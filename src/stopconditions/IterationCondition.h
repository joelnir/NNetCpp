#ifndef ITERATION_CONDITION_H
#define ITERATION_CONDITION_H

#include "StopCondition.h"

/**
 * Condition for stopping Neural Network training after
 * a fixed amount of training iterations
 */
class IterationCondition: public StopCondition {
    private:
        int stopIteration = 0;
    public:
        /**
         * Create a new IterationCondition that will allow
         * given amount of iterations
         *
         * @param allowedIterations amount of iterations to allow
         */
        IterationCondition(int allowedIterations);

        /**
         * Control if the last iteration has been met\n
         * Inherits:\n
         * @copydoc StopCondition::check
         */
        bool check(int iteration, double error);
};

#endif // ITERATION_CONDITION_H
