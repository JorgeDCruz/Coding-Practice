#include<iostream>
#include<string>
using namespace std;

string solution(string input){
    string output;


    if(input[0] == '?'){

        input[0] = (input[1] < 4 || input[1] == '?' ? input[0] = '2': input[0] = '1');
    }

    if(input[1] == '?'){
        input[1] = (input[0] == '2' ? input[1] = '3': input[1] = '9');
    }

    input[3] = (input[3] == '?' ? input[3] = '5': input[3]);
    input[4] = (input[4] == '?' ? input[4] = '9': input[4]);


    
    return input;
}

int main(){
    string input = "??:??";
    cout << solution(input) << endl;
    return 0; 
}