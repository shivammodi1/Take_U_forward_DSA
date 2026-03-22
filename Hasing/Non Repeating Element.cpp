// Find the first non-repeating element in a given array arr of integers and
// if there is not present any non-repeating element then return 0
// Note: The array consists of only positive and negative integers and not zero.


// Approach:
// 1. Create an unordered_map for storing the number and its frequency.
// 2. Traverse the array and update the frequency of each number in the map.
//     - <number, frequency>
// 3. Traverse array again and check the frequency of each number in the map.
//     - If frequency is 1, return that number as the first non-repeating element
// 4. If no non-repeating element is found, return 0.
// Time Complexity: O(n) + O(n) = O(n)
// Space Complexity: O(n) for the unordered_map


class Solution {
  public:
    int firstNonRepeating(vector<int>& arr) {
        // Complete the function
        unordered_map<int,int>mp;
        int n=arr.size();
        
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        
        for(int i=0;i<n;i++){
            if(mp[arr[i]]==1){
                return arr[i];
            }
        }
        return 0;
        
    }
};
