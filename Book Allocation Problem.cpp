#include <iostream>
using namespace std;

int numofstudents(int n, int* pages, int totalpages){
    int pagesread = 0;
    int student = 1;
    for(int i=0; i<n; i++){
        pagesread += pages[i];
        if(pagesread > totalpages){
            student++;
            pagesread = pages[i];
        }
    }
    return student;
}

int maxpages(int n, int m, int* pages){
    int s = pages[n-1];
    int e = 0;
    for(int i=0; i<n; i++){
        e += pages[i];
    }
    
    int ans;
    while (s <=e){
        int mid = s + (e-s)/2;
        int x = numofstudents(n, pages, mid);
        if (m >= x){
            ans = mid;
            e = mid-1;
        }else{
            s = mid+1;
        }
    }
    return ans;
    
}

int main() {
    int t;
    cin >> t; // No of testcases

    for(int testcase = 0; testcase < t; testcase++){
        int n,m;
        cin >> n >> m;
        int* pages = new int[n];
        for(int i=0; i<n; i++){
            cin >> pages[i];
        }

        cout << maxpages(n, m, pages) << endl;
    }
    return 0;
}
