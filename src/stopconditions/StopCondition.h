#ifndef STOP_CONDITION_H
#define STOP_CONDITION_H

#include <vector>

/**
 * Interface for classes describing conditions for
 * whether to continue training Neural Nets
 */
class StopCondition{
    public:
        /**
         * Control if the condition has been met
         *
         * @param iteration amount of training iterations ran
         * @param error current error from evaluation
         *
         * @return if training is done
         */
        virtual bool check(int iteration, double error) = 0;
};

#endif // STOP_CONDITION_H
