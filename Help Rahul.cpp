#include<iostream>
using namespace std;

int search(int* A, int s, int e,int t){
    
    if (s > e)  return -1; 

    int mid = s + (e-s)/2;
    if (A[mid] == t)  return mid; 
    // If A[s...mid] is sorted 
    if (A[s] <= A[mid]) { 
        if (t >= A[s] && t <= A[mid]) 
            return search(A, s, mid-1, t); 

        return search(A, mid+1, e, t); 
    } 
    if (t >= A[mid] && t <= A[e]) 
        return search(A, mid+1, e, t); 

    return search(A, s, mid-1, t); 
}



int main(){
    int n;
    cin >> n;

    int* A = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int t;
    cin >> t;

    cout << search(A, 0, n-1, t) << endl;
    return 0;
}