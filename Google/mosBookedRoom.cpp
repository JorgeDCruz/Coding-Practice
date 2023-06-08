#include<iostream>
#include<vector>
#include <map>
using namespace std;

void mostBooked(vector<string>& rooms){
    int n = rooms.size();
    map<string, int> mp;
    string s;
    for(int i = 0; i < n; i++){
        s = "";
        if(rooms[i][0] == '+'){
            s+=rooms[i][1];
            s+=rooms[i][2];
            mp[s]++;
        }
    }

    int max = 0;
    string sol = "";
    for(auto x : mp){
        if(x.second > max){
            max = x.second;
            sol = x.first;
        }
    }
    cout << sol << endl;
}

int main(){
    vector<string> rooms = {"+1A", "+3E", "-1A", "+4F", "+1A", "-3E"};
    mostBooked(rooms);
    return 0;
}