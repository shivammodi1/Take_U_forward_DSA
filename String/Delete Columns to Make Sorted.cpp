#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to count how many columns are NOT lexicographically sorted
    int minDeletionSize(vector<string>& strs) {

        // Number of columns = length of any string (all are same length)
        int col = strs[0].size();

        // Number of rows = total strings
        int row = strs.size();

        // This will store how many columns we need to delete
        int count = 0;

        // Loop over each column
        for(int j = 0; j < col; j++) {

            // Loop over rows for the current column
            for(int i = 0; i < row - 1; i++) {

                // Compare current row character with the next row character
                // If upper character > lower character,
                // then column is NOT sorted
                if(strs[i][j] > strs[i + 1][j]) {

                    // Increase delete count for this column
                    count++;

                    // No need to check further rows in this column
                    break;
                }
            }
        }

        // Return total columns to delete
        return count;
    }
};

int main() {
    // Creating object of Solution class
    Solution obj;

    // Input example
    vector<string> strs = {"cba", "daf", "ghi"};

    // Calling function and storing result
    int result = obj.minDeletionSize(strs);

    // Printing output
    cout << "Number of columns to delete: " << result << endl;

    return 0;
}
