#include <iostream>
using namespace std;

void LexOrder(int n, int a = 0){
    // Base Case
    if(a > n) return;

    // Recursive Case
    int i;
    cout << a << " ";
    (a == 0)? i = 1 : i = 0;
    while(i <= 9){
      if( a*10 + i > n) break; //Optimisataion
      LexOrder(n, a*10 + i);
      i++;
    }
}


int main() {
    int N;
    cin >> N;
    LexOrder(N);

    return 0;
}
