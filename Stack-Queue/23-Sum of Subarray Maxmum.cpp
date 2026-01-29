#include<bits/stdc++.h>
using namespace std;

// arr = [3,1,2,4]
// subarrays = [3], [3,1], [3,1,2], [3,1,2,4], [1], [1,2], [1,2,4], [2], [2,4], [4]
// subarray maximums = 3 + 3 + 3 + 4 + 1 + 2 + 4 + 2 + 4 + 4
// = 3 + 3 + 3 + 4 + 1 + 2 + 4 + 2 + 4 + 4 = 26

// brute force approach
int subArrayMaxSum(vector<int>& arr){
    int n=arr.size();
    long long totalSum=0;
    for(int i=0;i<n;i++){
        int currMax = 0;
        for(int i=i;j<n;j++){
            currMax = max(currMax, arr[j]);
            totalSum += currMax;
        }
    }
    return totalSum;
}

// Optimized Approach using Monotonic Stack
// Problem: Sum of Subarray Maximums
/*
Brute force O(n^2) hota hai, isliye hum O(n) optimized approach use karte hain.
Core Idea:
Hume har subarray ka maximum element nikal kar unka sum find karna hai.
Suffix:
1. Har element ke liye, hum uske left aur right me next greater element find
    karenge using Monotonic Stack.
2. Fir har element ka contribution calculate karenge as maximum in subarrays.
3. Finally, un contributions ka sum return karenge.
*/

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
    

int main(){
    return 0;
}