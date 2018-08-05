#include "Neuron.h"

Neuron::Neuron(std::function<double(double)> activationFunc,
    std::vector<Edge*> inputs, std::vector<Edge*> outputs):
    activationFunc(activationFunc),
    inputs(inputs), outputs(outputs){}

Neuron::Neuron(std::function<double(double)> activationFunc):
    activationFunc(activationFunc){}

double Neuron::sigmoidDelta(){
    double output = this->getOutput();

    return output * (1 - output);
}

void Neuron::setInputs(std::vector<Edge*> inputs){
    this->inputs = inputs;
}

void Neuron::setOutputs(std::vector<Edge*> outputs){
    this->outputs = outputs;
}

void Neuron::calcOutput(){
    double inputSum = 0;

    for(Edge* input : inputs){
        inputSum += input->getWeightedOutput();
    }

    // Store output from the Neuron
    this->output = this->activationFunc(inputSum);
}

void Neuron::calcDelta(){
    double deltaSum = 0;

    for(Edge* output : outputs){
        deltaSum += output->getWeightedDelta();
    }

    // Store delta value
    this->delta = this->sigmoidDelta() * deltaSum;
}

double Neuron::getOutput(){
    return this->output;
}

double Neuron::getDelta(){
    return this->delta;
}
