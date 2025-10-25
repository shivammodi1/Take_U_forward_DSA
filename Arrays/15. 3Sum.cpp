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


//method 2 
// T.C ->O(n^2) not exatly n^2 it can be more than
// TLE in this case also
// arr[i] + arr[j] + arr[k]=0
// arr[k] = -(arr[i]+arr[j])
//use hasing to search the rest element in array 
// -1 -1 -> arr[k] = -(-1-1)=2
//now using hasing we can directly serach 2 is present or not

vector<vector<int>> Sum3(vector<int>arr){
    int n=arr.size();
    
    set<vector<int>>st;
    for(int i=0;i<n;i++){
        set<int>hashset;
        for(int j=i+1;j<n;j++){
            int k = -(arr[i]+arr[j]);
            // if third element present in the hashset
            if(hashset.find(k) != hashset.end()){
                vector<int>tmp = {arr[i],arr[j],k};
                sort(tmp.begin(),tmp.end());
                st.insert(tmp);
            }
            hashset.insert(arr[j]);// at every time insert into hashset
        }
    }
    vector<vector<int>>res(st.begin(),st.end());
    return res;
}


// method 3 
//Optimal Solution
// using two pointer method
 vector<vector<int>> ThreeSum(vector<int> &arr){
    int n=arr.size();
    set<vector<int>>s;

    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        int st=i+1;
        int end=n-1;
        while(st<end){
            int sum = arr[i]+arr[st]+arr[end];
            // if sum==0 than store directly in set for uniqueness
            if(sum==0){
                vector<int>tmp = {arr[i],arr[st],arr[end]};
                s.insert(tmp);
                st++,end--;
            }else if(sum<0){
                // lesser than 0 move forward for making near 0 or equal 0
                st++;
            }else{
                // Othereise more back if more than 0
                end--;
            }
        }
    }
    vector<vector<int>>res(s.begin(),s.end());
    return res;
 }


int main()
{

}