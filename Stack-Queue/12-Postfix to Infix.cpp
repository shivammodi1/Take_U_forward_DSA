#include<bits/stdc++.h>
using namespace std;

// postfix to infix conversion

string postfixToInfix(string s){
    stack<string>st;
    int n = s.length();
    int i=0;
    while(i<n){
        char ch = s[i];
        if(ch>='a' && ch<='z' || ch>='A' && ch<='Z' || ch>='0' && ch<='9'){
            st.push(string(1, ch));
        }
            // pop last two and add in-between that operand that push it
            string second = st.top();
            st.pop();
            string first = st.top();
            st.pop();
            string ans = "("+first+ch+second+")";
            st.push(ans);
        
        i++;
    }
    return st.top();
}

int main(){

}