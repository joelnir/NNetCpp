#include <gtest/gtest.h>
#include <vector>

#include "../src/ConnectedNet.h"
#include "../src/TrainingData.h"
#include "../src/ConstantWeightGenerator.h"

const double EPSILON = 0.0000001;

TEST(ConnectedNet, output1){
    std::vector<int> hidden = std::vector<int>();
    ConstantWeightGenerator constGen = ConstantWeightGenerator(1.0);

    ConnectedNet cn = ConnectedNet(1, hidden, 1, &constGen);

    std::vector<double> input = std::vector<double>();
    input.push_back(1.0);

    std::vector<double> output = cn.getOutput(input);

    ASSERT_NEAR(output.at(0), 0.8807970779, EPSILON);
}

TEST(ConnectedNet, output2){
    std::vector<int> hidden = std::vector<int>();
    hidden.push_back(1);
    hidden.push_back(1);
    ConstantWeightGenerator constGen = ConstantWeightGenerator(1.0);

    ConnectedNet cn = ConnectedNet(1, hidden, 1, &constGen);

    std::vector<double> input = std::vector<double>();
    input.push_back(1.0);

    std::vector<double> output = cn.getOutput(input);

    ASSERT_NEAR(output.at(0), 0.86619223149328, EPSILON);
}

TEST(ConnectedNet, output3){
    std::vector<int> hidden = std::vector<int>();
    ConstantWeightGenerator constGen = ConstantWeightGenerator(1.0);

    ConnectedNet cn = ConnectedNet(1, hidden, 1, &constGen);

    std::vector<double> input = std::vector<double>();
    input.push_back(1.0);

    std::vector<double> output = cn.getOutput(input);
    ASSERT_NEAR(output.at(0), 0.8807970779, EPSILON);

    input.at(0) = 2.0;
    output = cn.getOutput(input);
    ASSERT_NEAR(output.at(0), 0.952574126822, EPSILON);

    input.at(0) = -1.0;
    output = cn.getOutput(input);
    ASSERT_NEAR(output.at(0), 0.5, EPSILON);
}

TEST(ConnectedNet, output_multilevel){
    std::vector<int> hidden = std::vector<int>();
    ConstantWeightGenerator constGen = ConstantWeightGenerator(1.0);
    hidden.push_back(3);

    ConnectedNet cn = ConnectedNet(3, hidden, 2, &constGen);

    std::vector<double> input = std::vector<double>();
    input.push_back(1.0);
    input.push_back(-2.3);
    input.push_back(5.4);

    std::vector<double> output = cn.getOutput(input);
    ASSERT_NEAR(output.at(0), 0.9816898629956, EPSILON);
    ASSERT_NEAR(output.at(1), 0.9816898629956, EPSILON);
}

TEST(ConnectedNet, training_single){
    std::vector<int> hidden = std::vector<int>();
    ConstantWeightGenerator constGen = ConstantWeightGenerator(1.0);

    ConnectedNet cn = ConnectedNet(1, hidden, 1, &constGen);

    // vector of just 1
    std::vector<double> ones = std::vector<double>();
    ones.push_back(1.0);

    TrainingData tData = TrainingData(ones, ones);
    cn.train(tData, 1.0);

    ASSERT_NEAR(cn.getDifference().at(0), 0.1192029221, EPSILON);

    std::vector<double> output = cn.getOutput(ones);
    ASSERT_NEAR(output.at(0), 0.8834002327004059, EPSILON);
}

TEST(ConnectedNet, training_small){
    std::vector<int> hidden = std::vector<int>();
    ConstantWeightGenerator constGen = ConstantWeightGenerator(1.0);
    hidden.push_back(3);

    ConnectedNet cn = ConnectedNet(3, hidden, 2, &constGen);

    std::vector<double> input = std::vector<double>();
    input.push_back(1.0);
    input.push_back(-2.3);
    input.push_back(5.4);
    std::vector<double> target = std::vector<double>();
    target.push_back(1.0);
    target.push_back(0.0);

    TrainingData tData = TrainingData(input, target);
    cn.train(tData, 1.5);

    std::vector<double> diff = cn.getDifference();
    ASSERT_NEAR(diff.at(0), 0.0183101370044, EPSILON);
    ASSERT_NEAR(diff.at(1), -0.9816898629956, EPSILON);

    // Try new inputs
    input.clear();
    input.push_back(-1.5);
    input.push_back(3.1);
    input.push_back(-0.2);

    std::vector<double> output = cn.getOutput(input);
    ASSERT_NEAR(output.at(0), 0.9770817534644519, EPSILON);
    ASSERT_NEAR(output.at(1), 0.9747155551791657, EPSILON);
}
