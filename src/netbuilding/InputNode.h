#ifndef INPUT_NODE_H
#define INPUT_NODE_H

#include "Node.h"

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
         */
        InputNode(double value);

        /**
         * Get the output value of the input node
         */
        double getOutput();

        /**
         * Set value of the input node
         */
        void setValue(double value);
};

#endif // INPUT_NODE_H
