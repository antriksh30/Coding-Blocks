#include <iostream>
#include <cmath>
using namespace std;

bool canPlaceDigit(int grid[][9], int n, int i, int j, int d) {

	for(int k=0; k<n; k++) {
		if(grid[i][k] == d || grid[k][j] == d) {
			return false;
		}
	}

	int rn = sqrt(n);

	int sx = (i/rn) * rn; // row no. of the 1st element of the subgrid
	int sy = (j/rn) * rn; // col. no. of the 1st element of the subgrid 
	
	for(int x=sx; x<sx+rn; x++) {
		for(int y=sy; y<sy+rn; y++) {
			if(grid[x][y] == d) {
				return false;
			}
		}
	}

	return true;

}

void solveSudoku(int grid[][9], int n, int i = 0, int j = 0){
    //base case
    if(i == n) {
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				cout << grid[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		return;
	}

    //recursive case
    if(j==n)
        solveSudoku(grid,n,i+1,0);
    if(grid[i][j] != 0){ 
        solveSudoku(grid,n,i,j+1);
        return;
    }
    else{
        for(int d=1; d<=9; d++){
            if(canPlaceDigit(grid,n,i,j,d)){
                grid[i][j] = d;
                solveSudoku(grid,n,i,j+1);
                grid[i][j] = 0;
            }
        }
    }

}
int main() {
    int N;
    cin >> N;
    int grid[9][9];
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> grid[i][j];
        }
    }

    solveSudoku(grid,N);
    return 0;
}
