#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};

class stack{
    node *top;
    public:
    stack(){
        top = NULL;
    }
    void push(int val){
        node *newnode = new node(val);
        if(!top){
            top = newnode;
            return;
        }
        newnode->next = top;
        top = newnode;
    }

    void pop(){
        node* temp = top;
        if(!top) return;
        top = top->next;
        delete temp;
    }

    int peek(){
        if(!top) return -1;
        return top->data;
    }

    bool isEmpty(){
        return top == NULL;
    }

};

int main(){
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<st.peek()<<endl; // 3
    st.pop();
    cout<<st.peek()<<endl; // 2
    st.pop();
    cout<<st.peek()<<endl; // 1
    st.pop();
    cout<<st.isEmpty()<<endl; // 1 (true)
    return 0;
}