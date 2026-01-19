#include<bits/stdc++.h>
using namespace std;

// Function to convert postfix expression to prefix expression
string postfixToPrefix(string postfix){
    stack<string> s;
    for(char ch : postfix){
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')){
            s.push(string(1, ch));
        } else {
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();
            string temp = ch + op2 + op1;
            s.push(temp);
        }
    }
    return s.top();
}

int main(){
    return 0;
}