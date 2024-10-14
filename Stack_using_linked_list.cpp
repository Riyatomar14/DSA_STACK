//stack using linked list
#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    // Constructor
    node(int data) {
        this->data = data;
        this->next = NULL;
    }

    // Destructor
    ~node() {
        cout << "Memory is free for node with data: " << this->data << endl;
    }
};

// Global pointer to the top of the stack
node* top = NULL;

// Push function to add data to the stack
void push(int data) {
    node* newnode = new node(data);
    newnode->next = top;  // Link new node to the previous top
    top = newnode;        // Update top to new node
}

// Pop function to remove and return the top data from the stack
void pop() {
    if (top == NULL) {
        cout << "Stack underflow" << endl;
    } else {
        node* temp = top;
        cout << "Popped: " << temp->data << endl;
        top = top->next;   // Move top to the next node
        delete temp;       // Free memory for the popped node
    }
}

// Function to check if the stack is empty
bool isEmpty() {
    return top == NULL;
}

// Function to find and return the top element without popping it
int findTop() {
    if (top != NULL) {
        return top->data;
    } else {
        cout << "Stack is empty" << endl;
        return -1;  // Indicates the stack is empty
    }
}

// Function to print the entire stack
void print() {
    node* temp = top;
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack elements: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

// Function to search for an element in the stack
bool search(int value) {
    node* temp = top;
    while (temp != NULL) {
        if (temp->data == value) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main() {
    push(10);
    push(20);
    push(30);
    
    print();  // Prints the current stack
    
    pop();    // Removes the top element
    print();  // Prints the stack after popping
    
    cout << "Top element: " << findTop() << endl;  // Display top element
    
    if (search(20)) {
        cout << "Element 20 found in the stack" << endl;
    } else {
        cout << "Element 20 not found in the stack" << endl;
    }

    if (isEmpty()) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is not empty" << endl;
    }

    return 0;
}
