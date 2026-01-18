#include<bits/stdc++.h>
using namespace std;

// stack is a LIFO data structure (Last In First Out)
// basic operations: push, pop, top, size, empty
// time complexity of all operations is O(1)
// space complexity is O(n)


int main() {
    stack<int> st;

    // push elements onto the stack
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.top() << endl; // Output: 30
    cout << "Stack size: " << st.size() << endl; // Output: 3

    // pop elements from the stack
    st.pop();
    cout << "Top element after pop: " << st.top() << endl; // Output: 20
    cout << "Stack size after pop: " << st.size() << endl; // Output: 2

    // check if stack is empty
    if (!st.empty()) {
        cout << "Stack is not empty" << endl;
    } else {
        cout << "Stack is empty" << endl;
    }

    return 0;
}