// ex array hain [1,2,3]
// or usme hume subarray ranges ka sum nikalna hain
// subarrays : [1] -> max - min = 0
//             [2] -> max - min = 0
//             [3] -> max - min = 0
//             [1,2] -> max - min = 2 - 1 = 1
//             [2,3] -> max - min = 3 - 2 = 1
//             [1,2,3] -> max - min = 3 - 1 = 2
// total sum = 0 + 0 + 0 + 1 + 1 + 2 = 4

#include <bits/stdc++.h>
using namespace std;

// brute force approach 
int subArrayRangeSum(vector<int>& arr){
    int n = arr.size();
    long long totalSum = 0;
    for(int i=0;i<n;i++){
        int curMax=arr[i];
        int curMin=arr[i];
        for(int j=i;j<n;j++){
            curMax = max(curMax, arr[j]);
            curMin = min(curMin, arr[j]);
            totalSum += (curMax - curMin);
        }
    }
    return totalSum;
}


//  Method 2:
// toh hum ise ayese bh dehk sakte hain:
// ans = (sum of subarray maximums) - (sum of subarray minimums)
// toh hume do cheeze nikalni hain:
// 1. sum of subarray maximums
// 2. sum of subarray minimums
// fir un dono ka difference nikal dena hain
// dono cheeze hum monotonic stack se nikal sakte hain
// jo ki humne pichle question me kiya hain 


// 1. sum of subarray maximums
void findPGE(vector<int> &arr, vector<int>& left){
    int n = arr.size();
    stack<int> s;

    for(int i=0;i<n;i++){
        while(!s.empty() && arr[s.top()] < arr[i]){
            s.pop();
        }
        if(s.empty()){
            left[i] = -1;
        }else{
            left[i] = s.top();
        }
        s.push(i);
    }
}

void findNGE(vector<int> &arr, vector<int>& right){
    int n = arr.size();
    stack<int> s;

    for(int i=n-1;i>=0;i--){
        while(!s.empty() && arr[s.top()] <= arr[i]){
            s.pop();
        }
        if(s.empty()){
            right[i] = n;
        }else{
            right[i] = s.top();
        }
        s.push(i);
    }
}

int subArrayMaxSum(vector<int>& arr){
    int n = arr.size();
    vector<int> left(n), right(n);
    findPGE(arr, left);
    findNGE(arr, right);

    long long totalSum = 0;
    for(int i=0;i<n;i++){
        int countLeft = i - left[i];
        int countRight = right[i] - i;
        long long contribution = (long long)arr[i] * countLeft * countRight;
        totalSum += contribution;
    }
    return totalSum;
}

// 2. sum of subarray minimums

void findPSE(vector<int>& arr, vector<int>& left){
    int n = arr.size();
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()] > arr[i]){
            st.pop();
        }
        if(st.empty()){
            left[i] = -1;
        }else{
            left[i] = st.top();
        }
        st.push(i);
    }
}

void findNSE(vector<int>& arr, vector<int>& right){
    int n = arr.size();
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }
        if(st.empty()){
            right[i] = n;
        }else{
            right[i] = st.top();
        }
        st.push(i);
    }
}

int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    vector<int> left(n), right(n);
    findPSE(arr, left);
    findNSE(arr, right);

    int mod = 1e9 + 7;
    int totalSum = 0;
    for(int i=0;i<n;i++){
        int countLeft = i - left[i];
        int countRight = right[i] - i;
        long long contribution = (long long)arr[i] * countLeft * countRight;
        totalSum = (totalSum + contribution) % mod;
    }
    return totalSum;
}

// final function to get sum of subarray ranges
int subArrayRangeSum(vector<int>& arr){
    long long maxSum = subArrayMaxSum(arr);
    long long minSum = sumSubarrayMins(arr);
    return maxSum - minSum;
}

int main(){
    return 0;
}