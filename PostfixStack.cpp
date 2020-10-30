//
// Created by Nathanael Gutierrez on 10/29/20.
//

#include "PostfixStack.h"

void PostfixStack::push(int val) {
    array[++position] = val;
}

int PostfixStack::pop() {
    return array[position--];
}

int PostfixStack::top() {
    return array[position];
}

bool PostfixStack::isEmpty() {
    return position == -1;
}


