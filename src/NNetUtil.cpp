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

