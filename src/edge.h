#ifndef EDGE_H
#define EDGE_H

#include "node.h"

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
        double weight;
        Node* input;
        Node* output;
    public:
        /**
         * Create a new Edge between 2 Nodes. Start with given weight
         */
        Edge(double startWeight, Node* input = nullptr, Node* output = nullptr);

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
};

#endif // EDGE_H
