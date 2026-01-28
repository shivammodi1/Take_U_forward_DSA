// So basically in question we have given an array representing heights of bars
// And hame find krna hain ki kitna pani trap hoga un bars ke bich me jab baarish hoti hain

// Approach:
// 1. toh phale hum left se max height nikaal lenge har index ke liye
// 2. phir right se max height nikaal lenge har index ke liye
// 3. Abb hum har index par check karege ki us index par kitna pani trap hoga
//    jo ki hoga min(leftMax, rightMax) - height[i]
// 4. Aur isse hum total pani me add karte jayenge

#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int maxWater(vector<int>& H){
    int n = H.size();

    vector<int> leftMax(n);
    vector<int> rightMax(n);

    // left max 
    leftMax[0]=0 ;// first element
    for(int i=1;i<n;i++){
        int lm = max(leftMax[i-1],H[i-1]);
        leftMax[i] = lm;
    }
    // right max
    rightMax[n-1]=0; // last element
    for(int i=n-2;i>=0;i--){
        int rm = max(rightMax[i+1],H[i+1]);
        rightMax[i] = rm;
    }
    int totalWater = 0;
    for(int i=0;i<n;i++){
        int minHeight = min(leftMax[i], rightMax[i]);
        if(minHeight > H[i]){
            totalWater += minHeight - H[i];
        }
    }
    return totalWater;
}
};