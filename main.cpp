#include <iostream>
#include "PostfixStack.h"
#include "Operation.h"
#include "InfixStack.h"
#include "InfixQueue.h"

std::string convertInfixToPostfix(std::string expr);
int evaluatePostfixExpression(std::string expr);
std::string orderOfOperations(InfixStack *stack, InfixQueue *q, Operand o);

int main() {
    std::string infix;

    std::cout << "Calculator" << std::endl;
    std::cin >> infix;

    std::string postfix = convertInfixToPostfix(infix);
    std::cout << "Postfix Expr: " << postfix << std::endl;

    std::cout << "Result: " << evaluatePostfixExpression(postfix);

    return 0;
}

std::string convertInfixToPostfix(std::string expr) {
    auto oprStack = new InfixStack();
    auto numQ = new InfixQueue();
    std::string newExpr;

    for (char c : expr) {
        auto operand = getOperand(c);
        if (operand == DIGIT) numQ->enqueue((int)(c - '0'));
        else newExpr += orderOfOperations(oprStack, numQ, operand);
    }

    while (!(numQ->isEmpty())) {
        newExpr += (char)(numQ->front() + '0');
        numQ->dequeue();
    }

    while (!oprStack->isEmpty()) {
        newExpr += getOperandAsChar(oprStack->pop());
    }

    return newExpr;
}

std::string orderOfOperations(InfixStack *stack, InfixQueue *q, Operand o) {
    if (!stack->isEmpty() && stack->top() > 2 && stack->top() > o) {
        std::string s;
        s = (char)(q->front());
        q->dequeue();
        s += (char)(q->front());
        q->dequeue();
        return s + getOperandAsChar(stack->pop()) + orderOfOperations(stack, q, o);
    }

    stack->push(o);
    return "";
}

int evaluatePostfixExpression(std::string expr) {
    auto stack = new PostfixStack();

    for (char c : expr) {
        auto operand = getOperand(c);
        if (operand == DIGIT) stack->push(c - '0');
        else {
            int b = stack->pop();
            int a = stack->pop();
            switch (operand) {
                case ADDITION:
                    stack->push(a + b);
                    break;
                case SUBTRACTION:
                    stack->push(a - b);
                    break;
                case MULTIPLICATION:
                    stack->push(a * b);
                    break;
                case DIVISION:
                    stack->push(a / b);
                    break;
                default:
                    break;
            }
        }
    }

    return stack->pop();
}