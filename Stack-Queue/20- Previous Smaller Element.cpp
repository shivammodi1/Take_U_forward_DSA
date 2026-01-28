//  Previous Smaller Element
#include<bits/stdc++.h>
using namespace std;

// Input: arr[] = [1, 6, 2]
// Output: [-1, 1, 1]

vector<int> prevSmaller(vector<int>& arr){
    stack<int> st;
    int n=arr.size();
    vector<int>ans(n,-1);
    for(int i=0;i<n;i++){
        if(st.empty()){
            st.push(arr[i]);
        }else{
            while(!st.empty() && st.top()>=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i]=st.top();
            }
            st.push(arr[i]);
        }
    }
    return ans;
}

int main(){
    return 0;
}