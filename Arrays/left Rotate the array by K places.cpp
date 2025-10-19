#include <bits/stdc++.h>
using namespace std;

// method 1
vector<int> Rotate(vector<int>& arr, int n, int k) {
    vector<int> ans;

    if (n == 0) return {}; // return empty vector
    k = k % n; // in case k > n
    if (k == 0) return arr; // no rotation needed

    for (int i = k; i < n; i++) {
        ans.push_back(arr[i]);
    }
    for (int i = 0; i < k; i++) {
        ans.push_back(arr[i]);
    }
    return ans;
}

// method 2
// using reverse 
// [1,2,3,4,5,6] k=2
// reverse(arr,arr+k); [2,1,3,4,5,6]
// reverse(arr+k,arr+n); [2,1,6,5,4,3]
// reverse(arr,arr+n); [3,4,5,6,1,2]
void rotate(vector<int>&arr,int n,int k){
     if (n == 0) return; // return empty vector
    k = k % n; // in case k > n
    if (k == 0) return; // no rotation needed

    reverse(arr.begin(),arr.begin()+k);
    reverse(arr.begin()+k,arr.end());
    reverse(arr.begin(),arr.end());


}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n); // ✅ allocate space for n elements
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> rotated = Rotate(arr, n, k);

    cout << "Rotated array: ";
    for (int x : rotated) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
