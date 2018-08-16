#include <gtest/gtest.h>
#include <vector>

#include "../src/ConnectedNet.h"
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
