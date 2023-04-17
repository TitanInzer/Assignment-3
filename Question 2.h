#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <vector>

class Queue {
public:
    Queue();
    void push(int value);
    int pop();
    int front() const;
    bool empty() const;
    int size() const;

private:
    std::vector<int> data;
};

#endif