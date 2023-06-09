#include <utility>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <class T>
void printPairs(vector<pair<T, T>> p){
    int n = p.size();
    for(int i = 0; i < n; i++){
        cout << p[i].first << " " << p[i].second << endl;
    }
}

int solution(vector<int> S, vector<int> E){

    vector<pair<int, int>> times;
    
    for(int i = 0; i < S.size(); i++){
        times.push_back(make_pair(S[i], 1));

    }

    for(int i = 0; i < E.size(); i++){
        times.push_back(make_pair(E[i], -1));

    }
    sort(times.begin(), times.end()); //O(n log(n))
    int maxTime = 0, currentTime = 0;
    for(int i = 0; i < times.size(); i++){
        currentTime+=times[i].second;
        maxTime = max(currentTime, maxTime);
    }

    return maxTime;
}


int main(){
    vector<int> S = {1, 2, 6, 5, 3};
    vector<int> E = {5, 5, 7, 6, 8};
    cout << solution(S, E) << endl;
    return 0;
}