#include <bits/stdc++.h>
using namespace std;

/*
    Heap Data Structure:

    - Heap ek Complete Binary Tree hota hai.
    - Har level completely filled hota hai except last level.
    - Last level left se right fill hota hai.

    Array representation:
        Left child  = 2*i + 1
        Right child = 2*i + 2
        Parent      = (i-1)/2

    Min Heap:
    - Har parent node apne children se chota ya equal hota hai.
    - Sabse chota element root par hota hai.
*/

class minHeap{
    int *arr;       // heap ko store karne ke liye array
    int size;       // current elements ka size
    int capacity;   // maximum capacity

public:

    // Constructor heap create karne ke liye
    minHeap(int c){
        arr = new int[c];
        size = 0;
        capacity = c;
    }

    // Heap me new element insert karne ka function
    void insert(int val){

        // Agar heap full ho gaya
        if(size == capacity){
            cout<<"Heap is full"<<endl;
            return;
        }

        // New element ko last position par insert karo
        arr[size] = val;
        size++;

        // Heap property maintain karne ke liye heapify up
        int index = size - 1;

        while(index > 0){

            // Parent ka index nikalna
            int parent = (index-1)/2;

            // Agar parent bada hai child se to swap karo
            if(arr[parent] > arr[index]){
                swap(arr[parent], arr[index]);

                // Ab new index parent ban jayega
                index = parent;
            }
            else{
                // Agar heap property satisfy ho gayi to loop stop
                break;
            }
        }
    }

    // Heap ko print karne ka function
    void print(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){

    // Heap create kar rahe hain capacity 10 ke saath
    minHeap h(10);

    // Elements insert kar rahe hain
    h.insert(10);
    h.insert(5);
    h.insert(20);
    h.insert(2);

    // Heap print kar rahe hain
    h.print();

    return 0;
}