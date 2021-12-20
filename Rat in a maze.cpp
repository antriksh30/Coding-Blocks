#include <iostream>
using namespace std;
bool ratInMaze(char maze[][1005],int soln[][1005],int i,int j,int m,int n){
    //Base case
    if(i==m-1 && j==n-1){
        soln[i][j] = 1;
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                cout<<soln[row][col]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return true;
    }

    if(i>m-1 || j>n-1)  return false;

    if(maze[i][j] == 'X')  return false;

    //Recursive case
    soln[i][j] = 1;

    bool rightSuccess = ratInMaze(maze,soln,i,j+1,m,n);
    if(rightSuccess)  return true ;
    
    bool downSuccess  = ratInMaze(maze,soln,i+1,j,m,n);
    if(downSuccess)  return true ;
    
    soln[i][j] = 0;  //Backtrack

    return false;

}
int main() 
{
    char maze[1005][1005];
    int soln[1005][1005]= {};
    int m,n;   
    cin >>m >>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> maze[i][j];
        }
    }

    bool ans = ratInMaze(maze,soln,0,0,m,n);
    if(!ans) cout<<"-1";

    return 0;
}