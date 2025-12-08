#include<bits/stdc++.h>
using namespace std;

// check if a string is palindrome using recursion
bool isPalindrome(string s,int st,int end){
    if(st>=end){
        return true;
    }

    if(s[st]!=s[end]){
        return false;
    }
    return isPalindrome(s,st+1,end-1);
}


int main(){
    string s = "racecar";
    int n = s.length();
    if(isPalindrome(s, 0, n-1)){
        cout << s << " is a palindrome." << endl;
    } else {
        cout << s << " is not a palindrome." << endl;
    }
    return 0;
}