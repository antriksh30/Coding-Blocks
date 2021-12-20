#include <iostream>
#include <set>
using namespace std;

void Permutations(char* inp, set<string>& s, int i){
    //base case
    if(inp[i]=='\0'){
        s.insert(string(inp));
        return;
    }
    //recursive case
    for(int j=i; inp[j]!='\0'; j++){
        swap(inp[i],inp[j]);
        Permutations(inp, s, i+1);
        swap(inp[i],inp[j]);
    }
}
int main() {
    char inp[11];
    cin>>inp;
    set<string> s;
    Permutations(inp, s, 0);
    auto posn = s.find(string(inp));
    for(auto it= s.begin(); it != posn; it++) {
		cout << *(it) << endl;
	}
    return 0;
}
