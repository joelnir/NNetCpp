#ifndef WEIGHT_GENERATOR_H
#define WEIGHT_GENERATOR_H

class WeightGenerator{
    private:
    public:
        /**
         * Get a new weight
         */
        virtual double getWeight() = 0;
};

#endif // WEIGHT_GENERATOR_H
