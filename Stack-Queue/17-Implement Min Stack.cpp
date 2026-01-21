#include<bits/stdc++.h>
using namespace std;


// Implement a stack that supports:
// push(x) -- Push element x onto stack.
// pop() -- Removes the element on top of the stack.
// top() -- Get the top element.
// getMin() -- Retrieve the minimum element in the stack.

class stack{
    stack<pair<int,int>>st;  // first -> value , second -> min till now
    public:
    void push(int x){
        if(st.empty()){
            st.push({x,x});
        }else{
            int curr_min  = st.top().second;
            int min_val = min(curr_min,x);
            st.push({x,min_val});
        }
    }
    void pop(){
        if(!st.empty()){
            st.pop();
        }
    }
    int top(){
        if(!st.empty()){
            return st.top().first;
        }
        return -1; // or throw an exception
    }
    int getMin(){
        if(!st.empty()){
            return st.top().second;
        }
        return -1; // or throw an exception
    }

};

int main(){
    stack s;
    s.push(3);
    s.push(5);
    cout<<s.getMin()<<endl; // 3
    s.push(2);
    s.push(1);
    cout<<s.getMin()<<endl; // 1
    s.pop();
    cout<<s.getMin()<<endl; // 2
    cout<<s.top()<<endl;    // 2
    return 0;
}