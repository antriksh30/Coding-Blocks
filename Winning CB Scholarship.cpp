#include<iostream>

using namespace std;

int numofscholarStudents(int n, int m, int x, int y) {
    
    int remstudents = 0;
    int leftcoupons = 0;
    int scholarstudents = m/x;
    if(n > scholarstudents){
        leftcoupons = m % x;
    }
    else{
        return n;
    }
    remstudents = n - scholarstudents;
    while(remstudents > 1){
        leftcoupons += y;
        remstudents--;
        if(leftcoupons >= x){
            int temp = leftcoupons/x;
            if(remstudents >= temp){
                scholarstudents += temp;
                remstudents -= temp;
                leftcoupons = leftcoupons % x;
            }else{
                scholarstudents += remstudents;
                break;
            }
        }
    }   
    return scholarstudents;
    

}

int main() {

	int n,m,x,y;
    cin >> n >> m >> x >> y;
	cout << numofscholarStudents(n, m, x, y) << endl;

	return 0;
}