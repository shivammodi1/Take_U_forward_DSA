#include<bits/stdc++.h>
using namespace std;

/*
    # Priority Queue in C++
    - A priority queue is a data structure that store elements in a way that the highest priority element is always at the front of the queue.
    - In C++, we can use the `priority_queue` class from the `<queue>` header to implement a priority queue.
    # Syntax
    ```cpp
    priority_queue<int> pq; // Creates a max heap
    priority_queue<int, vector<int>, greater<int>> pq; // Creates a min heap
    ```
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    // Max Heap
    priority_queue<int> pq;
    pq.push(10);
    pq.push(20);
    pq.push(5);
    cout << "Max Heap: ";
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    // output: Max Heap: 20 10 5
    cout << endl;

    // Min Heap
    priority_queue<int, vector<int>, greater<int>> min_pq;
    min_pq.push(10);
    min_pq.push(20);
    min_pq.push(5);
    cout << "Min Heap: ";
    while(!min_pq.empty()){
        cout << min_pq.top() << " ";
        min_pq.pop();
    }
    // output: Min Heap: 5 10 20
    cout << endl;

    return 0;
}