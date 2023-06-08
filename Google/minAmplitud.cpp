#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template<class T>
void printQueue(priority_queue<T> q){
    while(!q.empty()){
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;
}


int minDifference(vector<int>& nums) {
    int n = nums.size();
    priority_queue<int> maxQ;
    //Reverse priority queue
    priority_queue<int, vector<int>, greater<int> > minQ;

    for(int n : nums){
        maxQ.push(n);
        if(maxQ.size() > 4){
            maxQ.pop();
        }
        minQ.push(n);
        if(minQ.size() > 5){
            cout << minQ.top() << endl;
            minQ.pop();
        }
    }

    // for(int i = 0; i < n; i++){
    //     maxQ.push(nums[i]);
    //     if(maxQ.size() > 4){
    //         maxQ.pop();
    //     }
    //     minQ.push(nums[i]);
    //     if(minQ.size() > 4){
    //         minQ.pop();
    //     }
    // }

    while(!minQ.empty()){
        cout << minQ.top() << " ";
        minQ.pop();
    }
    cout << endl;


    // int max = INT_MAX;
    // vector<int> minV;
    // while(minQ.size() > 0){
    //     minV.push_back(minQ.top());
    //     minQ.pop();
    // }

    // for(int i = 3; i >= 0; i--){
    //     cout << minV[i] << endl;
    //     max = min(max, (maxQ.top() - minV[i]));
    //     maxQ.pop();
    // }

    // cout << max << endl;
    return 0;
}

int main(){
    vector<int> nums = {1,5,0,10,14};
    cout << minDifference(nums) << endl;
    return 0;
}