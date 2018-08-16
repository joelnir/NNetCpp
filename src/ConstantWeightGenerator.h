#ifndef CONSTANT_WEIGHT_GENERATOR_H
#define CONSTANT_WEIGHT_GENERATOR_H

#include "WeightGenerator.h"

class ConstantWeightGenerator: public WeightGenerator{
    private:
        double weight;

    public:
        /**
         * Create a new ConstantWeightGenerator that always outputs weight
         */
        ConstantWeightGenerator(double weight);

        /**
         * Get the constant weight
         */
        double getWeight();
};

#endif //  CONSTANT_WEIGHT_GENERATOR_H
