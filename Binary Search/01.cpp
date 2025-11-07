#include<bits/stdc++.h>
using namespace std;

int main(){
    int row, col;
    cin >> row >> col; // Input the dimensions of the 2D array

    vector<vector<int>> arr(row, vector<int>(col)); // Declare a 2D array using vector

    // Input elements into the 2D array
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cin >> arr[i][j];
        }
    }
// -----------------------------------------------------------------------------------------------------------------------------------------

    // this is fow row major order

    // index = (row_index * col + col_index) for a 1D representation of the 2D array
    int index = (0 * col + 0);
    cout << "Index of element at (0, 0): " << index << endl;
    index = (1 * col + 2);
    cout << "Index of element at (1, 2): " << index << endl;

    // if index is given now find the row and column
    int row_index = index / col;
    int col_index = index % col;
    cout << "Row index: " << row_index << ", Column index: " << col_index << endl;

// -----------------------------------------------------------------------------------------------------------------------------------------

    // Column major order

    // index = (col_index * row + row_index) for a 1D representation of the 2D array
    index = (0 * row + 0);
    cout << "Index of element at (0, 0) in column major order: " << index << endl;
    index = (2 * row + 1);
    cout << "Index of element at (2, 1) in column major order: " << index << endl;

    // if index is given now find the row and column in column major order
    row_index = index % row;
    col_index = index / row;
    cout << "Row index in column major order: " << row_index << ", Column index: " << col_index << endl;

// -----------------------------------------------------------------------------------------------------------------------------------------


    // Output the elements of the 2D array
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
// -----------------------------------------------------------------------------------------------------------------------------------------


    return 0;
}