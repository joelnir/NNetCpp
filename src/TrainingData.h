#ifndef TRAINING_DATA_H
#define TRAINING_DATA_H

#include <vector>

class TrainingData{
    private:
        std::vector<double> input;
        std::vector<double> target;

    public:
        /**
         * Create a new training data input-target pair
         */
        TrainingData(std::vector<double> input, std::vector<double> target);

        /**
         * Get the input vector of the training data
         */
        std::vector<double> getInput();

        /**
         * Get the known target vector of the training data
         */
        std::vector<double> getTarget();
};

#endif // TRAINING_DATA_H
