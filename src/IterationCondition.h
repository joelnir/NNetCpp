#ifndef ITERATION_CONDITION_H
#define ITERATION_CONDITION_H

#include "StopCondition.h"

class IterationCondition: public StopCondition {
    private:
        int stopIteration = 0;
    public:
        /**
         * Create a new IterationCondition that will allow
         * given amount of iterations
         */
        IterationCondition(int allowedIterations);

        /**
         * Control if the last iteration has been met
         */
        bool check(int iteration, double error);
};

#endif // ITERATION_CONDITION_H
