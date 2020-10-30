//
// Created by Nathanael Gutierrez on 10/29/20.
//

#ifndef CALCULATOR_OPERATION_H
#define CALCULATOR_OPERATION_H

enum Operand {
    DIGIT = 0,
    ADDITION = 1,
    SUBTRACTION = 2,
    MULTIPLICATION = 3,
    DIVISION = 4
};

Operand getOperand(char);
char getOperandAsChar(Operand);

#endif //CALCULATOR_OPERATION_H
