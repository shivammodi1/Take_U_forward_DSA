#include<bits/stdc++.h>
using namespace std;

/*
    Sliding Window Maximum (Using Priority Queue - Fixed)

    - pair {value, index} store karenge
    - jo element window ke bahar hoga usse remove karenge
*/

vector<int> maxSlidingWindow(vector<int>& nums,int k){
    vector<int> ans;

    // max heap -> {value, index}
    priority_queue<pair<int,int>> pq;

    // first window fill karo
    for(int i=0;i<k;i++){
        pq.push({nums[i], i});
    }

    // first window ka max
    ans.push_back(pq.top().first);

    // remaining windows
    for(int i=k;i<nums.size();i++){
        pq.push({nums[i], i});

        // jo element window se bahar ho gaya usse hatao
        while(!pq.empty() && pq.top().second <= i-k){
            pq.pop();
        }

        ans.push_back(pq.top().first);
    }

    return ans;
}

int main(){
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;

    vector<int> result = maxSlidingWindow(nums,k);

    for(int x : result){
        cout << x << " ";
    }

    return 0;
}