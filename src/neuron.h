#ifndef NEURON_H
#define NEURON_H

#include <functional>
#include <vector>
#include "node.h"
#include "edge.h"

class Neuron: public Node {
    private:
        std::vector<double> weights;
        std::vector<Edge*> inputs;
        std::vector<Edge*> outputs;
    public:
        /**
         * Create a new Neuron with the given in- and outputs
         */
        Neuron(std::function<double(double)> activationFunc,
                std::vector<Node*> inputs,
                std::vector<Node*> outputs);

        /**
         * Create a new Neuron
         */
        Neuron(std::function<double(double)> activationFunc);

        /**
         * Set the edges in to this Neuron
         */
        void setInputs(std::vector<Edge*>);

        /**
         * Set the edges out from this Neuron
         */
        void setOutputs(std::vector<Edge*>);

        /**
         * Get the output of this Neuron
         * TODO deisgn way to avoid calculating this multiple times
         */
        double getOutput();

        /**
         * Calculate delta for backpropagation
         * TODO deisgn way to avoid calculating this multiple times
         */
        double getDelta();
};

#endif // NEURON_H
