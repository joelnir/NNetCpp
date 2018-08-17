#include "IterationCondition.h"

IterationCondition::IterationCondition(int stopIteration):
    stopIteration(stopIteration) {}

bool IterationCondition::check(int iteration, double error){
    return (iteration >= this->stopIteration);
}
