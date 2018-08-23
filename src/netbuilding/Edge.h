#ifndef EDGE_H
#define EDGE_H

#include "Node.h"
#include "Neuron.h"

//Forward declararions
class Neuron;

/**
 * Edge between two nodes with weight W
 *   ____                          _____
 *  /    \          ---           /     \
 *  | in |  >------| W |--------> | out |
 *  \____/          ---           \_____/
 */
class Edge {
    private:
        double weight = 0;
        Node* input = nullptr;
        Neuron* output = nullptr;
    public:
        /**
         * Create a new Edge between 2 Nodes. Start with given weight
         */
        Edge(double startWeight, Node* input = nullptr, Neuron* output = nullptr);

        /**
         * Set the Node this Edge starts at
         */
        void setInput(Node* input);

        /**
         * Set the Neuron this Edge ends at
         * Note: must be Neuron (not just Node)
         * to allow for retrieving delta for training
         */
        void setOutput(Neuron* output);

        /**
         * Update the weight for the edge based on the backpropagation algorithm
         */
        void updateWeight(double learningRate);

        /**
         * Get the output from the edge, that is
         * the input weighted with the current weight
         */
        double getWeightedOutput();

        /**
         * Get the delta from the output Neuron weighted for back propagation
         */
        double getWeightedDelta();
};

#endif // EDGE_H
