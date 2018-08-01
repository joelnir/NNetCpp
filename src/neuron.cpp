#include "neuron.h"

Neuron::Neuron(std::function<double(double)> activationFunc,
                std::vector<Node*> inputs,
                std::vector<Node*> outputs){

}

Neuron::Neuron(std::function<double(double)> activationFunc){

}

void Neuron::setInputs(std::vector<Edge*>){

}

void Neuron::setOutputs(std::vector<Edge*>){

}

double Neuron::getOutput(){

}

double Neuron::getDelta(){

}
