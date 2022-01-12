#include<iostream>
#include<climits>

using namespace std;

int numOfPratasCookedByACook(int r, int timeLimit) {
	int count = 0; 
	int time = 0; 
	int n = 1;    
	while(true) {
		// ask the 'r' ranked cook to cook the nth prata
		time += r*n;
		if(time > timeLimit) {
			break;
		}
		count++;
		n++;
	}

	return count;
}

int numOfPratasCooked(int l, int* ranks, int timeLimit) {
	int totalPratas = 0;
	for(int i=0; i<l; i++) {
		totalPratas += numOfPratasCookedByACook(ranks[i], timeLimit);
	}
	return totalPratas;
}

int getMinTime(int p, int l, int* ranks) {
	int s = 0; 
	int e = INT_MAX;
	int ans;
	while(s <= e) {
		int m = s+(e-s)/2;
		int x = numOfPratasCooked(l, ranks, m);
		if(x >= p) {
			ans = m;
			e = m-1;
		} else {
			s = m+1;
		}
	}
	return ans;
}

int main() {

	int p, l;
	int* ranks = new int[l];

    cin >> p >> l;
    for(int i=0; i<l; i++) {
        cin >> ranks[i];
    }
    cout << getMinTime(p, l, ranks) << endl;

	return 0;
}
