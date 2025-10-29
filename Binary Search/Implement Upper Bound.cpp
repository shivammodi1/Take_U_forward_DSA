// upperBound -> greatest index such that arr[mid] <= target

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int upperBound(vector<int>& arr, int target) {
        int n = arr.size();
        int st = 0, end = n - 1, ans = n;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (arr[mid] > target) {
                ans = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return ans;
    }
};

int main(){

}