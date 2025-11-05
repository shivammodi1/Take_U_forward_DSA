// Koko can only eat from one pile per hour.
// Your task is to find the minimum value of s (bananas per hour) such that Koko can finish all the piles within k hours.
// Examples:
// Input: arr[] = [5, 10, 3], k = 4
// Output: 5
// Explanation: If Koko eats at the rate of 5 bananas per hour:
// First pile of 5 bananas will be finished in 1 hour.
// Second pile of 10 bananas will be finished in 2 hours.
// Third pile of 3 bananas will be finished in 1 hours.
// Therefore, Koko can finish all piles of bananas in 1 + 2 + 1 = 4 hours.


#include<bits/stdc++.h>
using namespace std;

int kokoEat(vector<int>& arr, int k){
     int n=arr.size();
     int st=0;
     int end=*max_element(arr.begin(),arr.end());
     int ans;
     int sum=0;
     // calculating sum 
     for(int i=0;i<n;i++){
        sum = sum + arr[i];
     }
    st = sum / k;
    if(!st){
        st=1;
    }
    while(st<=end){
        int mid = st + (end-st)/2;

        int time=0;
        for(int i=0;i<n;i++){
            time = time + (arr[i]/mid);
            // for ceil value
            if(arr[i]%mid){
                time++;
            }
        }
        // if calculated time > than given time that means increase the eating rate
        if(time>k){
            st=mid+1;
        }else{
            // possible ans store krlo and try to find better ans
            ans=mid;
            end=mid-1;
        }

    }
    return ans;
}

int main(){

}