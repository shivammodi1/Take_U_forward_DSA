#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findPages(vector<int> &arr, int k) {

        int n = arr.size();  
        // Total number of books

        if (k > n) return -1;  
        // Agar students books se zyada hain, toh allocation possible nahi hai

        int sum = 0;
        int maxVal = arr[0];

        // Calculate total pages (sum) aur largest single book (maxVal)
        for (int i = 0; i < n; i++) {
            sum += arr[i];           // total number of pages in all books
            if (arr[i] > maxVal)     // find maximum pages in a single book
                maxVal = arr[i];
        }

        int st = maxVal;  // minimum possible limit (ek student ke liye)
        int end = sum;    // maximum possible limit (agar ek hi student sab padhe)
        int ans = -1;     // final answer store karega

        // Binary Search shuru karte hain
        while (st <= end) {
            int mid = (st + end) / 2;  
            // mid = ek assumption hai ki ek student max itne pages tak padh sakta hai

            int pages = 0;  // ab tak assigned pages ka sum
            int count = 1;  // ab tak kitne students lage

            // Har book ko assign karne ki koshish karte hain
            for (int i = 0; i < n; i++) {

                // Agar current book add karne se mid limit cross ho jaye
                if (pages + arr[i] > mid) {
                    count++;          // naye student ko dena padega
                    pages = arr[i];   // naye student ke pages ka count start karein
                } 
                else {
                    pages += arr[i];  // current student ko assign karte jao
                }
            }

            // Ab check karte hain kitne students lage
            if (count <= k) {
                // Agar students kam ya barabar lage (means possible allocation)
                ans = mid;        // current mid ek valid answer ho sakta hai
                end = mid - 1;    // lekin aur chhota answer check karte hain (better minimum)
            } 
            else {
                // Agar students zyada lage toh mid limit chhoti thi
                st = mid + 1;     // isliye limit badha do
            }
        }

        return ans;  // minimum possible maximum pages return karo
    }
};
