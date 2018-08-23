#ifndef NNET_UTIL_H
#define NNET_UTIL_H

#include <vector>

/**
 * Utility functions for neural networks
 */
namespace NNetUtil{
    /**
     * Unit step function
     *
     * y(x) = 0 if x < 0\n
     * y(x) = 1 if x >= 0
     *
     * @param x input to step function
     *
     * @return step function of input
     */
    double unitStep(double x);

    /**
     * Sigmoid function
     *
     * y(x) = 1 / (1 + exp(-x))
     *
     * @param x input to sigmoid
     *
     * @return output of sigmoid
     */
    double sigmoid(double x);

    /**
     * Calculate the square error of two vectors
     * Scaled with (1/2) to normalize derivative
     *
     * E(v1, v2) = (1/2) |v2 - v1|^2
     *
     * @param v1 first vector
     * @param v2 second vector
     *
     * @return the square error of the two vectors
     */
    double squareError(const std::vector<double>& v1, const std::vector<double>& v2);
}

#endif // NNET_UTIL_H
