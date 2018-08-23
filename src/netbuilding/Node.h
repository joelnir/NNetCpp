#ifndef NODE_H
#define NODE_H

/**
 * Node of network
 */
class Node {
    public:
        /**
         * Get the output of the node
         *
         * @return the node's output
         */
        virtual double getOutput() = 0;
};

#endif // NODE_H
