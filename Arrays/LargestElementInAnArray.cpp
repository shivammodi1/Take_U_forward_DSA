#include <bits/stdc++.h>
using namespace std;

int BruteForce(int arr[],int n){
    // Sort the array
    // and last elemnt will be largest
    // time complexity O(nlogn)
    // space complexity O(1)
    sort(arr,arr+n);
    return arr[n-1];
}

int OptimalSolution(int arr[],int n){
    // Traverse the array and keep track of largest element
    // time complexity O(n)
    // space complexity O(1)
    int largest = INT_MIN;
    for(int i = 0; i < n; i++){
        if(arr[i] > largest){
            largest = arr[i];
        }
    }
    return largest;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << "Brute Force: " << BruteForce(arr,n) << endl;
    cout << "Optimal Solution: " << OptimalSolution(arr,n) << endl;
    return 0;
}