class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        // for(int i=0;i<n;i++){
        //     int sum=nums[i];
        //     for(int j=i+1;j<n;j++){
        //         sum += nums[j];
        //          if(sum%k==0){
        //             return true;
        //          }
        //     }

           
        // }

        // return false;

        // method 2:
        // we will calculate the prefix sum 
        // after that on every time we will check
        // prefix sum % k -> gives some remainder than check in map is this exist or not
        // if exist than check lenght should be >=2 (given in question)
        // not exist than put inside the map that remainder 
        unordered_map<int,int>mp;
        mp[0]=-1;
        int sum=0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            int rem = sum%k;
            if(mp.find(rem)!=mp.end()){
                int len = (i-mp[rem]);
                if(len>=2){
                    return true;
                }
            }else{
                mp[rem]=i;
            }
        }
        return false;
    }
};