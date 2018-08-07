#include "ConnectedNet.h"
#include "RandomWeightGenerator.h"
#include "NNetUtil.h"

ConnectedNet::ConnectedNet(int inputNodes,
    std::vector<int> hiddenLayers, int outputNodes){

    // Always use sigmoid function for activation
    auto activationFunc = NNetUtil::sigmoid;

    // Create input nodes (values currently irrelevant)
    this->inputs = std::vector<InputNode*>();
    for(int inputI = 0; inputI < inputNodes; ++inputI){
        this->inputs.push_back(new InputNode());
    }

    // Create hidden layers
    this->hidden = std::vector<std::vector<Neuron*>>();
    // Initialize layers with right amount of vector<Node*>:s
    this->hidden.resize(hiddenLayers.size());

    for(int layerI = 0; layerI < hiddenLayers.size(); ++layerI){
        for(int neuronI = 0; neuronI < hiddenLayers.at(layerI); ++neuronI){
            this->hidden.at(layerI).push_back(new Neuron(activationFunc));
        }
    }

    // Create output Neurons
    this->outputs = std::vector<OutputNeuron*>();
    for(int outputI = 0; outputI < outputNodes; ++outputI){
        this->outputs.push_back(new OutputNeuron(activationFunc));
    }

    // Set up edges between layers
    // Initialize random generator
    RandomWeightGenerator weightGen = RandomWeightGenerator(
        ConnectedNet::WEIGHT_INIT_MIN,
        ConnectedNet::WEIGHT_INIT_MAX);

    // Variables needed when creating weights
    std::vector<Edge*> inputs = std::vector<Edge*>();
    Edge* newEdge;

    if(hiddenLayers.size() == 0){
        // Special case: no hidden layer, connect inputs directly to outputs


        for(int outputI = 0; outputI < outputNodes; ++outputI){
            for(int inputI = 0; inputI < inputNodes; ++inputI){
                newEdge = new Edge(weightGen.getWeight(),
                    this->inputs.at(inputI),
                    this->outputs.at(outputI));

                inputs.push_back(newEdge);
            }

            // Set all created edges as inputs for OutputNode at index outputI
            this->outputs.at(outputI)->setInputs(inputs);
            inputs.clear();
        }
    }
    else{
        // Normal case, some hidden layer
        // Need to connect layers input->hidden, multiple hidden, hidden -> output

        // input -> first hidden layer
        for(int outputI = 0; outputI < hiddenLayers.at(0); ++outputI){
            for(int inputI = 0; inputI < inputNodes; ++inputI){
                newEdge = new Edge(weightGen.getWeight(),
                    this->inputs.at(inputI),
                    this->hidden.at(0).at(outputI));

                inputs.push_back(newEdge);
            }

            // Set all created edges as inputs
            // for Neuron in hidden layer 0 at index outputI
            this->hidden.at(0).at(outputI)->setInputs(inputs);
            inputs.clear();
        }

        // hidden layer -> hidden layer
        std::vector<std::vector<Edge*>> outputs = std::vector<std::vector<Edge*>>();

        // Need to start at index 1, layerI is index of layer with output of edges
        for(int layerI = 1; layerI < hiddenLayers.size(); ++layerI){
            // Adjust outputs vector for storing outputs for this layer
            outputs.resize(hiddenLayers.at(layerI - 1));

            for(int outputI = 0; outputI < hiddenLayers.at(layerI); ++outputI){
                for(int inputI = 0; inputI < hiddenLayers.at(layerI - 1); ++inputI){
                    newEdge = new Edge(weightGen.getWeight(),
                        this->hidden.at(layerI - 1).at(inputI),
                        this->hidden.at(layerI).at(outputI));

                    inputs.push_back(newEdge);
                    outputs.at(outputI).push_back(newEdge);
                }

                // Set all created edges as inputs
                // for Neuron in hidden layer 0 at index outputI
                this->hidden.at(layerI).at(outputI)->setInputs(inputs);
                inputs.clear();
            }

            // set outputs of layer layerI-1
            for(int inputI = 0; inputI < hiddenLayers.at(layerI - 1); ++inputI){
                this->hidden.at(layerI - 1).at(inputI)->setOutputs(outputs.at(inputI));
            }

            outputs.clear();
        }

        // last hidden layer -> outputs
        int lastHiddenI = hiddenLayers.size() - 1; // Index of last hidden layer
        outputs.resize(hiddenLayers.at(lastHiddenI));

        for(int outputI = 0; outputI < outputNodes; ++outputI){
            for(int inputI = 0; inputI < hiddenLayers.at(lastHiddenI); ++inputI){
                newEdge = new Edge(weightGen.getWeight(),
                    this->hidden.at(lastHiddenI).at(outputI),
                    this->outputs.at(outputI));

                inputs.push_back(newEdge);
                outputs.at(inputI).push_back(newEdge);
            }

            // Set all created edges as inputs
            // for OutputNeuron at index outputI
            this->outputs.at(outputI)->setInputs(inputs);
            inputs.clear();
        }
        // Set the outputs of last hidden layer
        for(int inputI = 0; inputI < hiddenLayers.at(lastHiddenI); ++inputI){
            this->hidden.at(lastHiddenI).at(inputI)->setOutputs(outputs.at(inputI));
        }
    }
}

 ConnectedNet::~ConnectedNet(){
    // TODO Clear memory for all Nodes and Neurons
}

std::vector<double> getOutput(std::vector<double> inputValues){

}
