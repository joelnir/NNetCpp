#ifndef NEURON_H
#define NEURON_H

#include <functional>
#include <vector>
#include "Node.h"
#include "Edge.h"

// Forward declaration
class Edge;

class Neuron: public Node {
    private:
        std::vector<Edge*> inputs;
        std::vector<Edge*> outputs;

        double output = 0;

        std::function<double(double)> activationFunc;

    protected:
        double delta = 0;

        /**
         * Get the derivative of a sigmoid activation function for this node
         */
        double sigmoidDelta();

    public:
        /**
         * Create a new Neuron with the given in- and outputs
         */
        Neuron(std::function<double(double)> activationFunc,
                std::vector<Edge*> inputs,
                std::vector<Edge*> outputs);

        /**
         * Create a new Neuron
         */
        Neuron(std::function<double(double)> activationFunc);

        /**
         * Set the edges in to this Neuron
         */
        void setInputs(std::vector<Edge*> inputs);

        /**
         * Set the edges out from this Neuron
         */
        void setOutputs(std::vector<Edge*> outputs);

        /**
         * Calculate and store the output from this Neuron
         * All input Neurons should have their outputs updated before calculating this
         */
        void calcOutput();

        /**
         * Calculate and store the delta from this Neuron according to the GDR
         * All output Neurons should have their deltas updated before calculating this
         */
        void calcDelta();

        /**
         * Get the output of this Neuron
         */
        double getOutput();

        /**
         * Calculate delta for backpropagation
         */
        double getDelta();
};

#endif // NEURON_H
