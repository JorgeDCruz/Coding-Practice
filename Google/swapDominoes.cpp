#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;


int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
    int n = tops.size();

    unordered_map<int, int> mA;
    unordered_map<int, int> mB;
    int repetition = 0;
    for(int i = 0; i < n; i++){
        mA[tops[i]]++;
        mB[bottoms[i]]++;
        if(tops[i] == bottoms[i]){
            repetition++;
        }
    }
    int sol = -1;
    for(auto x: mA){

        if((x.second + mB[x.first] - repetition) == n){
            sol = n - max(x.second, mB[x.first]);
        }
    }
    
    return sol;
}

int main(){
    vector<int> tops = {3,5,1,2,3};
    vector<int> bottoms = {3,6,3,3,4};
    minDominoRotations(tops, bottoms);
    return 0;
}