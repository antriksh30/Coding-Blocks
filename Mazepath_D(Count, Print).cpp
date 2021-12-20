#include <iostream>
using namespace std;

void printSteps(int m, int i, int n, int j, char* out, int k){
    //base case
    //We have reached our destination
    if(i==m-1 && j==n-1){
        out[k] = '\0';
        cout<<out<<" ";
        return;
    }
    //recursive case
    // We reached end of a row, we can only move downwards 
    if(j==n-1){
        out[k] = 'V';
        printSteps(m,i+1,n,j,out,k+1);
        return;
    }
    // We reached end of a column, we can only move rightwards
    if(i==m-1){
        out[k] = 'H';
        printSteps(m,i,n,j+1,out,k+1);
        return;
    }

    out[k] = 'V';
    printSteps(m,i+1,n,j,out,k+1);
    out[k] = 'H';
    printSteps(m,i,n,j+1,out,k+1);
    out[k] = 'D';
    printSteps(m,i+1,n,j+1,out,k+1);    
}

int countPath(int m, int n, int i, int j){
    //base case
    if(i==m-1 && j==n-1) return 1;
    if(i==m || j==n) return 0;

    //recursive case
    int X = countPath(m,n,i+1,j);    // move down
    int Y = countPath(m,n,i,j+1);    //move right
    int Z = countPath(m,n,i+1,j+1);  // move diagonally

    return X+Y+Z;
}
int main(){
    int m,n;
    cin>>m>>n;

    char out[100];

    printSteps(m,0,n,0,out,0);
    cout<<endl;
    cout<<countPath(m,n,0,0);
    return 0;
}