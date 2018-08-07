#include "RandomWeightGenerator.h"

RandomWeightGenerator::RandomWeightGenerator(double weightMin, double weightMax){
    this-> dist = std::uniform_real_distribution<double>(weightMin, weightMax);
}

double RandomWeightGenerator::getWeight(){
    return this->dist(this->engine);
}
