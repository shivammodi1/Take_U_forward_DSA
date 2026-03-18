#include<bits/stdc++.h>
using namespace std;


// Approach 1: Using Max Heap
// step1. Build a max heap from the given array.
// step2. Pop the top element from the max heap k-1 times.
// step3. The top element of the max heap will be the kth largest element in the array.
// step4. Return the top element of the max heap as the answer.

// Time Complexity: O(nlogn) + O(klogn) => O(nlogn)
// Space Complexity: O(n)

int kthLargest(vector<int>& nums,int k){
    priority_queue<int> pq;
    for(int i=0;i<nums.size();i++){
        pq.push(nums[i]);
    }

    int ans;

    while(!pq.empty() && k--){
        ans = pq.top();
        pq.pop();
    }
    return ans;
}



/*
    Approach 2: Using Min Heap
*/

int main(){
    return 0;
}