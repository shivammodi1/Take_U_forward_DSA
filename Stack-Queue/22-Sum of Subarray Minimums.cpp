//  toh iss question me hume ek array given hain
// hume us array ke sare subarray ke minimum element ka sum nikalna hain
// jaise ki agar array hain [3,1,2,4]
// [3]-> min is 3              [1]-> min is 1        [2]-> min is 2        [4]-> min is 4
// [3,1] -> min is 1           [1,2] -> min is 1     [2,4] -> min is 2
// [3,1,2] -> min is 1         [1,2,4] -> min is 1
// [3,1,2,4]-> min is 1
// in sabke minimum element ka sum nikalna hain
// 3 + 1 + 2 + 4 + 1 + 1 + 2 + 1 + 1 = 17

// class Solution {
// public:
//     int sumSubarrayMins(vector<int>& arr) {
//         int n = arr.size();
//         long long sum = 0;
//         int mod = 1000000007;

//         for(int i = 0; i < n; i++){
//             int mini = arr[i];
//             for(int j = i; j < n; j++){
//                 mini = min(mini, arr[j]);
//                 sum = (sum + mini) % mod;
//             }
//         }
//         return (int)sum;
//     }
// };


// Optimized Approach using Stack

void findPSE(vector<int>& arr, vector<int>& left){
    int n = arr.size();
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()] > arr[i]){
            st.pop();
        }
        if(st.empty()){
            left[i] = -1;
        }else{
            left[i] = st.top();
        }
        st.push(i);
    }
}

void findNSE(vector<int>& arr, vector<int>& right){
    int n = arr.size();
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }
        if(st.empty()){
            right[i] = n;
        }else{
            right[i] = st.top();
        }
        st.push(i);
    }
}

int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    vector<int> left(n), right(n);
    findPSE(arr, left);
    findNSE(arr, right);

    int mod = 1e9 + 7;
    int totalSum = 0;
    for(int i=0;i<n;i++){
        int countLeft = i - left[i];
        int countRight = right[i] - i;
        long long contribution = (long long)arr[i] * countLeft * countRight;
        totalSum = (totalSum + contribution) % mod;
    }
    return totalSum;
}

// Optimized Approach using Monotonic Stack
// Problem: Sum of Subarray Minimums

/*
LOGIC EXPLANATION:

Hume har subarray ka minimum element nikal kar unka sum find karna hai.
Brute force O(n^2) hota hai, isliye hum O(n) optimized approach use karte hain.

Core Idea:
Har element arr[i] ko individually consider karte hain aur yeh calculate karte hain
ki arr[i] kitne subarrays me minimum element ban sakta hai.
Phir uska contribution total sum me add kar dete hain.
*/

/*
Step 1: Previous Smaller Element (PSE)
-------------------------------------
left[i] = index of nearest element on the left of i
          jo arr[i] se strictly smaller ho.
Agar koi smaller element nahi mila, to left[i] = -1.

Iske liye monotonic increasing stack use ki jati hai.
*/

/*
Step 2: Next Smaller Element (NSE)
---------------------------------
right[i] = index of nearest element on the right of i
           jo arr[i] se smaller ya equal ho.
Agar koi smaller element nahi mila, to right[i] = n.

Yahan >= isliye use karte hain taaki duplicate elements ka
double counting na ho.
*/

/*
Step 3: Count subarrays jisme arr[i] minimum hoga
-------------------------------------------------
Agar current index i hai:

Left side choices  = i - left[i]
Right side choices = right[i] - i

Total subarrays = (i - left[i]) * (right[i] - i)
*/

/*
Step 4: Contribution of arr[i]
------------------------------
Har subarray me minimum value arr[i] hogi.

Contribution = arr[i] * (i - left[i]) * (right[i] - i)

Is contribution ko total sum me add kar dete hain.
*/

/*
Final Formula:
--------------
totalSum += arr[i] * (i - left[i]) * (right[i] - i)
(modulo 1e9 + 7)
*/

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
