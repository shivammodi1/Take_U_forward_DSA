#include<bits/stdc++.h>
using namespace std;

/*
    # k Most Frequent Elements
    - Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
    - Example 1:
        Input: nums = [1,1,1,2,2,3], k = 2
        Output: [1,2]
    - Example 2:
        Input: nums = [1], k = 1
        Output: [1]
    
    # Approach 1: Using Max Heap and Hash Map
    - Phale hum 1 unordered map banayege jisme frequency store karenge.
    - Phir hum ex max banayege uske ander pair me freq and element store karenge.
    - Phir jab sara data max heap me store ho jayega to hum iterate karege max heap jab k-- hoga and pq.empty() nahi hoga tab tak.
    - Jab k-- hoga to hum top element ko ans me store karenge and pop karenge.
    - Finally return ans.
*/


vector<int> topKFrequent(vector<int> &nums,int k){
    unordered_map<int,int>freq;
    for(int i=0;i<nums.size();i++){
        freq[nums[i]]++;
    }
    // Max Heap
    // pair<frequency,element>
    priority_queue<pair<int,int>>pq;
    for(auto it:freq){
        pq.push({it.second,it.first});
    }

    vector<int>ans;
    while(!pq.empty() && k--){
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}


int main(){
    return 0;
}