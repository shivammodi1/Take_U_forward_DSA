#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find the next permutation
//method 1 Using Library
// next_permutation
void nextPermutation(vector<int>& arr) {

    // Rearranges elements into the next lexicographical order
    // If already last permutation, rearranges to the smallest
    next_permutation(arr.begin(), arr.end());
}



int main() {

    vector<int> arr = {2, 4, 1, 7, 5, 0};

    nextPermutation(arr);

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    return 0;
}