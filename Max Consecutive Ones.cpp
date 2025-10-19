#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums)
{
    int count1 = 0, maxCount1 = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 1) {
            count1++;
            maxCount1 = max(count1, maxCount1);
        } else {
            count1 = 0;
        }
    }
    return maxCount1;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << findMaxConsecutiveOnes(nums);
}
