//stack using aaray
#include <iostream>
using namespace std;

class Stack {
    int* arr;
    int top;
    int size;

public:
    // Constructor
    Stack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    
    // Destructor
    ~Stack() {
        delete[] arr;
    }
    
    // Push operation
    void push(int element) {
        if (top < size - 1) {
            top++;
            arr[top] = element;
        } else {
            cout << "Stack overflow" << endl;
        }
    }
    
    // Pop operation
    void pop() {
        if (top >= 0) {
            top--;
        } else {
            cout << "Stack underflow" << endl;
        }
    }
    
    // Peek operation
    int peek() {
        if (top >= 0) {
            return arr[top];
        } else {
            cout << "Stack is empty" << endl;
            return -1;
        }
    }
    
    // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }
    
    // Reverse the stack
    void reverse() {
        if (isEmpty()) {
            cout << "Stack is empty, cannot reverse." << endl;
            return;
        }
        
        int s = top + 1; // Calculate the size of the stack
        for (int i = 0; i < s / 2; i++) {
            // Swap elements
            int temp = arr[i];
            arr[i] = arr[s - 1 - i];
            arr[s - 1 - i] = temp;
        }
    }
    
    // Print stack elements
    void print() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " "; 
        }
        cout << endl; 
    }
    
    // Sort the stack
    void sort() {
        int s = top + 1; 
        for (int i = 0; i < s; i++) {
            for (int j = i + 1; j < s; j++) {
                // Sort in ascending order
                if (arr[i] > arr[j]) {
                    // Swap elements
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
};

int main() {
    Stack st(5); // Increased size for testing
    st.push(20);
    st.push(30);
    st.push(70);
    st.push(7); // Should not cause overflow
    st.push(10); // Another push
    
    cout << "Original Stack: ";
    st.print();
    
    st.sort(); // Sort the stack
    cout << "Sorted Stack: ";
    st.print(); // Print the sorted stack
    
    st.pop();
    cout << "Top element after pop: " << st.peek() << endl;
    st.reverse(); // Reverse the stack
    cout << "Reversed Stack: ";
    st.print(); // Print the reversed stack

    return 0;
}

