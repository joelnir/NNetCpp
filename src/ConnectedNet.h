#ifndef CONNECTED_NET_H
#define CONNECTED_NET_H

#include <vector>

#include "InputNode.h"
#include "Neuron.h"
#include "WeightGenerator.h"
#include "OutputNeuron.h"

/**
 * A fully connected Neural Net
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
         * Create a new ConnectedNet with specified amount of input, hidden
         * and output nodes using specified version of weight generation
         */
        ConnectedNet(int inputNodes, std::vector<int> hiddenLayers,
                int outputNodes, WeightGenerator* weightGen = nullptr);

        /**
         * Destructor for ConnectedNet, clears all memory allocated
         */
        ~ConnectedNet();

        /**
         * Present an input to the ConnectedNet and get the output
         */
        std::vector<double> getOutput(std::vector<double> inputValues);
};

#endif // CONNECTED_NET_H
