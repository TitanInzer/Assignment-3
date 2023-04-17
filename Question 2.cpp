#include <iostream>
#include "Question 2.h"

Queue::Queue() {}

void Queue::push(int value) {
    data.push_back(value);
}

int Queue::pop() {
    int frontElement = data.front();
    data.erase(data.begin());
    return frontElement;
}

int Queue::front() const {
    return data.front();
}

bool Queue::empty() const {
    return data.empty();
}

int Queue::size() const {
    return data.size();
}

int main() {
    Queue myQueue;

    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);

    int frontElement = myQueue.front();
    std::cout << "Front element: " << frontElement << std::endl;

    int poppedElement = myQueue.pop();
    std::cout << "Popped element: " << poppedElement << std::endl;

    std::cout << "Queue size: " << myQueue.size() << std::endl;

    bool isEmpty = myQueue.empty();
    std::cout << "Queue is empty: " << std::boolalpha << isEmpty << std::endl;

    return 0;
}