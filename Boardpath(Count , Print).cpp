/*

Take as input N, a number. N is the size of a snakes and ladder board 
(without any snakes and ladders). Take as input M, a number. 
M is the number of faces of the dice.

a. Write a recursive function which returns the count of different 
   ways the board can be traveled using the dice. Print the value returned.

b. Write a recursive function which prints dice-values for all 
   valid paths across the board (void is the return type for function).

*/

#include <iostream>
using namespace std;

int count = 0;

void Boardpath(int* path, int N, int M, int j = 0){
    //base case
    if(N==0){
        count++;
        for(int i=0; i<j; i++){
            cout<<path[i];
        }
        cout << " ";
        return;
    }
    //recursive case
    for(int i=1; i<=M; i++){
        if(N-i >= 0){
            path[j] = i;
            Boardpath(path,N-i,M,j+1);
        }
    }
}
int main() {
    int N,M;
    cin >> N; // Size of Board
    cin >> M; // Number of dice faces
    int* path = new int[N];

    Boardpath(path,N,M);
    cout << endl;
    cout << count << endl;
    return 0;
}
