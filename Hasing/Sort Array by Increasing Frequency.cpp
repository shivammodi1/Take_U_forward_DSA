#include <bits/stdc++.h>
using namespace std;

// Iss question me hame freq ke according sort krna h
// Jiski freq kam h wo pehle aayegi 
// agar freq same h to jo chota h wo pehle aayega

/*
 ______________________________
|                              | -> [&] (int a,int b){ return expression; }
|    Using Lambda Function :   | -> [&] ( parameters ){ return expression; }
|______________________________| -> Using Lambda function we can create an anonymous function.
-> Using this we can sort the vector according to our need.   
*/
vector<int> frequencySort(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        // Using lambda function
        sort(nums.begin(),nums.end(),[&](int a,int b){
            if(mp[a]!=mp[b]){
                // agar freq same nhi toh jiska freq kam h woh phale aayega
                return mp[a] < mp[b];
            }
            return a>b; // freq same h toh bada number phale aayega
        });
        return nums;
    }

int main()
{
    return 0;
}