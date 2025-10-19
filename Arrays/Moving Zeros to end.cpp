#include <bits/stdc++.h>
using namespace std;

// method 1
//TL -> O(n)
//SC -> O(n)
void moveZeroes(vector<int> &nums) {
    vector<int> tmp;
    int n = nums.size();

    // Copy all non-zero elements into tmp
    for (int i = 0; i < n; i++) {
        if (nums[i] != 0) {
            tmp.push_back(nums[i]);
        }
    }

    int k = tmp.size();

    // Copy non-zero elements back
    for (int i = 0; i < k; i++) {
        nums[i] = tmp[i];
    }

    // Fill the rest with zeroes
    for (int i = k; i < n; i++) {
        nums[i] = 0;
    }
}

// method 2
// TL->O(n)
// SC -> O(1);
void movezeroes(vector<int>&arr,int n){
    int j=-1;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            j=i;
            break;
        }
    }

    for(int i=j+1;i<n;i++){
        if(arr[i]!=0){
            swap(arr[i],arr[j]);
            j++;
        }
    }
}


int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // moveZeroes(arr);
    movezeroes(arr,n);

    cout << "After moving zeroes: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
