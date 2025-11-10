// Given two strings s and t, return true if t is an anagram of s, and false otherwise.
// Example 1:
// Input: s = "anagram", t = "nagaram"
// Output: true

// Example 2:
// Input: s = "rat", t = "car"
// Output: false

#include<bits/stdc++.h>
using namespace std;

// method 1
// by creating 2 frequency vector where we will store the freq of character at there ASCII index
// if any index if is there any diffrence in freq then return false else at last return true

// time complexity : O(n)
// space complexity : O(1)
// but since we are using extra space of 2 frequency vector of size 256 so space complexity is O(256) which is constant space
bool validAnagram(string s,string t){
    if(s.size() != t.size()){
        return false;
    }

    vector<int>countS(256,0);
    vector<int>countT(256,0);

    for(int i=0;i<s.size();i++){
        countS[s[i]]++;
        countT[t[i]]++;
    }

    for(int i=0;i<256;i++){
        if(countS[i] != countT[i]){
            return false;
        }
    }

    return true;
}

// method 2
// using single frequency vector
// time complexity : O(n)
// space complexity : O(1)
bool validAnagramSingleFreq(string s,string t){
    if(s.size() != t.size()){
        return false;
    }

    vector<int>count(256,0);

    for(int i=0;i<s.size();i++){
        count[s[i]]++; // inc the freq
        count[t[i]]--; // at the same place dec the freq
    }

    // in freq vector if any index is not 0 then return false
    for(int i=0;i<256;i++){
        if(count[i] != 0){
            return false;
        }
    }

    return true;
}


int main(){
    string s = "anagram";
    string t = "nagaram";
    if(validAnagram(s,t)){
        cout<<"Valid Anagram"<<endl;
    }else{
        cout<<"Not a Valid Anagram"<<endl;
    }
    return 0;
}