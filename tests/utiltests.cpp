#include <gtest/gtest.h>
#include "../src/NNetUtil.h"

const double EPSILON = 0.0000001;

TEST(Util, step1){
    ASSERT_EQ(NNetUtil::unitStep(-1), 0);
}

TEST(Util, step2){
    ASSERT_EQ(NNetUtil::unitStep(0), 1);
}

TEST(Util, step3){
    ASSERT_EQ(NNetUtil::unitStep(1), 1);
}

TEST(Util, sigmoid1){
    ASSERT_NEAR(NNetUtil::sigmoid(0), 0.5, EPSILON);
}

TEST(Util, sigmoid2){
    ASSERT_NEAR(NNetUtil::sigmoid(-1), 0.2689414213699951207488407581, EPSILON);
}

TEST(Util, sigmoid3){
    ASSERT_NEAR(NNetUtil::sigmoid(5), 0.993307149075715144440638, EPSILON);
}

TEST(Util, square_error1){
    std::vector<double> v1 = std::vector<double>();
    std::vector<double> v2 = std::vector<double>();
    ASSERT_NEAR(NNetUtil::squareError(v1, v2), 0, EPSILON);
}

TEST(Util, square_error2){
    std::vector<double> v1 = std::vector<double>(3, 1.0);
    std::vector<double> v2 = std::vector<double>(3, -1.0);
    ASSERT_NEAR(NNetUtil::squareError(v1, v2), 6.0, EPSILON);
}

TEST(Util, square_error3){
    std::vector<double> v1 = std::vector<double>();
    v1.push_back(1.0);
    v1.push_back(-2.0);
    v1.push_back(4.0);
    v1.push_back(8.5);

    std::vector<double> v2 = std::vector<double>();
    v2.push_back(2.3);
    v2.push_back(-3.0);
    v2.push_back(5.0);
    v2.push_back(-1.0);


    ASSERT_NEAR(NNetUtil::squareError(v1, v2), 46.97, EPSILON);
}
