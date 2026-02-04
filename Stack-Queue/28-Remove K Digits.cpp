#include<bits/stdc++.h>
using namespace std;


string removeKdigits(string num,int k){
    int n=num.size();
    if(k>=n){
        return "0";
    }
    stack<char> st;
    for(int i=0;i<n;i++){
        if(st.empty()){
            st.push(num[i]);
        }else{
            while(!st.empty() && k>0 && st.top()>num[i]){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
    }
    while(k>0 && !st.empty()){
        st.pop();
        k--;
    }
    string ans = "";
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    int i=0;
    while(i<ans.size() && ans[i]=='0'){
        i++;
    }
    string finalAns = ans.substr(i);
    return finalAns==""?"0":finalAns;
}

int main(){
    return 0;
}

