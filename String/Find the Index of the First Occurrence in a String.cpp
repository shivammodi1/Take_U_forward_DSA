// Example 1:
// Input: s1 = "sadbutsad", s2 = "sad"
// Output: 0
// Explanation: "sad" occurs at index 0 and 6.
// The first occurrence is at index 0, so we return 0.

// Example 2:
// Input: s1 = "leetcode", s2 = "leeto"
// Output: -1
// Explanation: "leeto" did not occur in "leetcode", so we return -1.
 
#include<bits/stdc++.h>
using namespace std;

int strStr(string s1, string s2) {
    // return s1.find(s2);

    //method 2
    int n1 = s1.size();
    int n2 = s2.size();
    for(int i=0;i<n1;i++){
        strin subS1 = s1.substr(i, n2);
        if(subS1 == s2){
            return i;
        }
    }
    return -1;
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;

    int index = s1.find(s2);
    cout << index << endl;

    return 0;
}