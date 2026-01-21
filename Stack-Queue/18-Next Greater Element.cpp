#include<bits/stdc++.h>
using namespace std;

vector<int> nextLargerElement(vector<int>& arr){
    stack<int> s;
    vector<int> res(arr.size(), -1);
    int n = arr.size();
    for(int i=n-1;i>=0;i--){
        if(s.empty()){
            s.push(arr[i]);
        }else{
            while(!s.empty() && s.top() <= arr[i]){
                s.pop();
            }
            if(!s.empty()){
                res[i] = s.top();
            }
            s.push(arr[i]);
        }
    }
    
    return res;
}




int main(){
    vector<int> arr = {4,5,2,25};
    vector<int> result = nextLargerElement(arr);
    for(int val : result){
        cout << val << " ";
    }
    return 0;
}