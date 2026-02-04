#include<bits/stdc++.h>
using namespace std;

// so basically hum 1 array given h stocks ke jo stock price store kiye hain 
// hume batana hain ki kitne stock hai price current stock se kam or equal hain continously hone chahiye 
// and hume previous price dekhna hain current se.

// arr = [100,80,90,120]
// ans = [1,1,2,4];
// for 100-> no one is previous stock so 100 itself that is why 1
// for 80-> 80>=100-> false so stock 80 itself less or equal that is why 1
// for 90-> 90>=80-> true and 90>=100-> false so ans is 2 because 80,90
// for 120 -> all element is continuolsy is smaller and equal so ans 4


// Approach:
// 1. we will use stack to store the index of the stock price
// 2. toh hum stack me index store karenge and jab bhi current stock price se chota ya equal milega toh hum stack se pop karenge
// 3. jab bhi stack empty hoga toh ans[i] = i+1 because all previous stock price is less than or equal to current stock price
// 4. otherwise ans[i] = i - st.top() because st.top() will give the index of the previous greater stock price
// 5. finally push the current index into the stack
// 6. return the ans array

vector<int> stockSpan(vector<int> &arr){
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]<=arr[i]){
            st.pop();
        }
        ans[i] = st.empty() ? i+1 : i-st.top();
        st.push(i);
    }
    return ans;
}

int main(){
    return 0;
}