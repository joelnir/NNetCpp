#ifndef WEIGHT_GENERATOR_H
#define WEIGHT_GENERATOR_H

/**
 * Generator of default weights for edges
 */
class WeightGenerator{
    public:
        /**
         * Get a new weight from the generator
         *
         * @return the new weight
         */
        virtual double getWeight() = 0;
};

#endif // WEIGHT_GENERATOR_H
