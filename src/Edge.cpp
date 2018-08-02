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

}

double Edge::getOutput(){
    // Should probably assert here that input isn't nullptr
    return this->input->getOutput() * this->weight;
}
