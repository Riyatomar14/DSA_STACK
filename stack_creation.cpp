// stack using STL
#include <iostream>
#include <stack>
using namespace std;

int main() {
    //creation
    stack <int> s;
    //push
    s.push(8);
    s.push(10);
    //pop
    s.pop();
    //for top element 
    cout<<"the top element is "<<s.top();
    //fir checking stack is empty 
    cout<<endl;
    if(s.empty()){
        cout<<"stack is empty";
    }
    else{
        cout<<"stack is not empty";
    }
    return 0;
}
