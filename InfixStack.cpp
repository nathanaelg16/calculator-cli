//
// Created by Nathanael Gutierrez on 10/29/20.
//

#include "InfixStack.h"

void InfixStack::push(Operand o) {
    array[++position] = o;
}

Operand InfixStack::pop() {
    return array[position--];
}

Operand InfixStack::top() {
    return array[position];
}

bool InfixStack::isEmpty() {
    return position == -1;
}
