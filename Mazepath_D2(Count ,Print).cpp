#include <iostream>
using namespace std;

void printSteps(int n, int i, int j, char* out, int k){
    //base case
    //We have reached our destination
    if(i==n-1 && j==n-1){
        out[k] = '\0';
        cout<<out<<" ";
        return;
    }
    //recursive case
    // We reached end of a row, we can only move downwards 
    if(j==n-1){
        out[k] = 'V';
        printSteps(n,i+1,j,out,k+1);
        return;
    }
    // We reached end of a column, we can only move rightwards
    if(i==n-1){
        out[k] = 'H';
        printSteps(n,i,j+1,out,k+1);
        return;
    }

    out[k] = 'V';
    printSteps(n,i+1,j,out,k+1);
    out[k] = 'H';
    printSteps(n,i,j+1,out,k+1);
    if(i==j || i+j==n-1){
        out[k] = 'D';
        printSteps(n,i+1,j+1,out,k+1);   
    } 
}

int countPath(int n, int i, int j){
    //base case
    if(i==n-1 && j==n-1) return 1;
    if(i==n || j==n) return 0;

    //recursive case
    int X = countPath(n,i+1,j);    // move down
    int Y = countPath(n,i,j+1);    //move right
    int Z = 0;
    if(i==j || i+j==n-1) Z = countPath(n,i+1,j+1);  // move diagonally

    return X+Y+Z;
}
int main(){
    int n;
    cin>>n;

    char out[100];

    printSteps(n,0,0,out,0);
    cout<<endl;
    cout<<countPath(n,0,0);
    return 0;
}