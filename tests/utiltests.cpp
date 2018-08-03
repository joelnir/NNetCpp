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
