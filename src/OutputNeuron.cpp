#include "OutputNeuron.h"

OutputNeuron::OutputNeuron(std::function<double(double)> activationFunc):
    Neuron(activationFunc){}

OutputNeuron::OutputNeuron(std::function<double(double)> activationFunc,
    std::vector<Edge*> inputs): Neuron(activationFunc){

    this->setInputs(inputs);
}

OutputNeuron::OutputNeuron(std::function<double(double)> activationFunc,
    double targetValue): Neuron(activationFunc), targetValue(targetValue){}

double OutputNeuron::calcDelta(){
    double sigDelta = this->sigmoidDelta();
    double targetDiff = (this->targetValue - this->getOutput());

    // Store delta
    this->delta = targetDiff * sigDelta;
}

void OutputNeuron::setTarget(double targetValue){
    this->targetValue = targetValue;
}
