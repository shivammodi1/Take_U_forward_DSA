#include<bits/stdc++.h>
using namespace std;

/*
    Heapify Algorithm:

    - Heapify ka use heap property maintain karne ke liye hota hai.
    - Agar heap property break ho jaye (insert ya delete ke baad),
      to heapify use karke tree ko dobara correct karte hain.

    Max Heap:
    Parent >= Children

    Min Heap:
    Parent <= Children
*/

// ---------------- MAX HEAPIFY ----------------

void maxHeapify(vector<int>& arr,int n,int i){

    int largest = i;

    // left child index
    int left = 2*i + 1;

    // right child index
    int right = 2*i + 2;

    // check karo left child bada hai kya
    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }

    // check karo right child bada hai kya
    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }

    // agar parent largest nahi hai to swap karo
    if(largest != i){

        swap(arr[i], arr[largest]);

        // ab subtree ko heapify karo
        maxHeapify(arr, n, largest);
    }
}


// ---------------- MIN HEAPIFY ----------------

void minHeapify(vector<int> &arr,int n,int i){

    int smallest = i;

    int left = 2*i + 1;
    int right = 2*i + 2;

    // check karo left child chhota hai kya
    if(left < n && arr[left] < arr[smallest]){
        smallest = left;
    }

    // check karo right child chhota hai kya
    if(right < n && arr[right] < arr[smallest]){
        smallest = right;
    }

    // agar parent smallest nahi hai to swap karo
    if(smallest != i){

        swap(arr[i], arr[smallest]);

        // subtree ko heapify karo
        minHeapify(arr, n, smallest);
    }
}


// array print karne ka function
void print(vector<int> &arr){

    for(int x : arr){
        cout<<x<<" ";
    }
    cout<<endl;
}

int main(){

    vector<int> arr = {4,10,3,5,1};

    int n = arr.size();

    // max heapify root par apply
    maxHeapify(arr,n,0);

    cout<<"After Max Heapify:"<<endl;
    print(arr);

    // min heapify root par apply
    minHeapify(arr,n,0);

    cout<<"After Min Heapify:"<<endl;
    print(arr);

}