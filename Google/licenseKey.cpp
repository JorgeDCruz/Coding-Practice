#include<iostream>
#include <algorithm>
#include <string>

using namespace std;

string licenseKeyFormatting(string s, int k) {
    int n = s.size();
    int count = 0;
    string sol = "";
    for(int i = n-1; i >= 0; i--){
        if(s[i] != '-'){
            sol = s[i] + sol;
            count++;
        }
        if(count == k && i != 0){
            sol = "-" + sol;
            count = 0;
        }
    }
    transform(sol.begin(), sol.end(), sol.begin(), ::toupper); //O(n)
    if(sol[0] == '-'){
        sol.erase(0, 1);
    }
    

    return sol;
}


int main(){
    string s = "----a-a-a-a--";
    int k = 2;
    char c = 'a';
    cout << licenseKeyFormatting(s, k) << endl;
    cout << c - 32 << endl;
    return 0;
}