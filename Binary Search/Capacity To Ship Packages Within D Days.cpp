#include<bits/stdc++.h>
using namespace std;

// A conveyor belt has packages that must be shipped from one port to another within days days.
// The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.
// Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.
// Example 1:
// Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
// Output: 15
// Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
// 1st day: 1, 2, 3, 4, 5
// 2nd day: 6, 7
// 3rd day: 8
// 4th day: 9
// 5th day: 10
// Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.

// User function Template for C++

class Solution {
  public:
    int leastWeightCapacity(int arr[], int n, int d) {
        // code here
        int st,end=0;
        //min weight of ship should max element in array
        st = *max_element(arr, arr + n);
        //max weight of ship should sum of all element in array
        for(int i=0;i<n;i++){
            end += arr[i];
        }
        
        int ans = end;  // initialize answer with max possible
        
        while(st<=end){
            int mid = st+(end-st)/2;
            
            int sum=0,day=1;int days = 1;  // at least 1 day required
            for(int i=0;i<n;i++){
                sum += arr[i];
                
                if(sum>mid){
                    day++;
                    sum=arr[i];
                }
            }
            
            if(day<=d){
                ans=mid;
                end=mid-1;
            }else{
                st=mid+1;
            }
        }
        return ans;
    }
};

int main(){

}