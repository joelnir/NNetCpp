#include "InputNode.h"

InputNode::InputNode(){}

InputNode::InputNode(double value): value(value){}

double InputNode::getOutput(){
    return this->value;
}


void InputNode::setValue(double value){
    this->value = value;
}
