#include<bits/stdc++.h>
using namespace std;


class stack{
    int *arr;
    int top;
    int size;
    public:
    stack(int s){
        size = s;
        arr = new int[size];
        top = -1;
    }
    void push(int x){
        if(top==size-1){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        top++;
        arr[top]=x;
    }
    void pop(){
        if(top==-1){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        top--;
    }
    int peek(){
        if(top==-1){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return arr[top];
    }
    int getSize(){
        return top+1;
    }
    bool isEmpty(){
        return top==-1;
    }
};

int main(){
    stack st(5);

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.peek() << endl; // Output: 30
    cout << "Stack size: " << st.getSize() << endl; // Output: 3

    st.pop();
    cout << "Top element after pop: " << st.peek() << endl; // Output: 20
    cout << "Stack size after pop: " << st.getSize() << endl; // Output: 2

    if (!st.isEmpty()) {
        cout << "Stack is not empty" << endl;
    } else {
        cout << "Stack is empty" << endl;
    }

    return 0;
}