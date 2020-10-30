//
// Created by Nathanael Gutierrez on 10/29/20.
//

#include "Operation.h"
#include <exception>

Operand getOperand(char c) {
    if (c >= 48 && c <= 57) return DIGIT;
    switch (c) {
        case '*':
            return MULTIPLICATION;
        case '/':
            return DIVISION;
        case '+':
            return ADDITION;
        case '-':
            return SUBTRACTION;
        default:
            throw std::exception();
    }
}

char getOperandAsChar(Operand o) {
    switch (o) {
        case ADDITION:
            return '+';
        case SUBTRACTION:
            return '-';
        case MULTIPLICATION:
            return '*';
        case DIVISION:
            return '/';
        default:
            return '0';
    }
}