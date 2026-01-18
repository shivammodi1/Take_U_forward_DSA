#include<bits/stdc++.h>
using namespace std;

class queue{
    int *arr;
    int front;
    int size;
    int rear;
    public:
    queue(int s){
        arr = new int[s];
        size = s;
        front = -1;
        rear = -1;
    }
    void push(int x){
        if(rear==size-1){
            cout<<"Queue Overflow"<<endl;
            return;
        }
        rear++;
        arr[rear]=x;
        if(front==-1){
            front=0;
        }
    }
    void pop(){
        if(front==-1 || front>rear){
            cout<<"Queue Underflow"<<endl;
            return;
        }
        front++;
    }
    int peek(){
        if(front==-1 || front>rear){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return arr[front];
    }
    int getSize(){
        if(front==-1 || front>rear){
            return 0;
        }
        return rear-front+1;
    }
    bool isEmpty(){
        return front==-1 || front>rear;
    }
    
};