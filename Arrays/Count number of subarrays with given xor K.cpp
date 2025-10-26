
#include <bits/stdc++.h>
using namespace std;

//Time-Complexity -> O(n)
class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        int count=0;
        int Xor = 0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            Xor = Xor ^ arr[i];
            if(Xor==k){
                count++;
            }
            if(mp.find(Xor ^ k) != mp.end()){
                count += mp[Xor^k];
            }
            //storing Xor and there count
            mp[Xor]++;
        }
        return count;
    }
};

//Time-Complexity -> O(n^2)
class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        int count=0;
        for(int i=0;i<n;i++){
            int Xor = 0;
            for(int j=i;j<n;j++){
                Xor = Xor ^ arr[j];
                if(Xor==k){
                    count++;
                }
            }
        }
        return count;
    }
};