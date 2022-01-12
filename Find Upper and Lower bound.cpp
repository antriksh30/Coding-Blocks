#include<iostream>
using namespace std;

int findLowerBound(int num, int* A,int n){
    int lowerBound = -1;

    int s=0;
    int e=n;

    while(s <= e){
      int mid = s + (e-s)/2;
      if(A[mid]==num){
          lowerBound=mid;
          e=mid-1;
      }else if(A[mid]>num){
          e=mid-1;
      }else{
          s=mid+1;
      }
    }

    return lowerBound;
}

int findUpperBound(int num, int* A,int n){
    int upperBound =-1;

    int s=0;
    int e=n;

    while(s <= e){
      int mid = s + (e-s)/2;
      if(A[mid]==num){
          upperBound=mid;
          s=mid+1;
      }else if(A[mid]>num){
          e=mid-1;
      }else{
          s=mid+1;
      }
    }

    return upperBound;
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

    while(t--){
        int num;
        cin >> num;

        int lowerBound = findLowerBound(num,A,n);
        int upperBound = findUpperBound(num,A,n);

        cout << lowerBound<<" "<<upperBound <<endl;
    }
    return 0;
}