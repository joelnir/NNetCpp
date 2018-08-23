#ifndef NET_TRAINING_H
#define NET_TRAINING_H

#include <vector>

#include "ConnectedNet.h"
#include "StopCondition.h"

/**
 * Training session of a neural net. Consists of
 * a collection of data, net and some stop condition for how long to keep training.
 */
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
         *
         * @param input input vector to print information about
         * @param output output of the net from the input
         */
        static void printInOut(const std::vector<double>& input,
                const std::vector<double>& output);

    public:
        /**
         * Create a new NetTraining session for the given net with
         * the given data and stop condition
         *
         * @param net the neural net to train
         * @param trainingData vector of all data pieces to use for training
         * @param evalData data pieces to use for evaluating performance of the net
         * @param stopper condition for stopping training
         * @param learningRate rate to adjust weights in backpropagation algorithm
         * @param trainingPerIteration times training data should be
         * iterated through before performace is evaluated
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
