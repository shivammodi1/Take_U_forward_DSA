#include <bits/stdc++.h>
using namespace std;

//method 1 using two freq vector for + and - both
vector<int> findMajority(vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
        return {-1};

    int maxiPos = 0, maxiNeg = 0;

    // Find maximum positive and maximum absolute negative number
    for (int x : arr)
    {
        if (x >= 0)
            maxiPos = max(maxiPos, x);
        else
            maxiNeg = max(maxiNeg, abs(x));
    }

    vector<int> pos(maxiPos + 1, 0);
    vector<int> neg(maxiNeg + 1, 0);

    // Build frequency arrays
    for (int x : arr)
    {
        if (x >= 0)
            pos[x]++;
        else
            neg[abs(x)]++;
    }

    vector<int> ans;

    // Check positive candidates
    for (int i = 0; i <= maxiPos; i++)
    {
        if (pos[i] > n / 3)
        {
            ans.push_back(i);
        }
    }

    // Check negative candidates
    for (int i = 1; i <= maxiNeg; i++)
    {
        if (neg[i] > n / 3)
        {
            ans.push_back(-i);
        }
    }

    if (ans.empty())
        return {};
    return ans;
}


// method 2
// using mao
// storing element and thri occurence

vector<int> findMajority(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> freq;
        
        for(int i = 0; i < n; i++){
            freq[arr[i]]++;
        }
        
        vector<int> ans;
        for(auto &p : freq){
            if(p.second > n / 3){
                ans.push_back(p.first);
            }
        }
        
        if(ans.empty()) return {};
        sort(ans.begin(),ans.end());
        return ans;
    }