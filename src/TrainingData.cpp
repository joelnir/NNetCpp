#include "TrainingData.h"

TrainingData:: TrainingData(std::vector<double> input, std::vector<double> target):
    input(input), target(target) {}

std::vector<double> TrainingData::getInput(){
    return this->input;
}

std::vector<double> TrainingData::getTarget(){
    return this->target;
}
