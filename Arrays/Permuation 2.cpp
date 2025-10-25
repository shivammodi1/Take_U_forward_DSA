#include<bits/stdc++.h>
using namespace std;


// here it will not exclude the duplicates 
void generatePermute2(vector<int>&arr,set<vector<int>>&ans,int index){
    if(index == arr.size()){
        ans.insert(arr);
        return ;
    }
    //generate permutaion 
    for(int i=0;i<arr.size();i++){
        swap(arr[i],arr[index]);
        generatePermute2(arr,ans,index+1);
        swap(arr[i],arr[index]);//backtrack to original
    }
}


int main(){
    vector<int> arr = {2, 4, 1, 7, 5, 0};
    set<vector<int>>ans;

    generatePermute2(arr,ans,0);
    vector<vector<int>>res(ans.begin(),ans.end());


    return 0;
}