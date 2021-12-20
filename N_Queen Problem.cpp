#include <iostream>
using namespace std;

int count = 0;
void f(int n, int* Qpos, int r){
    //base case
    if(r==n){
        count++;
        for(int i=0; i<n; i++){
            cout<<"{"<<i+1<<"-"<<Qpos[i]+1<<"}"<<" ";
        }
        return;
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
            f(n,Qpos,r+1);
        }
    }
}
int main() {
    int N;
    cin >> N;
    int* Qpos = new int[N];
    f(N,Qpos,0);
    cout<<endl;
    cout<<count;
    return 0;
}
