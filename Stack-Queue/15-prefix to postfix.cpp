#include<bits/stdc++.h>
using namespace std;

// Function to convert prefix expression to postfix expression
string prefixToPostfix(string prefix){
    stack<string> s;
    for(int i = prefix.length() - 1; i >= 0; i--){
        char ch = prefix[i];
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')){
            s.push(string(1, ch));
        } else {
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();
            string temp = op1 + op2 + ch;
            s.push(temp);
        }
    }
    return s.top();
}

int main(){
    return 0;
}