#include <random>

class RandomWeightGenerator{
    private:
        std::default_random_engine engine;
        std::uniform_real_distribution<double> dist;

    public:
        /**
         * Create new RandomWeightGenerator for generating weights in the interval
         * [weightMin, weightMax)
         */
        RandomWeightGenerator(double weightMin, double weightMax);

        /**
         * Generate a new random weight
         */
        double getNewWeight();
};
