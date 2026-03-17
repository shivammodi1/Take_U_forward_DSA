#include<bits/stdc++.h>
using namespace std;

// Max-Heapify
void heapify(vector<int> &arr,int n,int index){
    int largest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;

    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }
    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }

    if(largest != index){
        swap(arr[largest],arr[index]);
        heapify(arr,n,largest);
    }
}

int main(){
    vector<int> arr = {10, 20, 15, 30, 40};
    // n/2 - 1 isliye ki hum leaf nodes already heapify property ko follow karte hain, 
    // toh unko heapify karne ki zarurat nahi hoti
    for(int i = arr.size()/2 - 1; i >= 0; i--){ 
        heapify(arr, arr.size(), i);
    }
    return 0;
}