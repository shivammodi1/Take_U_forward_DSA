#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void Generate(int row, vector<vector<int>>& ans) {
        vector<int> res;
        int a = 1;
        res.push_back(a);
        // i represents column index
        for (int i = 1; i <= row; i++) { // include all elements in the row
            a = a * (row - i + 1) / i;   // nCr formula works for 0-based row
            res.push_back(a);
        }
        ans.push_back(res);
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 0; i < numRows; i++) { // 0-based row indexing
            Generate(i, ans);
        }
        return ans;
    }
};
