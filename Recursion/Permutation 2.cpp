class Solution {
public:
    void generatePermute2(vector<int>& arr, vector<vector<int>>& ans, int index) {

        // Base case:
        // Jab index array ke size ke equal ho jaye
        // matlab ek valid permutation ban chuki hai
        if(index == arr.size()){
            ans.push_back(arr);
            return;
        }

        // unordered_set used isliye use kar rahe hain
        // taaki same recursion level par duplicate element
        // dobara swap na ho
        unordered_set<int> used;

        // index se leke last tak element ko current index par rakhne ki try
        for(int i = index; i < arr.size(); i++){

            // Agar same value is recursion level par already use ho chuki hai
            // toh skip kar do (duplicate permutation avoid)
            if(used.count(arr[i])) continue;

            // Current value ko mark kar do as used
            used.insert(arr[i]);

            // arr[i] ko current position (index) par le aao
            swap(arr[i], arr[index]);

            // Baaki ke elements ke liye recursion call
            generatePermute2(arr, ans, index + 1);

            // Backtracking:
            // Array ko original state me laana
            swap(arr[i], arr[index]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;

        // Sort isliye taaki duplicates easily handle ho sake
        sort(nums.begin(), nums.end());

        generatePermute2(nums, ans, 0);

        return ans;
    }
};


int main(){
    return 0;
}
