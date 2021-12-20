#include <iostream>
using namespace std;

char strings[] = {'a','b','c','d','e','f','g','h','i','j','k','l'
                ,'m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int idx = 0;
void stringCodes(string inp, char* out, int i, int j, string ans[100]){
    //base case
    if( i == inp.length()){
        out[j] = '\0';
        ans[idx] = string(out);
        idx++;
        return;
    }
    if( i > inp.length()){
        return;
    }
    //recursive case
    int d = stoi(inp.substr(i,1));
    out[j] = strings[d-1];
    stringCodes(inp,out,i+1,j+1,ans);

    d = stoi(inp.substr(i,2));
    if(d<=26){
        out[j] = strings[d-1];
        stringCodes(inp,out,i+2,j+1,ans);
    }
}

int main() {
    string inp;
    cin>>inp;
    char out[100];
    string ans[100];
    stringCodes(inp,out,0,0,ans);
    cout<<"[";
    for(int i=0;i<idx;i++){
        (i==idx-1) ? cout<<ans[i] : cout<<ans[i]<<", ";
    }
    cout<<"]";
    return 0;
}
