#include <iostream>

#include "NetTraining.h"
#include "NNetUtil.h"

NetTraining::NetTraining(ConnectedNet* net, std::vector<TrainingData> trainingData,
                std::vector<TrainingData> evalData, StopCondition* stopper,
                double learningRate, int trainingPerIteration):
    net(net), trainingData(trainingData), evalData(evalData),
    stopper(stopper), learningRate(learningRate), trainingPerIteration(trainingPerIteration) {}

void NetTraining::printInfo(){
    std::cout << std::endl;
    std::cout << "****** Iteration " << this->iteration << " ******" << std::endl;
    std::cout << "error measure " << error << std::endl;
    std::cout << "**************************" << std::endl;
    std::cout << std::endl;
}

void NetTraining::printInOut(const std::vector<double>& input,
                const std::vector<double>& output){
    std::cout << "input: ";
    for(int inputI = 0; inputI < input.size(); ++inputI){
        std::cout << input.at(inputI);

        // Add , for all except last input
        if(inputI != (input.size() - 1)){
            std::cout << ",";
        }
    }

    std::cout << " ouput: ";
    for(int outputI = 0; outputI < output.size(); ++outputI){
        std::cout << output.at(outputI);

        // Add , for all except last input
        if(outputI != (output.size() - 1)){
            std::cout << ",";
        }
    }

    std::cout << std::endl;
}

void NetTraining::run(){
    std::vector<double> targetDiff;

    double errorSum = 0;

    do{
        // Train
        for(int trainingIter = 0; trainingIter < this->trainingPerIteration;
                ++trainingIter){
            // Run through training data once
            for(int dataI = 0; dataI < this->trainingData.size(); ++dataI){
                this->net->train(this->trainingData.at(dataI), this->learningRate);
            }
        }

        // Evaluate performance
        errorSum = 0;
        for(int evalI = 0; evalI < this->evalData.size(); ++evalI){
            std::vector<double> output = this->net->getOutput(
                    evalData.at(evalI).getInput());

            NetTraining::printInOut(evalData.at(evalI).getInput(), output);
            errorSum += NNetUtil::squareError(output, evalData.at(evalI).getTarget());
        }

        // If there is no evalData use 0 as error
        if(this->evalData.empty()){
            this->error = 0;
        }
        else{
            this->error = errorSum / (double)this->evalData.size();
        }

        this->printInfo();

        this->iteration++;
    }while(!this->stopper->check(iteration, error));
}
