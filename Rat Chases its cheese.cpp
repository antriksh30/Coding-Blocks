#include <iostream>
using namespace std;

bool flag = false ; 
void ratChases(char maze[][15],int soln[][15],int i,int j,int m,int n){
    //Base case
    if(i==m-1 && j==n-1){
        soln[i][j] = 1;
         for(int row=0;row<=m-1;row++){
            for(int col=0;col<=n-1;col++){
                cout<<soln[row][col]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        flag=true;
        return;
    }

    if(i>m-1 || j>n-1 || i<0 || j<0) return;
    if(maze[i][j] == 'X' || soln[i][j] == 1) return;

    //Recursive case
    soln[i][j] = 1;
    
    ratChases(maze,soln,i+1,j,m,n); // moving down
    ratChases(maze,soln,i,j+1,m,n); // moving right
    ratChases(maze,soln,i-1,j,m,n); // moving up
    ratChases(maze,soln,i,j-1,m,n); // moving left

    soln[i][j] = 0; //Backtrack

}
int main() {
    char maze[15][15];
    int soln[15][15]= {};
    int m,n;     
    cin >> m >> n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> maze[i][j];
        }
    }
    
    ratChases(maze,soln,0,0,m,n);

    if(!flag)  cout<<"NO PATH FOUND";

    return 0;
}