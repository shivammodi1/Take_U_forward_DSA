#include<bits/stdc++.h>
using namespace std;

class queue{
    int *arr;
    int front;
    int rear;
    int size;

public:
    queue(int s){
        size = s;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void push(int x){
        // Queue Full
        if((rear + 1) % size == front){
            cout << "Queue Overflow" << endl;
            return;
        }

        // First element
        if(front == -1){
            front = rear = 0;
        }
        else{
            rear = (rear + 1) % size;
        }

        arr[rear] = x;
    }

    void pop(){
        // Queue Empty
        if(front == -1){
            cout << "Queue Underflow" << endl;
            return;
        }

        // Single element
        if(front == rear){
            front = rear = -1;
        }
        else{
            front = (front + 1) % size;
        }
    }

    int peek(){
        if(front == -1){
            cout << "Queue is Empty" << endl;
            return -1;
        }
        return arr[front];
    }

    bool isEmpty(){
        return front == -1;
    }

    int getSize(){
        if(front == -1)
            return 0;

        if(rear >= front)
            return rear - front + 1;

        return size - front + rear + 1;
    }

    ~queue(){
        delete[] arr;
    }
};
int main(){
    queue q(5);

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.peek() << endl; // Output: 10
    cout << "Queue size: " << q.getSize() << endl; // Output: 3

    q.pop();
    cout << "Front element after pop: " << q.peek() << endl; // Output: 20
    cout << "Queue size after pop: " << q.getSize() << endl; // Output: 2

    if (!q.isEmpty()) {
        cout << "Queue is not empty" << endl;
    } else {
        cout << "Queue is empty" << endl;
    }

    return 0;
}