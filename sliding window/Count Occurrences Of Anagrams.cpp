#include<bits/stdc++.h>
using namespace std;

/*
| Count Occurrences Of Anagrams
| 2 string given hogi, s and p and hume p ke anagrams ko s me count karna hai.
| Example: s = "forxxorfxdofr", p = "for"
| Output: 3
| Explanation: "for", "orf" and "ofr" are the anagrams of p in s.
*/

/*
* Method 1: Brute Force
* Using hash map + sorting 
* 1. sort the pattern string and store it in a variable, because anagrams will be same after sorting.
* 2. Now we will traverse the string s and for every substring of length equal to pattern string, we will sort it and compare it with the sorted pattern string.
* 3. If they are same then we will increment the count.
* Time Complexity: O(n*m*log(m)) where n is the length of string s and m is the length of pattern string p.
* Space Complexity: O(m) for storing the sorted pattern string.
*/

/*
* Method 2: Sliding Window + Hash Map
* 1. We will create 2 vectors of 26 size to store the frequency of characters in pattern string and current window of string s.
* 2. Phale hum vector<int> freP(26,0) me pattern string ke characters ki frequency store karenge.
* 3. Ab hum string s me sliding window technique use karenge.
* 4. Add current element of s put into freW -> freW[s[i]-'a']++
* 5. agar i>=size of pattern string , toh left se remove karo -> freW[s[i-m]-'a']--
* 6. Har step pe check karo ki freP and freW same hai ya nahi, agar same hai toh count++.
* Time Complexity: O(n) where n is the length of string s.
* Space Complexity: O(1) because we are using fixed size vectors of 26.
*/

// User function template for C++
class Solution {
  public:
    int search(string &pat, string &txt) {
        // code here
        int n=txt.size();
        int m=pat.size();
        // int c=0;
        // sort(pat.begin(),pat.end());
        // for(int i=0;i<=n-m;i++){
        //     string s = txt.substr(i,m);
        //     sort(s.begin(),s.end());
        //     if(s==pat){
        //         c++;
        //     }
        // }
        // return c;
        
        vector<int>p(26,0); // for pattern
        vector<int>w(26,0); // for current window
        int count=0;
        for(char c:pat){
            p[c-'a']++;
        }
        
        for(int i=0;i<n;i++){
            w[txt[i]-'a']++;
            
            if(i>=m){
                w[txt[i-m]-'a']--;
            }
            
            if(p==w){
                count++;
            }
        }
        
        return count;
    }
};