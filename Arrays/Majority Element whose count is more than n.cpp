#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return arr[0];

        // Create vector of size max_element + 1
        int maxVal = *max_element(arr.begin(), arr.end());
        vector<int> count(maxVal + 1, 0); // Allocate enough space

        for(int i = 0; i < n; i++) {
            count[arr[i]]++; // Safe now
        }

        for(int i = 0; i <= maxVal; i++) {
            if(count[i] > n/2) {
                return i;
            }
        }

        return -1;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    Solution sol;
    cout << sol.majorityElement(arr) << endl;
    return 0;
}
