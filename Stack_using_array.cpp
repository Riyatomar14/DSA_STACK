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
        if (size-top >= 1) {
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
    
    // Peek or top operation
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
        if(top==-1){
            cout<<"stack is empty"<<endl;
            return true;
        }
        else{
            cout<<"stack is not empty"<<endl;
            return false;
        }
    }
};

int main() {
    //st instance if size 3.
    Stack st(2);
    st.push(20);
    st.push(30);
    st.push(70);
    st.push(7);//overflow
    st.pop();
    cout << st.peek() << endl;
    st.isEmpty();
    st.pop();
    st.isEmpty();
    return 0;
}
