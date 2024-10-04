#include <iostream>
using namespace std;

class TwoStack {
    int size;
    int* arr;
    int top1;
    int top2;

public:
    // Constructor
    TwoStack(int size) {
        this->size = size;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    // Push in stack 1
    void push1(int num) {
        if (top2 - top1 > 1) {
            top1++;
            arr[top1] = num;
        } else {
            cout << "Stack Overflow for Stack 1\n";
        }
    }

    // Push in stack 2
    void push2(int num) {
        if (top2 - top1 > 1) {
            top2--;
            arr[top2] = num;
        } else {
            cout << "Stack Overflow for Stack 2\n";
        }
    }

    // Pop from stack 1
    int pop1() {
        if (top1 >= 0) {
            int ans = arr[top1];
            top1--;
            return ans;
        } else {
            cout << "Stack Underflow for Stack 1\n";
            return -1;
        }
    }

    // Pop from stack 2
    int pop2() {
        if (top2 < size) {
            int ans = arr[top2];
            top2++;
            return ans;
        } else {
            cout << "Stack Underflow for Stack 2\n";
            return -1;
        }
    }

    // Destructor to free memory
    ~TwoStack() {
        delete[] arr;
    }
};

int main() {
    TwoStack ts(5);

    ts.push1(5);
    ts.push2(10);
    ts.push1(15);
    ts.push2(20);

    cout << "Popped from Stack 1: " << ts.pop1() << endl;
    cout << "Popped from Stack 2: " << ts.pop2() << endl;

    return 0;
}
