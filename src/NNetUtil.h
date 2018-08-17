#ifndef NNET_UTIL_H
#define NNET_UTIL_H

#include <vector>

namespace NNetUtil{
    /**
     * Unit step function
     *
     * y(x) = 0 if x < 0
     * y(x) = 1 if x >= 0
     */
    double unitStep(double x);

    /**
     * Sigmoid function
     *
     * y(x) = 1 / (1 + exp(-x))
     */
    double sigmoid(double x);

    /**
     * Calculate the square error of two vectors
     * Scaled with (1/2) to normalize derivative
     *
     * E(v1, v2) = (1/2) |v2 - v1|^2
     */
    double squareError(const std::vector<double>& v1, const std::vector<double>& v2);
}

#endif // NNET_UTIL_H
