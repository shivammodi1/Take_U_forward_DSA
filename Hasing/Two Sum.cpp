// Given an array arr[] of integers and another integer target. Determine if there exist two distinct indices such that the sum of their elements is equal to the target.
// Example:
// Input: arr[] = {1, 2, 3, 4, 5}, target = 8
// Output: Yes
// Explanation: arr[2] + arr[4] = 3 + 5 = 8

class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]=i;
        }

        // abb map me rest element ko search karna hai
        // woh element target me se minus karna hai
        // aur check karna hai ki woh element map me exist karta hai ya nahi 
        // aur woh element ka index i ke barabar nahi hona chahiye
        for(int i=0;i<arr.size();i++){
            int ele=arr[i];
            int t = target-ele;
            
            if(mp.find(t)!=mp.end() && mp[t]!=i){
                return true;
            }
        }
        return false;
        
    }
};