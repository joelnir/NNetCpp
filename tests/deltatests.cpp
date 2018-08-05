#include <gtest/gtest.h>
#include <vector>

#include "../src/Neuron.h"
#include "../src/OutputNeuron.h"
#include "../src/InputNode.h"
#include "../src/NNetUtil.h"
#include "../src/Edge.h"

const double EPSILON = 0.0000001;

TEST(Delta, output1){
    OutputNeuron o1 = OutputNeuron(NNetUtil::sigmoid);
    o1.setTarget(1.0);

    o1.calcOutput();
    ASSERT_NEAR(o1.getOutput(), 0.5, EPSILON);

    o1.calcDelta();

    ASSERT_NEAR(o1.getDelta(), 0.125, EPSILON);
}

TEST(Delta, output2){
    OutputNeuron o1 = OutputNeuron(NNetUtil::sigmoid);
    o1.setTarget(1.0);

    InputNode i1 = InputNode(1.0);
    InputNode i2 = InputNode(-1.0);

    Edge e1 = Edge(3.0, &i1, &o1);
    Edge e2 = Edge(1.0, &i2, &o1);

    std::vector<Edge*> inputs = std::vector<Edge*>();
    inputs.push_back(&e1);
    inputs.push_back(&e2);
    o1.setInputs(inputs);

    o1.calcOutput();
    ASSERT_NEAR(o1.getOutput(), 0.880797077977, EPSILON);

    o1.calcDelta();

    ASSERT_NEAR(o1.getDelta(), 0.012515542173676732, EPSILON);
}

TEST(Delta, neuron1){
    Neuron n1 = Neuron(NNetUtil::sigmoid);

    n1.calcOutput();
    ASSERT_NEAR(n1.getOutput(), 0.5, EPSILON);

    n1.calcDelta();
    ASSERT_NEAR(n1.getDelta(), 0, EPSILON);
}

TEST(Delta, small_net){
    // Setup nodes
    Neuron n1 = Neuron(NNetUtil::sigmoid);
    OutputNeuron o1 = OutputNeuron(NNetUtil::sigmoid);
    OutputNeuron o2 = OutputNeuron(NNetUtil::sigmoid);
    o1.setTarget(5.0);
    o2.setTarget(2.0);

    Edge e1 = Edge(2.0, &n1, &o1);
    Edge e2 = Edge(-3.0, &n1, &o2);

    // Outputs for Neuron
    std::vector<Edge*> outputs = std::vector<Edge*>();
    outputs.push_back(&e1);
    outputs.push_back(&e2);

    // Inputs for OutputNeurons
    std::vector<Edge*> inputs1 = std::vector<Edge*>();
    inputs1.push_back(&e1);

    std::vector<Edge*> inputs2 = std::vector<Edge*>();
    inputs2.push_back(&e2);

    n1.setOutputs(outputs);
    o1.setInputs(inputs1);
    o2.setInputs(inputs2);

    // Calulate output
    n1.calcOutput();
    o1.calcOutput();
    o2.calcOutput();

    ASSERT_NEAR(n1.getOutput(), 0.5, EPSILON);
    ASSERT_NEAR(o1.getOutput(), 0.73105857863000487925, EPSILON);
    ASSERT_NEAR(o2.getOutput(), 0.18242552380635635, EPSILON);

    // Calculate deltas
    o1.calcDelta();
    o2.calcDelta();
    n1.calcDelta();

    ASSERT_NEAR(o1.getDelta(), 0.8393248257501941, EPSILON);
    ASSERT_NEAR(o2.getDelta(), 0.2710847844978756, EPSILON);
    ASSERT_NEAR(n1.getDelta(), 0.21634882450169035, EPSILON);
}

TEST(Delta, weight_adjust1){
    InputNode i1 = InputNode(1.0);
    OutputNeuron o1 = OutputNeuron(NNetUtil::sigmoid);
    o1.setTarget(1.0);
    Edge e1 = Edge(1.0, &i1, &o1);

    std::vector<Edge*> inputs = std::vector<Edge*> ();
    inputs.push_back(&e1);

    o1.setInputs(inputs);

    o1.calcOutput();
    ASSERT_NEAR(o1.getOutput(), 0.7310585786300049, EPSILON);
    o1.calcDelta();
    ASSERT_NEAR(o1.getDelta(), 0.052877092784266715, EPSILON);

    e1.updateWeight(1.0);
    // Weight after this should be 1.052877092784266, check so this is used next time

    o1.calcOutput();
    ASSERT_NEAR(o1.getOutput(), 0.7413269971303528, EPSILON);
}

TEST(Delta, weight_adjust2){
    InputNode i1 = InputNode(1.5);
    OutputNeuron o1 = OutputNeuron(NNetUtil::sigmoid);
    o1.setTarget(-2.0);
    Edge e1 = Edge(0.3, &i1, &o1);

    std::vector<Edge*> inputs = std::vector<Edge*> ();
    inputs.push_back(&e1);

    o1.setInputs(inputs);

    o1.calcOutput();
    ASSERT_NEAR(o1.getOutput(), 0.610639233949222, EPSILON);
    o1.calcDelta();
    ASSERT_NEAR(o1.getDelta(), -0.6207028689669545, EPSILON);

    e1.updateWeight(0.8);
    // Weight after this should be -0.44484344276034543, check so this is used next time

    o1.calcOutput();
    ASSERT_NEAR(o1.getOutput(), 0.3391094865129555, EPSILON);
}
