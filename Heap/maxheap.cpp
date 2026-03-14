#include<bits/stdc++.h>
using namespace std;

class maxHeap{
    int *arr;      // heap store karne ke liye array
    int size;      // current elements
    int capacity;  // maximum size

public:

    // constructor heap create karne ke liye
    maxHeap(int c){
        arr = new int[c];
        size = 0;
        capacity = c;
    }

    // new element insert karne ka function
    void insert(int val){

        // agar heap full ho gaya
        if(size == capacity){
            cout<<"Heap is full"<<endl;
            return;
        }

        // element last position par insert karo
        arr[size] = val;
        size++;

        int index = size - 1;

        // heapify up (max heap property maintain karne ke liye)
        while(index > 0){

            int parent = (index-1)/2;

            // agar child parent se bada hai to swap karo
            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{
                break;
            }
        }
    }

    // heap print karne ka function
    void print(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){

    maxHeap h(10);

    h.insert(10);
    h.insert(50);
    h.insert(20);
    h.insert(60);

    h.print();

    return 0;
}