#include <math.h>

#include "NNetUtil.h"

double NNetUtil::unitStep(double x){
    if(x < 0){
        return 0;
    }
    else{
        return 1.0;
    }
}

double NNetUtil::sigmoid(double x){
    return 1.0 / (1.0 + exp(-1.0 * x));
}

double NNetUtil::squareError(const std::vector<double>& v1, const std::vector<double>& v2){
    double squareSum = 0;

    for(int i = 0; i < v1.size(); ++i){
        squareSum += pow((v2.at(i) - v1.at(i)), 2);
    }

    return (0.5) * squareSum;
}
