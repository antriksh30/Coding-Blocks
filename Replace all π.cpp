#include <iostream>
using namespace std;

void ReplacePi(char* inp,int i){
    //base case
    if(inp[i]=='\0') return;
    //recursive case
    if(inp[i]=='p' && inp[i+1]=='i'){
        int j=i+2;
        while(inp[j]!='\0'){
            j++;
        }
        while(j>=i+2){
            inp[j+2]=inp[j];
            j--;
        }
        inp[i]='3';
        inp[i+1]='.';
        inp[i+2]='1';
        inp[i+3]='4';
        ReplacePi(inp,i+4);
    }else{
        ReplacePi(inp,i+1);
    }
}

int main(){
    int N;
    cin>>N;
    for(int i=1;i<=N;i++){
        char inp[2000];
        cin>>inp;
        ReplacePi(inp,0);
        cout<<inp<<endl;

    }
    return 0;
}