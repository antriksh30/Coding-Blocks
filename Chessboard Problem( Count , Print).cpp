#include <iostream>      // Chessboard Problem(Count , Print)
using namespace std;

// In this code we are storing all the moves of a path in out[] array
// and when we reach our desitination we print the moves in the req. format

int count = 0;

void Chessboard(int n, int i, int j, pair<char,pair<int,int>> out[],int k){

    //base case
    // we have reached our destination
    if(i==n-1 && j==n-1){
        count+=1;
        cout<<"{0-0}";
        for(int j=0;out[j].first != '\0';j++){
            cout<<out[j].first;
            cout<<"{"<<out[j].second.first<<"-"<<out[j].second.second<<"}";
        }
        cout<<" ";
        return;
    }

    // we have gone outside the chessboard
    if(i>n-1 || j>n-1) return;


    //recursive case

    //1. As knight
    // Moving 2 steps down and 1 step right
    out[k]= {'K',{i+2,j+1}};
    Chessboard(n,i+2,j+1,out,k+1);
    out[k] = {}; //backtracking
    
    // Moving 1 step down and 2 steps right
    out[k]= {'K',{i+1,j+2}};
    Chessboard(n,i+1,j+2,out,k+1);
    out[k] = {};  //backtracking

    
    //2. As Rook
    if(i==0 || j==0 || i==n-1 || j==n-1){
        // Moving horizontally
        for(int x=1;x<n;x++){
            out[k]= {'R',{i,j+x}};
            Chessboard(n,i,j+x,out,k+1);
            out[k] = {};  //backtracking
        }

        // Moving vertically
        for(int x=1;x<n;x++){
            out[k]= {'R',{i+x,j}};
            Chessboard(n,i+x,j,out,k+1);
            out[k] = {};  //backtracking
        }
    }
    

    //3. As Bishop
    if(i==j || i+j==n-1){
        // Moving diagonally
        for(int x=1;x<n;x++){
            out[k]= {'B',{i+x,j+x}};
            Chessboard(n,i+x,j+x,out,k+1);
            out[k] = {};  //backtracking
        }
    }
    
}

int main() {
    int N;
    cin>>N;
    pair<char,pair<int,int>> out[10];
    Chessboard(N,0,0,out,0); // Printing moves
    cout<<endl<<count;      // Printing no of moves
    return 0;
}
