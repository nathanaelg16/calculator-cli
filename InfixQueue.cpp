//
// Created by Nathanael Gutierrez on 10/29/20.
//

#include "InfixQueue.h"

void InfixQueue::enqueue(int i) {
    if (isEmpty()) {
        frontNode->next = new InfixQueue::Node(i);
        backNode = frontNode->next;
    } else {
        backNode->next = new InfixQueue::Node(i);
        backNode = backNode->next;
    }
}

void InfixQueue::dequeue() {
    frontNode->next = frontNode->next->next;
}

int InfixQueue::front() {
    return frontNode->next->x;
}

bool InfixQueue::isEmpty() {
    return frontNode->next == nullptr;
}

InfixQueue::Node::Node(int x) : x(x) {}
