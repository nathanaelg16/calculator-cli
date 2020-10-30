//
// Created by Nathanael Gutierrez on 10/29/20.
//

#ifndef CALCULATOR_POSTFIXSTACK_H
#define CALCULATOR_POSTFIXSTACK_H

class PostfixStack {
    private:
        int array[1024];
        int position = -1;

    public:
        void push(int);
        int pop();
        int top();
        bool isEmpty();
};


#endif //CALCULATOR_POSTFIXSTACK_H
