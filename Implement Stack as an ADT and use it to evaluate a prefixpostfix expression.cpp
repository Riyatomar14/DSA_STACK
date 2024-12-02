#include <iostream>
#include <string>
using namespace std;

// Stack Implementation
class Stack {
private:
    int *arr;
    int top;
    int capacity;

public:
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int x) {
        if (top >= capacity - 1) {
            cout << "Stack overflow\n";
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (top == -1) {
            cout << "Stack underflow\n";
            return -1;
        }
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }
};

// Function to apply arithmetic operations
int applyOperator(int operand1, int operand2, char op) {
    switch (op) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': return operand1 / operand2;
        case '^': { 
            int result = 1;
            for (int i = 0; i < operand2; ++i) {
                result *= operand1;
            }
            return result;
        }
        default: return 0;
    }
}

// Function to evaluate postfix expressions
int evaluatePostfix(string expr) {
    Stack s(expr.length());
    int i = 0;
    while (i < expr.length()) {
        if (isdigit(expr[i])) {
            int num = 0;
            while (i < expr.length() && isdigit(expr[i])) {
                num = num * 10 + (expr[i] - '0');
                i++;
            }
            s.push(num);
        } else if (expr[i] != ' ') {
            int operand2 = s.pop();
            int operand1 = s.pop();
            int result = applyOperator(operand1, operand2, expr[i]);
            s.push(result);
            i++;
        } else {
            i++;
        }
    }
    return s.pop();
}

// Function to evaluate prefix expressions
int evaluatePrefix(string expr) {
    Stack s(expr.length());
    int i = expr.length() - 1;
    while (i >= 0) {
        if (isdigit(expr[i])) {
            int num = 0;
            while (i >= 0 && isdigit(expr[i])) {
                num = num * 10 + (expr[i] - '0');
                i--;
            }
            s.push(num);
        } else if (expr[i] != ' ') {
            int operand1 = s.pop();
            int operand2 = s.pop();
            int result = applyOperator(operand1, operand2, expr[i]);
            s.push(result);
            i--;
        } else {
            i--;
        }
    }
    return s.pop();
}

int main() {
    // Test Postfix
    string postfixExpr = "23*5+";
    cout << "Postfix Result: " << evaluatePostfix(postfixExpr) << endl;

    // Test Prefix
    string prefixExpr = "+*23 5";
    cout << "Prefix Result: " << evaluatePrefix(prefixExpr) << endl;

    return 0;
}
