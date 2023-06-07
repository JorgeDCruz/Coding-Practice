#include<iostream>
#include<vector>
using namespace std;

int maxArea(vector<int>& height) {
    int n = height.size();

    //Two pointers
    int i = 0, j = n-1;
    int currentArea, maxArea = 0;
    //Constant iteration on two pointers
    while(i < j){
        currentArea = min(height[i], height[j]) * (j - i);
        if(height[i] < height[j]){
            i++;
        }
        else{
            j--;
        }
        maxArea = max(maxArea, currentArea);
    }
    return maxArea;
}


int main(){

    vector<int> height = {1,1};
    maxArea(height);
    return 0;
}