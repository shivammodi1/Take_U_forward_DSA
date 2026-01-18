#include<bits/stdc++.h>
using namespace std;

// Implementing Stack using a single Queue
class Stack {
    queue<int> q;

public:
    void push(int x) {
        q.push(x);
        int sz = q.size();

        // rotate previous elements
        for(int i = 0; i < sz - 1; i++){
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (!q.empty()) {
            q.pop();
        }
    }

    int top() {
        if (!q.empty()) {
            return q.front();
        }
        throw runtime_error("Stack is empty");
    }

    bool empty() {
        return q.empty();
    }
};
