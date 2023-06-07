//Problem 242
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool isAnagram(string s, string t) {
    sort(s.begin(), s.end()); //O(n log(n))
    sort(t.begin(), t.end()); //O(n log(n))
    return (s == t);
}   

int main(){
    string s =  "anagram";
    string t = "nagaram";  
    if(isAnagram(s, t)){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }
    return 0;
}