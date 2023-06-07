//Problem 216
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> st;
    for(int i = 0; i < nums.size(); i++){ 
        if(st.find(nums[i]) != st.end()){//O(1)
            return true;
        }
        else{
            st.insert(nums[i]);
        }
    } 
    return false;
}


int main(){
    vector<int> nums = {1,1,1,3,3,4,3,2,4,2};
    if(containsDuplicate(nums)){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }
    return 0;
}