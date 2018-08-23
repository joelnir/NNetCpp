#ifndef CONNECTED_NET_H
#define CONNECTED_NET_H

#include <vector>

#include "InputNode.h"
#include "Neuron.h"
#include "WeightGenerator.h"
#include "OutputNeuron.h"
#include "TrainingData.h"

/**
 * A fully connected Neural Network
 */
class ConnectedNet{
    private:
        std::vector<InputNode*> inputs;
        std::vector<std::vector<Neuron*> > hidden;
        std::vector<OutputNeuron*> outputs;
        InputNode* bias = nullptr;

        std::vector<std::vector<Edge*> > edges;

    public:
        /**
         * Create a new ConnectedNet of given dimensions.
         *
         * For example: For a 3x5x4x4x2 network one would put\n
         *      inputNodes - 3\n
         *      hiddenLayers - [5, 4, 4]\n
         *      outputNodes - 2\n
         *
         * @param inputNodes amount of inputs to the network
         * @param hiddenLayers vector of dimensions of hidden layers, number
         * at each index becomes amount of neurons in hidden layer at that index
         * @param outputNodes amount of outputs from the network
         * @param weighGen generator to use for initializing weights in the network,
         * if left a nullptr it is replaced with a default random generator
         */
        ConnectedNet(int inputNodes, std::vector<int> hiddenLayers,
                int outputNodes, WeightGenerator* weightGen = nullptr);

        /**
         * Destructor for ConnectedNet, clears all memory allocated
         */
        ~ConnectedNet();

        /**
         * Present an input to the ConnectedNet and get the output
         *
         * @param inputValues input vector to the net
         *
         * @return the output vector of the net
         */
        std::vector<double> getOutput(std::vector<double> inputValues);

        /**
         * Train the net on one input - target vector pair with speed learningrate
         * returns the error
         *
         * @param tData a piece of training data to use for training the net
         * @param learningRate rate to adjust weights in training
         */
        void train(TrainingData& tData, double learningrate);

        /**
         * Get a vector of difference between target and output
         *
         * @return the difference vector
         */
        std::vector<double> getDifference();
};

#endif // CONNECTED_NET_H
