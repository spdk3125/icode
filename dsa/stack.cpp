#include <iostream>
using namespace std;

const int MAX = 10;

class Stack {
private:
    int items[MAX];
    int top;

public:
    Stack() : top(-1) {}
    bool isFull() { return top == MAX - 1; }
    bool isEmpty() { return top == -1; }
    void push(int newItem);
    void pop();
    void printStack();
};

void Stack::push(int newItem) {
    if (isFull()) {
        cout << "STACK FULL" << endl;
    } else {
        items[++top] = newItem;
    }
}

void Stack::pop() {
    if (isEmpty()) {
        cout << "STACK EMPTY" << endl;
    } else {
        cout << "Item popped: " << items[top--] << endl;
    }
}

void Stack::printStack() {
    cout << "Stack: ";
    for (int i = 0; i <= top; i++) {
        cout << items[i] << " ";
    }
    cout << endl;
}

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    s.printStack();

    s.pop();

    cout << "\nAfter popping out:\n";
    s.printStack();

    return 0;
}
