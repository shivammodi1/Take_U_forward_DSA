#include<bits/stdc++.h>
using namespace std;

vector<string> ratInMaze(vector<vector<int>>& maze){

}

int main(){
    return 0;
}

// Consider a rat placed at position (0, 0) in an n x n square matrix maze[][]. 
// The rat's goal is to reach the destination at position (n-1, n-1). 
// The rat can move in four possible directions: 'U'(up), 'D'(down), 'L' (left), 'R' (right).
// The matrix contains only two possible values:
// 0: A blocked cell through which the rat cannot travel.
// 1: A free cell that the rat can pass through.

// My task is to find all possible paths that the rat can take to reach the destination.
// Note: The rat cannot visit the same cell more than once in a single path.
// The function should return a vector of strings, where each string represents a valid path using the characters 'U', 'D', 'L', and 'R'.
// Example: [ [1, 0, 0, 0],
//            [1, 1, 0, 1],
//            [1, 1, 0, 0],
//            [0, 1, 1, 1] ]

// Output: ["DDRDRR", "DRDDRR"]