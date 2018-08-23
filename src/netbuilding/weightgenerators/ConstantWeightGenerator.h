#ifndef CONSTANT_WEIGHT_GENERATOR_H
#define CONSTANT_WEIGHT_GENERATOR_H

#include "WeightGenerator.h"

/**
 * WeightGenerator that always outputs a constant weight
 */
class ConstantWeightGenerator: public WeightGenerator{
    private:
        double weight;

    public:
        /**
         * Create a new ConstantWeightGenerator that always outputs weight
         *
         * @param weight the constant weight to output
         */
        ConstantWeightGenerator(double weight);

        /**
         * Get the constant weight\n
         * Inherits:\n
         * @copydoc WeightGenerator::getWeight
         */
        double getWeight();
};

#endif //  CONSTANT_WEIGHT_GENERATOR_H
