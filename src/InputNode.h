#ifndef INPUT_NODE_H
#define INPUT_NODE_H

#include "Node.h"

class InputNode: public Node {
    private:
        double value;

    public:
        /**
         * Create a new input node with the given value
         */
        InputNode(double value);

        /**
         * Get the output value of the input node
         */
        double getOutput();
};

#endif // INPUT_NODE_H
