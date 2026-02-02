#include<bits/stdc++.h>
using namespace std;
void PSElement(vector<int> &arr,vector<int> &P){
    stack<int>st;
    int n=arr.size();

    for(int i=0;i<n;i++){
        if(st.empty()){
            st.push(i);
        }else{
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(!st.empty()){
                P[i]=st.top();
            }

            st.push(i);
        }
    }
}

void NSElement(vector<int> &arr,vector<int> &N){
    stack<int>st;
    int n=arr.size();

    for(int i=n-1;i>=0;i--){
        if(st.empty()){
            st.push(i);
        }else{
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            if(!st.empty()){
                N[i]=st.top();
            }

            st.push(i);
        }
    }
}

int getMaxArea(vector<int> &arr){
    int n=arr.size();
    vector<int>PSE(n,-1);
    vector<int>NSE(n,n);

    PSElement(arr,PSE);
    NSElement(arr,NSE);

    int maxArea = 0;

    for(int i=0;i<n;i++){
        int area = arr[i] * (NSE[i] - PSE[i] -1);
        maxArea = max(maxArea,area);
    }
    return maxArea;
    
}

int main(){
    return 0;
}