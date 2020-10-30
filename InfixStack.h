//
// Created by Nathanael Gutierrez on 10/29/20.
//

#ifndef CALCULATOR_INFIXSTACK_H
#define CALCULATOR_INFIXSTACK_H

#include "Operation.h"

class InfixStack {
private:
    Operand array[1024];
    int position = -1;

public:
    void push(Operand);
    Operand pop();
    Operand top();
    bool isEmpty();
};


#endif //CALCULATOR_INFIXSTACK_H
