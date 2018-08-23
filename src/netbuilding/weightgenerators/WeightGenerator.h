#ifndef WEIGHT_GENERATOR_H
#define WEIGHT_GENERATOR_H

class WeightGenerator{
    public:
        /**
         * Get a new weight
         */
        virtual double getWeight() = 0;
};

#endif // WEIGHT_GENERATOR_H
