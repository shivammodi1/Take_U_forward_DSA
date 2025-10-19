#include<bits/stdc++.h>
using namespace std;
   // containing n disticnt number
int findMissing(vector<int>& arr){
    int n = arr.size();
    int ans = n;
    for(int i=0;i<n;i++){
        if(arr[i]!=i+1){
            ans=i+1;
            return ans;
        }
    }
    return ans;
}


int MissingNum(vector<int>& arr) {
    int n = arr.size();
    vector<int> count(n + 2, 0);  // +2 to safely cover up to n+1

    for (int i = 0; i < n; i++) {
        if (arr[i] <= n + 1 && arr[i] >= 1)
            count[arr[i]] = 1; // mark presence
    }

    for (int i = 1; i <= n + 1; i++) {
        if (count[i] == 0)
            return i;  // found the missing number
    }

    return -1; // just in case (should never reach here)
}

// method 3
// sum of n natural number = n(n+1)/2 
// missing num = sum of n natural numbers - total in array
int missingNum(vector<int>&arr){
    int n = arr.size();
    int nSum = n*(n+1)/2;
    int tSum = 0;
    for(int i=0;i<n;i++){
        tSum+=arr[i];
    }
    int miss_num = nSum - tSum;
    return miss_num;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << MissingNum(arr);
    return 0;
}
