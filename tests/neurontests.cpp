#include <gtest/gtest.h>
#include <vector>

#include "../src/Neuron.h"
#include "../src/InputNode.h"
#include "../src/Edge.h"
#include "../src/NNetUtil.h"

const double EPSILON = 0.0000001;

TEST(Neuron, single_input){
    Neuron n1 = Neuron(NNetUtil::unitStep);
    InputNode in1 = InputNode(-0.1);
    Edge e1 = Edge(1.0, &in1, &n1);

    std::vector<Edge*> nInputs = std::vector<Edge*>();
    nInputs.push_back(&e1);

    n1.setInputs(nInputs);
    n1.calcOutput();

    ASSERT_NEAR(n1.getOutput(), 0.0, EPSILON);
}

TEST(Neuron, single_sigmoid){
    Neuron n1 = Neuron(NNetUtil::sigmoid);
    InputNode in1 = InputNode(0.0);
    Edge e1 = Edge(1.0, &in1, &n1);

    std::vector<Edge*> nInputs = std::vector<Edge*>();
    nInputs.push_back(&e1);

    n1.setInputs(nInputs);
    n1.calcOutput();

    ASSERT_NEAR(n1.getOutput(), 0.5, EPSILON);
}

TEST(Neuron, weighted_sigmoid){
    Neuron n1 = Neuron(NNetUtil::sigmoid);
    InputNode in1 = InputNode(0.3);
    Edge e1 = Edge(5.0, &in1, &n1);

    std::vector<Edge*> nInputs = std::vector<Edge*>();
    nInputs.push_back(&e1);

    n1.setInputs(nInputs);
    n1.calcOutput();

    ASSERT_NEAR(n1.getOutput(),  0.81757447619, EPSILON);
}

TEST(Neuron, double_input1){
    Neuron n1 = Neuron(NNetUtil::unitStep);
    InputNode in1 = InputNode(-0.3);
    InputNode in2 = InputNode(1.0);
    Edge e1 = Edge(1.0, &in1, &n1);
    Edge e2 = Edge(1.0, &in2, &n1);

    std::vector<Edge*> nInputs = std::vector<Edge*>();
    nInputs.push_back(&e1);
    nInputs.push_back(&e2);

    n1.setInputs(nInputs);
    n1.calcOutput();

    ASSERT_NEAR(n1.getOutput(),  1.0, EPSILON);
}

TEST(Neuron, double_input2){
    Neuron n1 = Neuron(NNetUtil::unitStep);
    InputNode in1 = InputNode(-0.6);
    InputNode in2 = InputNode(1.0);
    Edge e1 = Edge(2.0, &in1, &n1);
    Edge e2 = Edge(1.0, &in2, &n1);

    std::vector<Edge*> nInputs = std::vector<Edge*>();
    nInputs.push_back(&e1);
    nInputs.push_back(&e2);

    n1.setInputs(nInputs);
    n1.calcOutput();

    ASSERT_NEAR(n1.getOutput(),  0.0, EPSILON);
}

TEST(Neuron, 5_inputs){
    Neuron n1 = Neuron(NNetUtil::sigmoid);
    InputNode in1 = InputNode(0.2);
    InputNode in2 = InputNode(1.5);
    InputNode in3 = InputNode(3.5);
    InputNode in4 = InputNode(-2.6);
    InputNode in5 = InputNode(1.6);
    Edge e1 = Edge(1.3, &in1, &n1);
    Edge e2 = Edge(-2.4, &in2, &n1);
    Edge e3 = Edge(3.1, &in3, &n1);
    Edge e4 = Edge(0.2, &in4, &n1);
    Edge e5 = Edge(1.0, &in5, &n1);

    std::vector<Edge*> nInputs = std::vector<Edge*>();
    nInputs.push_back(&e1);
    nInputs.push_back(&e2);
    nInputs.push_back(&e3);
    nInputs.push_back(&e4);
    nInputs.push_back(&e5);

    n1.setInputs(nInputs);
    n1.calcOutput();

    ASSERT_NEAR(n1.getOutput(),   0.99981407849, EPSILON);
}
