#ifndef NET_TRAINING_H
#define NET_TRAINING_H

#include <vector>

#include "ConnectedNet.h"
#include "StopCondition.h"

class NetTraining{
    private:
        ConnectedNet* net = nullptr;
        std::vector<TrainingData> trainingData;
        std::vector<TrainingData> evalData;
        StopCondition* stopper = nullptr;
        double learningRate = 1.0;
        int trainingPerIteration = 1;

        double error = 0;
        int iteration = 0;

        /**
         * Print information about the current iteration and error
         */
        void printInfo();

        /**
         * Print information about a net input and resulting output
         */
        static void printInOut(const std::vector<double>& input,
                const std::vector<double>& output);

    public:
        /**
         * Create a new NetTraining session for the given net with
         * the given data and stop condition
         * trainingPerIteration is how many times the training data
         * should be iterated through between every performace evaluation
         */
        NetTraining(ConnectedNet* net, std::vector<TrainingData> trainingData,
                std::vector<TrainingData> evalData, StopCondition* stopper,
                double learnigRate, int trainingPerIteration = 1);

        /**
         * Start the training and run until the stop condition is met
         */
        void run();
};

#endif // NET_TRAINING_H
