#include <iostream>
using namespace std;

void GenerateParenthesis(int n, string str, int open = 0, int close = 0){
    //base case
    if(close == n){
        cout << str << endl;
        return;
    }
    //recursive case
    if(open != 0){
        if(open>close) 
            GenerateParenthesis(n,str + ")",open,close + 1);
        if(open<n) 
            GenerateParenthesis(n,str + "(",open + 1,close);
    }
    if(open == 0) GenerateParenthesis(n,str + "(",open + 1,close);
}
int main() {
    int N;
    cin >> N;
    string str = "";
    GenerateParenthesis(N, str);
    return 0;
}
