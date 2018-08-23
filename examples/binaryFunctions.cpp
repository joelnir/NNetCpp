#include <vector>

#include "binaryFunctions.h"
#include "NetTraining.h"
#include "ConnectedNet.h"
#include "NetTraining.h"
#include "IterationCondition.h"

void trainAnd(){
    std::vector<int> hiddenLayers = std::vector<int>();
    ConnectedNet net = ConnectedNet(2, hiddenLayers, 1);

    // Parameters
    // ********************
    int iterations = 100;
    double learningRate = 10.0;
    int trainingIter = 50;
    // ********************

    // dataset
    std::vector<TrainingData> andData = std::vector<TrainingData>();

    std::vector<double> input = std::vector<double>();
    std::vector<double> target = std::vector<double>();

    input.push_back(0);
    input.push_back(0);
    target.push_back(0);
    andData.push_back(TrainingData(input, target));
    input.clear();
    target.clear();

    input.push_back(0);
    input.push_back(1);
    target.push_back(0);
    andData.push_back(TrainingData(input, target));
    input.clear();
    target.clear();

    input.push_back(1);
    input.push_back(0);
    target.push_back(0);
    andData.push_back(TrainingData(input, target));
    input.clear();
    target.clear();

    input.push_back(1);
    input.push_back(1);
    target.push_back(1);
    andData.push_back(TrainingData(input, target));
    input.clear();
    target.clear();

    IterationCondition stopCond = IterationCondition(iterations);

    NetTraining training = NetTraining(&net, andData,
            andData, &stopCond, learningRate, trainingIter);

    training.run();
}

void trainOr(){
    std::vector<int> hiddenLayers = std::vector<int>();
    ConnectedNet net = ConnectedNet(2, hiddenLayers, 1);

    // Parameters
    // ********************
    int iterations = 100;
    double learningRate = 10.0;
    int trainingIter = 50;
    // ********************

    // dataset
    std::vector<TrainingData> orData = std::vector<TrainingData>();

    std::vector<double> input = std::vector<double>();
    std::vector<double> target = std::vector<double>();

    input.push_back(0);
    input.push_back(0);
    target.push_back(0);
    orData.push_back(TrainingData(input, target));
    input.clear();
    target.clear();

    input.push_back(0);
    input.push_back(1);
    target.push_back(1);
    orData.push_back(TrainingData(input, target));
    input.clear();
    target.clear();

    input.push_back(1);
    input.push_back(0);
    target.push_back(1);
    orData.push_back(TrainingData(input, target));
    input.clear();
    target.clear();

    input.push_back(1);
    input.push_back(1);
    target.push_back(1);
    orData.push_back(TrainingData(input, target));
    input.clear();
    target.clear();

    IterationCondition stopCond = IterationCondition(iterations);

    NetTraining training = NetTraining(&net, orData,
            orData, &stopCond, learningRate, trainingIter);

    training.run();
}

void trainXor(){
    std::vector<int> hiddenLayers = std::vector<int>();
    hiddenLayers.push_back(3);
    hiddenLayers.push_back(3);
    ConnectedNet net = ConnectedNet(2, hiddenLayers, 1);

    // Parameters
    // ********************
    int iterations = 100;
    double learningRate = 0.1;
    int trainingIter = 500;
    // ********************

    // dataset
    std::vector<TrainingData> orData = std::vector<TrainingData>();

    std::vector<double> input = std::vector<double>();
    std::vector<double> target = std::vector<double>();

    input.push_back(0);
    input.push_back(0);
    target.push_back(0);
    orData.push_back(TrainingData(input, target));
    input.clear();
    target.clear();

    input.push_back(0);
    input.push_back(1);
    target.push_back(1);
    orData.push_back(TrainingData(input, target));
    input.clear();
    target.clear();

    input.push_back(1);
    input.push_back(0);
    target.push_back(1);
    orData.push_back(TrainingData(input, target));
    input.clear();
    target.clear();

    input.push_back(1);
    input.push_back(1);
    target.push_back(0);
    orData.push_back(TrainingData(input, target));
    input.clear();
    target.clear();

    IterationCondition stopCond = IterationCondition(iterations);

    NetTraining training = NetTraining(&net, orData,
            orData, &stopCond, learningRate, trainingIter);

    training.run();
}
