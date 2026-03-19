#include<bits/stdc++.h>
using namespace std;


/*
        APPROACH + LOGIC (Why we thought this):

        👉 Problem:
        - Hume dynamically numbers add karne hain
        - Har step pe median nikalna hai efficiently

        👉 Brute Force Idea:
        - Har baar array sort karo → O(n log n)
        - Phir middle nikaalo
        ❌ Inefficient (har insertion ke baad sorting costly hai)

        👉 Optimized Thinking:
        - Median hamesha "middle" element hota hai
        - To data ko 2 parts me divide kar dete hain:
              Left half  → smaller elements
              Right half → larger elements

        👉 Data Structure Choice:
        - maxHeap (left side) → taaki largest of smaller half quickly mile
        - minHeap (right side) → taaki smallest of larger half quickly mile

        👉 Key Observation:
        - Median depend karta hai sirf middle elements par
        - Isliye hume pura sorted array nahi chahiye
        - Sirf 2 heaps maintain karke kaam ho sakta hai

        ------------------------------------------------------------

        1. Insertion Logic:
           - Agar number chhota hai (<= maxHeap.top)
                → left side (maxHeap)
           - warna → right side (minHeap)

        2. Balancing Logic:
           - Ensure:
                minHeap.size() <= maxHeap.size() <= minHeap.size() + 1

           - Kyun?
                → taaki median hamesha maxHeap.top ya dono tops se nikle

        3. Median Logic:
           - Agar sizes equal:
                → 2 middle elements → average
           - Agar unequal:
                → maxHeap.top (extra element wahi hota hai)

        ------------------------------------------------------------

        👉 Final Benefit:
        - Insertion → O(log n)
        - Median → O(1)
        ✔️ Efficient for streaming data
    */

class MedianFinder {
public:
    priority_queue<int> maxHeap; 
    priority_queue<int, vector<int>, greater<int>> minHeap;

    void addNum(int num) {
       
        // Step 1: Insert into correct heap
        if(maxHeap.empty() || num <= maxHeap.top()){
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        // Step 2: Balance heaps
        if(maxHeap.size() > minHeap.size() + 1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } 
        else if(minHeap.size() > maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        // Step 3: Calculate median
        if(maxHeap.size() == minHeap.size()){
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        return maxHeap.top();
    }
};

int main(){
    MedianFinder obj;

    obj.addNum(1);
    cout << "Median: " << obj.findMedian() << endl;

    obj.addNum(2);
    cout << "Median: " << obj.findMedian() << endl;

    obj.addNum(3);
    cout << "Median: " << obj.findMedian() << endl;

    obj.addNum(4);
    cout << "Median: " << obj.findMedian() << endl;

    return 0;
}