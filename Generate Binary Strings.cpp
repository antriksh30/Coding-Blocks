#include <iostream>
using namespace std;

void GenerateBinary(string str, int i = 0){
    // Base case
    if(str[i] == '\0'){
        cout << str << " ";
        return;
    } 
    // Recursive case
    if(str[i] == '?'){
        str[i] = '0';
        GenerateBinary(str, i+1);

        str[i] = '1';
        GenerateBinary(str, i+1);
    }
    else{
        GenerateBinary(str, i+1);
    }
}
int main() {
    int testcases;
    cin >> testcases;
    for(int i = 1; i <= testcases; i++){
        string str;
        cin >> str;
        GenerateBinary(str);
		cout << endl;
    }
    return 0;
}
