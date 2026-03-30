#include <bits/stdc++.h>
using namespace std;
/*
    0-1 Knapsack Problem (Recursive Approach)

    Problem:
    --------
    Given:
        wt[]  = {1, 3, 4, 5}   -> weights of items
        val[] = {1, 4, 5, 7}   -> values of items
        W = 7                  -> maximum capacity of knapsack

    Goal:
    -----
    Maximum profit find karna hai without exceeding capacity W.

    Types of Knapsack:
    -------------------
    1. 0-1 Knapsack -> har item ko ya to le sakte ho ya chhod sakte ho (only once)
    2. Unbounded Knapsack -> infinite supply of items
    3. Fractional Knapsack -> items ko fraction me le sakte ho (Greedy)

    Approach (Recursive):
    ---------------------
    Har item ke liye 2 choices:
        1. Include karo (agar weight allow kare)
        2. Exclude karo

    Choice Diagram:
    ----------------
                item[n]
               /       \
        include         exclude
         /                 \
    val[n] + recur     recur

    Base Case:
    ----------
    Agar:
        n == 0  (koi item nahi bacha)
        ya
        W == 0  (capacity khatam)

    -> return 0

*/

// 0/1 Knapsack Problem (Recursive Approach)

int knapsack(int wt[],int val[],int W,int n){

    // base case
    if(n == 0 || W == 0){
        return 0;
    }

    // choice diagram
    if(wt[n-1] <= W){
        // include karo
        int include = val[n-1] + knapsack(wt,val,W-wt[n-1],n-1);
        // exclude karo
        int exclude = knapsack(wt,val,W,n-1);
        // return max of include and exclude
        return max(include,exclude);
    }
    // wt[n-1] > W -> include nahi kar sakte
    return knapsack(wt,val,W,n-1);
}