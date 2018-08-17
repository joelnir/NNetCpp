#include <iostream>
#include <vector>

#include "ConnectedNet.h"
#include "NetTraining.h"
#include "IterationCondition.h"

int main(){
    std::vector<int> hiddenLayers = std::vector<int>(1, 2);
    ConnectedNet net = ConnectedNet(2, hiddenLayers, 2);

    IterationCondition stopCond = IterationCondition(10);

    std::vector<TrainingData> eval = std::vector<TrainingData>();
    eval.push_back(TrainingData(std::vector<double>(2, 1.0), std::vector<double>(2, 1.0)));

    NetTraining training = NetTraining(&net, eval,
            eval, &stopCond, 1.0);
    training.run();
}
