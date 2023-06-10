#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

bool compare(vector<int> a, vector<int> b){
    double euclidian1 = 0, euclidian2 = 0;
    euclidian1 = sqrt((pow((0 - a[0]), 2)) + (pow((0 - a[1]), 2)));
    euclidian2 = sqrt((pow((0 - b[0]), 2)) + (pow((0 - b[1]), 2)));

    if(euclidian1 < euclidian2){
        return true;
    }
    return false;
}

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    sort(points.begin(), points.end(), compare);
    vector<vector<int>> sol;
    for(int i = 0; i < k; i++){
        sol.push_back(points[i]);
    }
    return sol;
}


int main(){
    return 0;
}