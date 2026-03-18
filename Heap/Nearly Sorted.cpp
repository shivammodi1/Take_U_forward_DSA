#include <bits/stdc++.h>
using namespace std;

/*
    # Nearly Sorted
    Given an array arr[], where each element is at most k positions away from its correct position in the sorted order.
    Your task is to restore the sorted order of arr[] by rearranging the elements in place.

    Note: Don't use any sort() method.

    # Example:
    Input: arr[] = {6, 5, 3, 2, 8, 10, 9}, k = 3
    Output: arr[] = {2, 3, 5, 6, 8, 9, 10}

    # Approach: Using Min Heap
    - Hum 1 min heap me sare elements ko push kr denge.
    - phir hum iterate krke min heap se top element ko pop krke arr me store kr denge.
    - jab tak min heap empty nahi ho jata tab tak ye process repeat krte rahenge.
*/

void nearlySorted(vector<int>& arr,int k){
    // Min Heap 
    // greater<int> is used to create a min heap
    // arr.begin() and arr.end() is used to initialize the min heap with the elements of the array
    priority_queue<int,vector<int>,greater<int>>pq(arr.begin(),arr.end());

    int j = arr.size() - k;
    while(!pq.empty()){
        arr[j++] = pq.top();
        pq.pop();
    }
}

int main()
{
    return 0;
}


