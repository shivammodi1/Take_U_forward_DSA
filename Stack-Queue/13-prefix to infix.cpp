#include<bits/stdc++.h>
using namespace std;

// prefix to infix conversion
// example: +AB to (A+B)

string preficToInfix(string s)
{
    // start from right end of prefix expression
    // if operand push to stack
    // if operator pop two operands from stack
    // concatenate them in order (operand1 operator operand2)
    // push the result back to stack
    
    stack<string> st;
    int n = s.length();
    int i=n-1;
    while(i>=0){
        char ch = s[i];
        if(ch>='A' && ch<='Z' || ch>='a' && ch<='z' || ch>='0' && ch<='9'){
            st.push(string(1,ch));
        }else{
            string first = st.top(); st.pop();
            string second = st.top(); st.pop();
            string ans = "("+first+ch+second+")";
            st.push(ans);
        }
        i--;
    }
    return st.top();
}

int main(){
    return ;
}