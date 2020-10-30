//
// Created by Nathanael Gutierrez on 10/29/20.
//

#ifndef CALCULATOR_INFIXQUEUE_H
#define CALCULATOR_INFIXQUEUE_H


class InfixQueue {
private:
    class Node {
    public:
        int x;
        InfixQueue::Node *next{};
        explicit Node(int x);
    };
    InfixQueue::Node *frontNode = new InfixQueue::Node(-1);
    InfixQueue::Node *backNode;

public:
    void enqueue(int);
    void dequeue();
    int front();
    bool isEmpty();
};


#endif //CALCULATOR_INFIXQUEUE_H
