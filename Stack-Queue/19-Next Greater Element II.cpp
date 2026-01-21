#include <bits/stdc++.h>
using namespace std;


// Now here is array is in circular form
vector<int> nextGreaterElements(vector<int> &nums)
{
    stack<int>st;
    int n=nums.size();
    vector<int>ans(n,-1);
    for(int i=2*n-1;i>=0;i--){
        int index = i%n; // to simulate circular array
        if(st.empty()){
            // if stack is empty just push the element
            st.push(nums[index]);
        }else{
            // there is some element in stack
            // agar top element jab tak chota hoga tab tak pop karte jao
            while(!st.empty() && st.top()<=nums[index]){
                st.pop();
            }
            // now check if stack is empty or not than assign the value
            if(!st.empty()){
                ans[index]=st.top();
            }
            // store only next greater elements in stack
            st.push(nums[index]);
        }
    }
    return ans;
}

int main()
{
    return 0;
}