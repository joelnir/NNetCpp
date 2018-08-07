#include <vector>

#include "InputNode.h"
#include "Neuron.h"
#include "OutputNeuron.h"

/**
 * A fully connected Neural Net
 */
class ConnectedNet{
    private:
        std::vector<InputNode*> inputs;
        std::vector<std::vector<Neuron*> > hidden;
        std::vector<OutputNeuron*> outputs;

        // Constants for weight initialization
        constexpr static double WEIGHT_INIT_MIN = -1.0;
        constexpr static double WEIGHT_INIT_MAX = 1.0;
    public:
        /**
         * Create a new ConnectedNet with specified amount of input, hidden
         * and output nodes
         */
        ConnectedNet(int inputNodes, std::vector<int> hiddenLayers, int outputNodes);

        /**
         * Destructor for ConnectedNet, clears all memory allocated
         */
        ~ConnectedNet();

        /**
         * Present an input to the ConnectedNet and get the output
         */
        std::vector<double> getOutput(std::vector<double> inputValues);
};
