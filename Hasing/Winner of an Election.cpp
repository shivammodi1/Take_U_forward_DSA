#include<bits/stdc++.h>
using namespace std;


// winner of an election
// whose name is lexicographically smaller in case of tie and the number of votes received by the winner
// mtlb jiska naam sabse jayda baar ho and agar same votes h toh jiska naam ka length chota hoga yaani lexicographically smaller hoga wo winner hoga

// https://practice.geeksforgeeks.org/problems/winner-of-an-election/0

class Solution {
  public:

    // Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[], int n) {
        // Your code here
        
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        
        int maxVotes=INT_MIN;
        string winner="";
        for(auto it:mp){
            if(it.second > maxVotes){
                maxVotes=it.second;
                winner = it.first;
            }
             else if(it.second == maxVotes){
                if(it.first < winner){
                    winner = it.first;
                }
            }
        }
        return {winner,to_string(maxVotes)};
    }
};