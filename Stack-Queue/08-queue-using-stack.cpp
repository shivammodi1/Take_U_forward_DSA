#include<bits/stdc++.h>
using namespace std;

class queue{
    stack<int> s1, s2;
    public:
    void push(int x){
        /// Step 1: s1 → s2
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        // Step 2: push new element
        s1.push(x);

        // Step 3: s2 → s1
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    void pop(){
        if(!s1.empty()){
            s1.pop();
        }
    }
    int front(){
        if(!s1.empty()){
            return s1.top();
        }
        return -1; // or throw an exception
    }
    bool empty(){
        return s1.empty();
    }
};

int main(){
    queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout << q.front() << endl; // Output: 10
    q.pop();
    cout << q.front() << endl; // Output: 20
    q.pop();
    cout << q.front() << endl; // Output: 30
    q.pop();
    cout << (q.empty() ? "Queue is empty" : "Queue is not empty") << endl; // Output: Queue is empty
    return 0;
}