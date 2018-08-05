#include "InputNode.h"

InputNode::InputNode(){}

InputNode::InputNode(double value): value(value){}

double InputNode::getOutput(){
    return this->value;
}
