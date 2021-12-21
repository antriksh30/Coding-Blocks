#include <iostream>
using namespace std;

int count = 0;
void split(int* A, int n, string s1, int sum1, string s2, int sum2, int i){
    //base case
    if(i == n){
        if(sum1 == sum2){
            count++;
            cout << s1.substr(1) <<" and " << s2.substr(1) << endl;
        }
        return;
    }
    
    //recursive case
    split (A, n, s1 + " " + to_string(A[i]), sum1+A[i], s2, sum2, i+1);
    split (A, n, s1, sum1, s2 + " " + to_string(A[i]), sum2+A[i], i+1);

}

int main() {

    int N;
    cin >> N;
    int* A = new int[N];
    for(int i=0; i<N; i++){
        cin >> A[i];
    }

    split(A,N,"",0,"",0,0);
    cout<<count;

    return 0;
}
