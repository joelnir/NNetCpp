#ifndef OUTPUT_NEURON_H
#define OUTPUT_NEURON_H

#include <functional>
#include <vector>

#include "Neuron.h"

class OutputNeuron: public Neuron{
    private:
        double targetValue = 0;
    public:
        /**
         * Create a new OutputNeuron using the given activation function
         */
        OutputNeuron(std::function<double(double)> activationFunc);

        /**
         * Create a new OutputNeuron using the given
         * activation function with given inputs
         */
        OutputNeuron(std::function<double(double)> activationFunc, std::vector<Edge*> inputs);

        /**
         * Create a new OutputNeuron using the given
         * activation function and target value
         */
        OutputNeuron(std::function<double(double)> activationFunc, double targetValue);

        /**
         * Calculate delta for output Neuron according to the GDR
         */
        double calcDelta();

        /**
         * Set the target value of the OutputNeuron
         */
        void setTarget(double targetValue);

        /**
         * Get the difference between actual output and target
         */
        double getDifference();
};

#endif // OUTPUT_NEURON_H
