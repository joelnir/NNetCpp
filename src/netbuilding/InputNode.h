#ifndef INPUT_NODE_H
#define INPUT_NODE_H

#include "Node.h"

/**
 * A node to be used for input to networks. Its output value can be set.
 */
class InputNode: public Node {
    private:
        double value = 0;

    public:
        /**
         * Create a new input Node
         */
        InputNode();

        /**
         * Create a new input Node with the given value
         *
         * @param value the value for the InputNode to output
         */
        InputNode(double value);

        /**
         * Get the output value of the input node\n
         * inherits:\n
         * @copydoc Node::getOutput
         */
        double getOutput();

        /**
         * Set value of the input node
         *
         * @param value the value for the InputNode to output
         */
        void setValue(double value);
};

#endif // INPUT_NODE_H
