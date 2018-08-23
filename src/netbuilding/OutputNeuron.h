#ifndef OUTPUT_NEURON_H
#define OUTPUT_NEURON_H

#include <functional>
#include <vector>

#include "Neuron.h"

/**
 * Neuron at end of Neural Network outputting the nets output
 */
class OutputNeuron: public Neuron{
    private:
        double targetValue = 0;
    public:
        /**
         * Create a new OutputNeuron using the given activation function
         *
         * @param activationFunc function to use for neuron activation
         */
        OutputNeuron(std::function<double(double)> activationFunc);

        /**
         * Create a new OutputNeuron using the given
         * activation function with given inputs
         *
         * @param activationFunc function to use for neuron activation
         * @param inputs vector of pointers to incoming edges
         */
        OutputNeuron(std::function<double(double)> activationFunc,
                std::vector<Edge*> inputs);

        /**
         * Create a new OutputNeuron using the given
         * activation function and target value
         *
         * @param activationFunc function to use for neuron activation
         * @param targetValue target output value of the neuron
         */
        OutputNeuron(std::function<double(double)> activationFunc, double targetValue);

        /**
         * Calculate delta for output Neuron according to the GDR\n
         * Inherits:\n
         * @copydoc Neuron::calcDelta
         */
        void calcDelta();

        /**
         * Set the target value of the OutputNeuron
         *
         * @param targetValue value to target as output
         */
        void setTarget(double targetValue);

        /**
         * Get the difference between actual output and target
         *
         * @return the difference for the Neurons current values
         */
        double getDifference();
};

#endif // OUTPUT_NEURON_H
