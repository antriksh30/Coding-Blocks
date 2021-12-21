#include <iostream>
using namespace std;

int NthTriangle(int N){
    //base case
    if(N==0) return 0;
    //recursive case
    return NthTriangle(N-1) + N;
}
int main() {
    int N;
    cin >> N;
    cout<< NthTriangle(N);
}
