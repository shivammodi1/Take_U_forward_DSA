#include<bits/stdc++.h>
using namespace std;

int precedence(char ch){
    if(ch == '^') return 3;
    if(ch == '*' || ch == '/') return 2;
    if(ch == '+' || ch == '-') return 1;
    return -1;
}

// Function to convert infix expression to postfix expression
// Time Complexity: O(N)
// Space Complexity: O(N)

// example:
// Input:  a*(b+c)/d
// Output: abc+*d/

string infixToPostfix(string s){
    stack<char> st;
    string result;
    int i = 0;

    while(i < s.length()){
        char ch = s[i];
        // If the character is an operand, add it to output
        if((ch >= 'a' && ch <= 'z') ||
           (ch >= 'A' && ch <= 'Z') ||
           (ch >= '0' && ch <= '9')){
            result += ch;
        }
        else if(ch == '('){
            st.push(ch);
        }
        else if(ch == ')'){
            while(!st.empty() && st.top() != '('){
                result += st.top();
                st.pop();
            }
            st.pop(); // pop the '(' from the stack
        }
        else{
            // operator encountered
            while(!st.empty() &&
                 (precedence(st.top()) > precedence(ch) ||
                 (precedence(st.top()) == precedence(ch) && ch != '^'))){
                result += st.top();
                st.pop();
            }
            st.push(ch);
        }
        i++;
    }

    while(!st.empty()){
        result += st.top();
        st.pop();
    }
    return result;
}

int main(){
    string s = "a*(b+c)/d";
    cout << infixToPostfix(s);
}
