#include <bits/stdc++.h>
using namespace std;

// Method 1 
// T.C-> O(n^3)
//time limited exceeded
vector<vector<int>> threeSum(vector<int> &arr)
{
    set<vector<int>>st;
        int n=arr.size();
        
        
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    if(arr[i]+arr[j]+arr[k]==0){
                        vector<int>temp = {arr[i],arr[j],arr[k]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
        vector<vector<int>>res(st.begin(),st.end());
        return res;
}


//

int main()
{
}