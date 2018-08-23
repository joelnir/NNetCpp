#ifndef RANDOM_WEIGHT_GENERATOR_H
#define RANDOM_WEIGHT_GENERATOR_H

#include <random>

#include "WeightGenerator.h"

/**
 * Weight Generator for generating random weights
 */
class RandomWeightGenerator: public WeightGenerator {
    private:
        std::default_random_engine engine;
        std::uniform_real_distribution<double> dist;

        // Constant default limits
        constexpr static double DEFAULT_MIN = -1.0;
        constexpr static double DEFAULT_MAX = 1.0;
    public:
        /**
         * Create new RandomWeightGenerator for generating weights in the interval
         * [weightMin, weightMax)
         *
         * @param weightMin bottom limit of random interval
         * @param weightMax upper limit of random interval
         */
        RandomWeightGenerator(
                double weightMin = RandomWeightGenerator::DEFAULT_MIN,
                double weightMax = RandomWeightGenerator::DEFAULT_MAX);

        /**
         * Generate a new random weight\n
         * Inherits:\n
         * @copydoc WeightGenerator::getWeight
         */
        double getWeight();
};

#endif // RANDOM_WEIGHT_GENERATOR_H
