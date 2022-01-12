#include <iostream>
#include <climits>
using namespace std;

int numofpainters(int n, int* len, int timelimit){
    int time = 0;
    int numpainters = 1;
    for(int i=0; i<n; i++){
        time += len[i];
        if (time > timelimit){
            numpainters++;
            time = len[i];
        }
    }
    return numpainters;
}

int minimumTime(int k, int n, int* len){
    int s = INT_MIN;
    int e = 0;
    for(int i=0; i<n; i++){
        s = max(s,len[i]);
        e += len[i];
    }
    int ans;
    while (s <= e){
        int m = s + (e-s)/2;
        int x = numofpainters(n, len, m);
        if(k >= x){
            ans = m;
            e = m-1;
        }
        else{
            s = m+1;
        }
    }
    return ans;
}

int main() {
    int k,n;
    cin >> k; // No of painters
    cin >> n; // No of boards

    int* len = new int[n];
    //Taking input length of boards
    for(int i=0; i<n; i++){
        cin>>len[i];
    }

    cout << minimumTime(k, n, len) << endl;

    return 0;
}
