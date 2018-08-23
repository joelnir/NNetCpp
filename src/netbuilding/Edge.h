#ifndef EDGE_H
#define EDGE_H

#include "Node.h"
#include "Neuron.h"

//Forward declararions
class Neuron;

/**
 * Edge between two nodes with weight W
 * @code
 *  ____                          _____
 * /    \          ---           /     \
 * | in |  >------| W |--------> | out |
 * \____/          ---           \_____/
 * @endcode
 */
class Edge {
    private:
        double weight = 0;
        Node* input = nullptr;
        Neuron* output = nullptr;
    public:
        /**
         * Create a new Edge between 2 Nodes. Start with given weight
         *
         * @param startWeight initial weight of the edge
         * @param input start node of the edge
         * @param output end node of the edge
         */
        Edge(double startWeight, Node* input = nullptr, Neuron* output = nullptr);

        /**
         * Set the Node this Edge starts at
         *
         * @param input node to set for input of edge
         */
        void setInput(Node* input);

        /**
         * Set the Neuron this Edge ends at
         * Note: must be Neuron (not just Node)
         * to allow for retrieving delta for training
         *
         * @param output node to set for output of edge, must be a neuron
         * not just a node to allow for retrieving delta for training
         */
        void setOutput(Neuron* output);

        /**
         * Update the weight for the edge based on the backpropagation algorithm
         * @param learningRate distance to update weight
         */
        void updateWeight(double learningRate);

        /**
         * Get the output from the edge
         *
         * @return the input weighted with the current edge weight
         */
        double getWeightedOutput();

        /**
         * Get the delta from the output Neuron weighted for back propagation
         *
         * @return the delta of output node weighted with the current edge weight
         */
        double getWeightedDelta();
};

#endif // EDGE_H
