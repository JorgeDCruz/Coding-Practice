#include<iostream>
#include <unordered_map>
using namespace std;

int solution(string keyboard, string text){
    unordered_map<char, int> keyMap;

    for(int i = 0; i < keyboard.length(); i++){
        keyMap[keyboard[i]] = i;
    }


    int current = 0, target = 0, sum = 0;
    for(int i = 0; i < text.length(); i++){
        target = keyMap[text[i]];
        sum+=abs(target - current);
        current = target;
    }
    return sum;
}

int main(){
    string keyboard = "abcdefghijklmnopqrstuvwxy";
    string text = "hola";
    cout << solution(keyboard, text) << endl;
    return 0;
}