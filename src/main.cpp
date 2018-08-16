#include <iostream>
#include <vector>

#include "Neuron.h"
#include "InputNode.h"
#include "OutputNeuron.h"
#include "Edge.h"
#include "NNetUtil.h"
#include "ConnectedNet.h"

int main(){
    std::vector<int> hiddenLayers = std::vector<int>(10, 100);
    ConnectedNet net = ConnectedNet(3, hiddenLayers, 3);
}
