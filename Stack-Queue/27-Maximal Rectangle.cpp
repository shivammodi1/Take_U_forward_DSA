#include <bits/stdc++.h>
using namespace std;

// Function to calculate the maximum area of rectangle in a binary matrix
// by treating each row as the base of a histogram
// Utilizes the largest rectangle in histogram approach
// Time Complexity: O(rows * cols)
// Space Complexity: O(cols)
// Approach: For each row, update the histogram heights and calculate the maximum area

class Solution
{
public:
    void PSElement(vector<int> &arr, vector<int> &P)
    {
        stack<int> st;
        int n = arr.size();

        for (int i = 0; i < n; i++)
        {
            if (st.empty())
            {
                st.push(i);
            }
            else
            {
                while (!st.empty() && arr[st.top()] >= arr[i])
                {
                    st.pop();
                }
                if (!st.empty())
                {
                    P[i] = st.top();
                }

                st.push(i);
            }
        }
    }

    void NSElement(vector<int> &arr, vector<int> &N)
    {
        stack<int> st;
        int n = arr.size();

        for (int i = n - 1; i >= 0; i--)
        {
            if (st.empty())
            {
                st.push(i);
            }
            else
            {
                while (!st.empty() && arr[st.top()] > arr[i])
                {
                    st.pop();
                }
                if (!st.empty())
                {
                    N[i] = st.top();
                }

                st.push(i);
            }
        }
    }

    int getMaxArea(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> PSE(n, -1);
        vector<int> NSE(n, n);

        PSElement(arr, PSE);
        NSElement(arr, NSE);

        int maxArea = 0;

        for (int i = 0; i < n; i++)
        {
            int area = arr[i] * (NSE[i] - PSE[i] - 1);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }

    int maxArea(vector<vector<int>> &mat)
    {
        if (mat.empty() || mat[0].empty())
            return 0;

        int n = mat.size();
        int m = mat[0].size();
        int ans = 0;

        vector<int> H(m, 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 0)
                    H[j] = 0;
                else
                    H[j]++;
            }
            ans = max(ans, getMaxArea(H));
        }

        return ans;
    }
};