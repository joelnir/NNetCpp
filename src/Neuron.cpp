#include "Neuron.h"

Neuron::Neuron(std::function<double(double)> activationFunc,
    std::vector<Edge*> inputs, std::vector<Edge*> outputs):
    activationFunc(activationFunc),
    inputs(inputs), outputs(outputs){}

Neuron::Neuron(std::function<double(double)> activationFunc):
    activationFunc(activationFunc){}

void Neuron::setInputs(std::vector<Edge*> inputs){
    this->inputs = inputs;
}

void Neuron::setOutputs(std::vector<Edge*> outputs){
    this->outputs = outputs;
}

double Neuron::getOutput(){
    double inputSum = 0;

    for(Edge* input : inputs){
        inputSum += input->getOutput();
    }

    return this->activationFunc(inputSum);
}

double Neuron::getDelta(){

}
