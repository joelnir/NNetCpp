#include "IterationCondition.h"

IterationCondition::IterationCondition(int stopIteration):
    stopIteration(stopIteration) {}

bool IterationCondition::check(int iteration, std::vector<double>& targetDifference){
    return (iteration >= this->stopIteration);
}
