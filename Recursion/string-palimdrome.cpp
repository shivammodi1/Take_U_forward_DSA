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

// Recursion Tree
/*
                    isPalindrome(s,0,6)
                        /          \
               s[0]==s[6]?      false
                   /   \
         isPalindrome(s,1,5)
              /        \
        s[1]==s[5]?   false
            /   \
  isPalindrome(s,2,4)
       /        \
 s[2]==s[4]?   false
     /   \
isPalindrome(s,3,3)
        /      \
    true     false 
Base Case: st >= end  => true
*/


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