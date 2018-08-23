#include "ConstantWeightGenerator.h"

ConstantWeightGenerator::ConstantWeightGenerator(double weight): weight(weight) {}

double ConstantWeightGenerator::getWeight(){
    return this->weight;
}
