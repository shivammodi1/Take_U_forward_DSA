#include <bits/stdc++.h>
using namespace std;


int SecondLargest(int arr[],int n){
    // Traverse the array and keep track of largest element
    // time complexity O(n)+O(n) = O(2n) = O(n)
    // space complexity O(1)
    
    if(n < 2){
        return -1; 
    }

    int largest = INT_MIN;
    int second_largest = INT_MIN;
    for(int i = 0; i < n; i++){
        if(arr[i] > largest){
            largest = arr[i];
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i]>second_largest){
            if(arr[i]!=largest){
                second_largest=arr[i];
            }
        }
    }
    return second_largest;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << "Second Solution: " << SecondLargest(arr,n) << endl;
    return 0;
}