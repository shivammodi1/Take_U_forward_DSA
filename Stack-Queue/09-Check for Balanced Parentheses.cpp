#include<bits/stdc++.h>
using namespace std;

bool isBalanced(string& s){
    stack<char>st;
    int n=s.length();
    for(int i=0;i<n;i++){
        char ch = s[i];
        if(ch=='(' || ch=='{' || ch=='['){
            st.push(ch);
        }else{
            if(st.size()==0){
                return false;
            }
            char top = st.top();
            if(ch==')' && top=='('){
                st.pop();
            }else if(ch=='}' && top=='{'){
                st.pop();
            }else if(ch==']' && top=='['){
                st.pop();
            }else{
                return false;
            }
        }
    }
    if(st.size() == 0){
        return true;
    }
    return false;
}

int main(){
    string s;
    cin>>s;
    if(isBalanced(s)){
        cout<<"Balanced"<<endl;
    }else{
        cout<<"Not Balanced"<<endl;
    }
    return 0;
}