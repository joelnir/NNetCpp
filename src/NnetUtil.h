namespace NnetUtil{
    /**
     * Unit step function
     *
     * y(x) = 0 if x < 0
     * y(x) = 1 if x >= 0
     */
    double unitStep(double x);

    /**
     * Sigmoid function
     *
     * y(x) = 1 / (1 + exp(-x))
     */
    double sigmoid(double x);
}
