#include "Edge.h"

Edge::Edge(double startWeight, Node* input, Neuron* output):
    weight(startWeight), input(input), output(output){}

void Edge::setInput(Node* input){
    this->input = input;
}

void Edge::setOutput(Neuron* output){
    this->output = output;
}

void Edge::updateWeight(double learningRate){
    // Output of previous node
    double inputValue = this->input->getOutput();

    // Delta of next node
    double followingDelta = this->output->getDelta();

    double weightDelta = learningRate * inputValue * followingDelta;
    this->weight += weightDelta;
}

double Edge::getWeightedOutput(){
    // Should probably assert here that input isn't nullptr
    return this->input->getOutput() * this->weight;
}

double Edge::getWeightedDelta(){
    return this->weight * this->output->getDelta();
}
