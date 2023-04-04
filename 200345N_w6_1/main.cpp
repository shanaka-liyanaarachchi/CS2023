#include <iostream>
#define MAX_SIZE 10
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;


class Stack {
private:
    int top;
    int arr[MAX_SIZE];
public:
    Stack() {
        top = -1;
    }
    bool isEmpty() {
        return (top == -1);
    }
    bool isFull() {
        return (top == MAX_SIZE - 1);
    }
    void Push(int x) {
        // here isFull returns whether there is an empty slot available in the stack
        // didn't use increment the SP and then check, as in the pseudo code because this is easy.
        if (isFull()) {
            cout << "Error: Stack Overflow" << endl;
            return;
        }
        arr[++top] = x;
    }
    void Pop() {
        if (isEmpty()) {
            cout << "Error: Stack Underflow" << endl;
            return;
        }
        int popped = arr[top--];
    }

    int stackTop() {
        if (isEmpty()) {
            cout << "Error: Stack Underflow" << endl;
            return -1;
        }
        return arr[top];
    }
    void Display() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return;
        }
        cout << "Elements: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
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

    cout << " Time taken using Array  " << duration.count() << " milliseconds" << endl;

    return 0;
}

