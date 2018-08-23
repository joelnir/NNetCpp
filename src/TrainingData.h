#ifndef TRAINING_DATA_H
#define TRAINING_DATA_H

#include <vector>

/**
 * Data to be used for training a neural net.
 * Consist of a pair of input data and wanted output
 */
class TrainingData{
    private:
        std::vector<double> input;
        std::vector<double> target;

    public:
        /**
         * Create a new training data input-target pair
         * @param input the input to the neural net
         * @param target the wanted output from the net
         */
        TrainingData(std::vector<double> input, std::vector<double> target);

        /**
         * Get the input vector of the training data
         * @return the input vector
         */
        std::vector<double> getInput();

        /**
         * Get the known target vector of the training data
         * @return the (target) output vector
         */
        std::vector<double> getTarget();
};

#endif // TRAINING_DATA_H
