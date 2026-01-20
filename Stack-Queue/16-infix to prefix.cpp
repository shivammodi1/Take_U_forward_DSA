#include<bits/stdc++.h>
using namespace std;


int precedence(char op) {
    if(op == '+'|| op == '-') return 1;
    if(op == '*'|| op == '/') return 2;
    if(op == '^') return 3;
    return 0;
}

string infixToprefix(string s){
    // reverse the infix expression
    // swap ( and )
    // do like infix to postfix
    // reverse the result
    reverse(s.begin(), s.end());
    for(int i=0; i<s.length(); i++){
        if(s[i] == '(') s[i] = ')';
        else if(s[i] == ')') s[i] = '(';
    }
    stack<char> st;
    string result = "";
    for(int i=0; i<s.length(); i++){
        char c = s[i];
        if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')){
            result += c;
        }
        else if(c == '('){
            st.push(c);
        }
        else if(c == ')'){
            while(!st.empty() && st.top() != '('){
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && precedence(st.top()) > precedence(c)){
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty()){
        result += st.top();
        st.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}