#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int sumArray(vector<int> loads){
    int sum, n = loads.size();

    for(int i = 0; i < n; i++){
        sum+=loads[i];
    }
    return sum;
}

//0/1 Knapsack aproach
//Ref: https://www.youtube.com/watch?v=xCbYmUPvc2Q
/*
My aproach consists of a simple 0/1 Knapsack with Dynamic Programming
Where you take the load of each member of the array as both the weight and the value, and the max weight would be half of the sum of all the members of the array +1
this is because we want to know in the matrix from 0 to array/2

with this you can implement the algorithm as you normally would.

Then we can take the last value of the matrix, because this value will always be made of the highest combination of loads possible, then you can
take the difference between the highest load and the sum of the array and return it.
*/
int solution(vector<int> loads){
    //Array must be sorted
    sort(loads.begin(), loads.end());


    //We will take this as the max weight 
    int arraySum = sumArray(loads);
    int medium = (arraySum/2) + 1;

    //We create the matrix needed for the dynamic programing aproach
    vector<int> aux;
    vector<vector<int>> knapsackMX;
    aux.resize(medium, 0);
    for(int i = 0; i < loads.size(); i++){
        knapsackMX.push_back(aux);
    }


    for(int i = 0; i < loads.size(); i++){
        for(int j = 0; j < knapsackMX[i].size(); j++){
            //We need to treat the first line differently
            if(i == 0){
                if(loads[i] > j){
                    knapsackMX[i][j] = 0;
                }
                else{
                    knapsackMX[i][j] = loads[i];
                }
            }
            else{
                //If the weight of the ith object is greater than the current max weight (j), we take the value thats above
                if(loads[i] > j){
                    knapsackMX[i][j] = knapsackMX[i-1][j];
                }
                else{
                    //We check if the value above is greater than the one w times to the left and one above
                    knapsackMX[i][j] = max(knapsackMX[i-1][j], (knapsackMX[i-1][j - loads[i]] + loads[i]));
                }
            }
        }
    }

    //Because the last line contains the highest load, we can always asume that the combination to get there will be the highest possible load that a server can take
    int greaterLoad = knapsackMX[loads.size() - 1][medium-1];
    
    //We return the difference between the total load and the greater load on a server
    //This is because this value will be the difference between the server 1 and 2
    return abs(arraySum - 2 * greaterLoad);
}


int main(){
    vector<int> loads = {1, 4, 6, 7, 8};
    cout << "The difference between loads is: " << solution(loads) << endl;
    return 0;
}