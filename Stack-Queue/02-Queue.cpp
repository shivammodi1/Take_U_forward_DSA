#include<bits/stdc++.h>
using namespace std;

// Queue is a FIFO data structure (First In First Out)
// Basic operations: push, pop, front, size, empty
// Time complexity of all operations is O(1)
// Space complexity is O(n)

int main() {
    queue<int> q;

    // Push elements onto the queue
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.front() << endl; // Output: 10
    cout << "Queue size: " << q.size() << endl;     // Output: 3

    // Pop elements from the queue
    q.pop();
    cout << "Front element after pop: " << q.front() << endl; // Output: 20
    cout << "Queue size after pop: " << q.size() << endl;     // Output: 2

    // Check if queue is empty
    if (!q.empty()) {
        cout << "Queue is not empty" << endl;
    } else {
        cout << "Queue is empty" << endl;
    }

    return 0;
}