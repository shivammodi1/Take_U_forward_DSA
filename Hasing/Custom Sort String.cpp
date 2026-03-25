// same question as relative sorting but here we have to sort the string according to the order of another string
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string customSortString(string o, string s) {
        int n=o.size();
        int m=s.size();

        // phale s ko frequency map me daalenge
        unordered_map<char,int>mp;
        for(int i=0;i<m;i++){
            char ch = s[i];
            mp[ch]++;
        }

        // phir o ke according ans me daalenge
        string ans="";
        for(int i=0;i<n;i++){
            char ch=o[i];
            // o ke char ko mp me find kr kr uski frequency ke according ans me daalenge
            if(mp.find(ch)!=mp.end()){
                int c = mp[ch];
                while(c--){
                    ans+=ch;
                }
                mp.erase(ch); // erase kr denge taki duplicates na aaye
            }
        }

        /// ab o ke char ke baad jo bhi char bache hai unko ans me daal denge
        for(int i=0;i<m;i++){
            char ch=s[i];
            if(mp.find(ch)!=mp.end()){
                int c = mp[ch];
                while(c--){
                    ans+=ch;
                }
                mp.erase(ch); // erase kr denge taki duplicates na aaye
            }
        }

        return ans;

    }
};