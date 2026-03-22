// // Given two unsorted integer arrays a[] and b[] each consisting of distinct elements, the task is to return the count of elements in the intersection (or common elements) of the two arrays.

// // Intersection of two arrays can be defined as the set containing distinct common elements between the two arrays. 

// Input: a[] = [89, 24, 75, 11, 23], b[] = [89, 2, 4]
// Output: 1
// Explanation: 89 is the only element in the intersection of two arrays.


class Solution {
  public:
    int intersectSize(vector<int> &a, vector<int> &b) {
        // code  here
        unordered_map<int,int>mp;
        int n=a.size();
        int m=b.size();
        
        // 1 array ka frequency map bna liya
        for(int i=0;i<n;i++){
            mp[a[i]]++;
        }
        int count=0;

        // abb check karege ki array2 ka element frequency map me hai ya nhi
        // agar hai to count++ kr denge
        for(int i=0;i<m;i++){
            if(mp.find(b[i])!=mp.end()){
               count++;
            }
        }
        return count;
    }
};