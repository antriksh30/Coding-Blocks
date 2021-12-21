#include <iostream>
using namespace std;

int count = 0;
int countWays(int n, int* Qpos, int r){
    //base case
    if(r==n){
        count++;
        return count;
    }
    //recursive case
    for(int j=0; j<n; j++){
        bool canplace = true;
        for(int i=0; i<=r-1; i++){
            if(Qpos[i] == j || Qpos[i] == j+(r-i) || Qpos[i] == j-(r-i)){
                canplace = false;
            }
        }
        if(canplace){
            Qpos[r] = j;
            count = countWays(n,Qpos,r+1);
        }
    }
    return count;
}
int main() {
    int N;
    cin >> N;
    int* Qpos = new int[N];

    cout << countWays(N,Qpos,0);
    return 0;
}
