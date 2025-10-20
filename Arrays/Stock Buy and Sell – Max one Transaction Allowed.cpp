#include <bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int> &p)
{
    // code here
    int maxPro = 0;
    int minEle = INT_MAX;
    for (int i = 0; i < p.size(); i++)
    {
        // min element 
        minEle = min(minEle, p[i]);
        //calculating cost 
        int cost = p[i] - minEle;
        //find max profit
        maxPro = max(maxPro, cost);
    }
    return maxPro;
}
