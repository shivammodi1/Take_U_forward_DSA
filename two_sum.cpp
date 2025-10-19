// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
// Example 2:
// Input: nums = [3,2,4], target = 6
// Output: [1,2]

#include<bits/stdc++.h>
using namespace std;



// Optimal Solution using hash map
//T.C -> O(n)
vector<int> TwoSum(vector<int>& nums, int target){
    unordered_map<int,int>mp;
    int n = nums.size();
    for(int i=0;i<n;i++){
        int ele = nums[i];
        int rest = target - ele;
        //if in map rest is pressent
        if(mp.find(rest) != mp.end()){
            return {mp[rest],i};
        }
        //otherwise store that [value-> index]
        mp[ele] = i;
    }
    return {-1,-1};
}

// broute fource method
vector<int> twoSum(vector<int>& nums, int target){
    vector<int>ans;
    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            if(nums[i]+nums[j]==target){
                ans.push_back(i);
                ans.push_back(j);
            }
        }
    }
    return ans;
}


//target - nums [i] = x 
// x ko rest aaray me seach karege h toh woh index return kr denge nhi toh aage badho
// tc->O(nlogn)
//for sorted array
int index(vector<int>&nums , int start,int x){
    int ind=-1;
    int st,end;
    st=start;
    end=nums.size()-1;
    while(st<=end){
        int mid = st+(end-st)/2;
        if(nums[mid]==x){
            ind=mid;
            return mid;
        }else if(nums[mid]>x){
            end=mid-1;
        }else{
            st = mid+1;
        }
    }
    return ind;
}

vector<int> TwoSum(vector<int>& nums, int target){
    vector<int>ans;
    int n = nums.size();
    for(int i=0;i<n-1;i++){
        int ele = nums[i];
        int newTar = target - ele;
        int j = index(nums,i+1,newTar);
        if(j != -1){
            ans.push_back(i);
            ans.push_back(j);
            break;
        }
    }
    return ans;
}

// method 4 using two pointer approach
vector<int> TwoSum(vector<int>& nums, int target){
    vector<int>ans;
    sort(nums.begin(),nums.end());
    int n = nums.size();
    int st=0;
    int end=n-1;
    while (st<end)
    {
        int sum = nums[st]+nums[end];
        if(sum==target){
            return {st,end};
        }else if(sum>target){
            end--;
        }else{
            st++;
        }
    }
    
    return {-1,-1};
}

int main(){
     int n;
    cin >> n;
    int target;
    cin >> target;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<int>ans = TwoSum(nums, target);

    for(int i=0;i<2;i++){
        cout<<ans[i]<<" ";
    }
}