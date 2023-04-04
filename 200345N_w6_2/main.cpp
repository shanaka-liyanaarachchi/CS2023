
#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Node { // Node class to implement the linked list
public:
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;
public:
    Stack() {
        top = nullptr;
    }
    void Push(int x) {
        Node* newNode = new Node; // create a new node for the linked list
        newNode->data = x;
        newNode->next = top;
        top = newNode;
    }
    void Pop() {
        if (isEmpty()) {
            cout << "Error: Stack Underflow" << endl;
            return;
        }
        int popped = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    bool isEmpty() {
        return (top == nullptr);
    }
    bool isFull() {
        return false;
    }
    int stackTop() {
        if (isEmpty()) {
            cout << "Error: Stack Underflow" << endl;
            return -1;
        }
        return top->data;
    }
    void Display() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return;
        }
        cout << "Elements : ";
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    auto start_time = high_resolution_clock::now();
    Stack l;
    l.Push(8);
    l.Push(10);
    l.Push(5);
    l.Push(11);
    l.Push(15);
    l.Push(23);
    l.Push(6);
    l.Push(18);
    l.Push(20);
    l.Push(17);
    l.Display();
    l.Pop();
    l.Pop();
    l.Pop();
    l.Pop();
    l.Pop();
    l.Display();
    l.Push(4);
    l.Push(30);
    l.Push(3);
    l.Push(1);
    l.Display();
    auto end_time= high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end_time - start_time);

    cout << " Time taken using linked list " << duration.count() << " milliseconds" << endl;

    return 0;
}
