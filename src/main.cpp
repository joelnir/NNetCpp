#include <iostream>
#include <vector>

#include "Neuron.h"
#include "InputNode.h"
#include "Edge.h"

double step(double x){
    if(x < 0){
        return 0;
    }
    else{
        return 1;
    }
}

int main(){
    Neuron* n1 = new Neuron(step);
    InputNode* in1 = new InputNode(0.0);
    Edge* e1 = new Edge(1.0, in1, n1);

    std::vector<Edge*> nInputs = std::vector<Edge*>();
    nInputs.push_back(e1);

    n1->setInputs(nInputs);

    std::cout << n1->getOutput() << std::endl;
}
