// Given a positive integer n, find the square root of n. If n is not a perfect square, then return the floor value.

// Floor value of any number is the greatest Integer which is less than or equal to that number.

// Examples:

// Input: n = 4
// Output: 2
// Explanation: Since, 4 is a perfect square, so its square root is 2.

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int floorSqrt(int n) {
        // code here
        // return sqrt(n);
        if(n<2){
            return n;
        }
        
        int st = 0;
        int end = n;
        int ans;
        while(st<=end){
            int mid = st+(end-st)/2;
            // To avoid mid*mid overflow, we use n/mid
            // Compare mid with n/mid instead of mid*mid with n
            if(mid == n/mid){
                return mid;
            }else if(mid > n/mid){
                // mid*mid > n than move to left side beacuse we need floor value
                end=mid-1;
            }else{
                // mid*mid < n than move to right side
                ans=mid;
                st=mid+1;
            }
        }
        return ans;
    }
};