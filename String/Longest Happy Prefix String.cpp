// A string is called a happy prefix if is a non-empty prefix which is also a suffix (excluding itself).
// Given a string s, return the longest happy prefix of s. Return an empty string "" if no such prefix exists.

// Example 1:
// Input: s = "level"
// Output: "l"
// Explanation: s contains 4 prefix excluding itself ("l", "le", "lev", "leve"), and suffix ("l", "el", "vel", "evel"). The largest prefix which is also suffix is given by "l".

// Example 2:
// Input: s = "ababab"
// Output: "abab"
// Explanation: "abab" is the largest prefix which is also suffix. They can overlap in the original string.

#include<bits/stdc++.h>
using namespace std;

// brute force approach
string longestHappyPrefix(string s){
    unordered_map<string,int>s1;
        int n=s.size();
        for(int i=0;i<n-1;i++){
            string sub = s.substr(0,i+1);
            s1[sub]=sub.length();
        }

        
        int ans=0;
        string res="";
        string sub="";
        for(int i=n-1;i>0;i--){
            sub += s[i];
            string tmp=sub;
            reverse(tmp.begin(),tmp.end());

            if(s1.find(tmp)!=s1.end() && ans<s1[tmp]){
                ans=s1[tmp];
                res=tmp;
            }

        }
        return res;
}

// efficient approach using KMP algorithm
string longestHappyPrefix(string s){
    int n=s.size();
    vector<int>lps(n,0);
    
    int len=0;
    int i=1;
    while(i<n){
        if(s[i]==s[len]){
            len++;
            lps[i]=len;
            i++;
        }else{
            if(len!=0){
                len=lps[len-1];
            }else{
                lps[i]=0;
                i++;
            }
        }
    }
    int length = lps[n-1];
    return s.substr(0, length);
}