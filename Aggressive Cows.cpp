#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

bool canPlaceCows(int n, int c, int* pos, int m) {
	// place the 1st cow in the stall at the 0th pos
	int numOfCowsPlaced = 1;
	int prevCowPosition = pos[0];
	for(int i=1; i<n; i++) {
		// can I place the next cow at the ith stall
		if(pos[i]-prevCowPosition >= m) {
			// you can place the next cow at the ith stall
			numOfCowsPlaced++;
			prevCowPosition = pos[i];
			if(numOfCowsPlaced == c) {
				return true;
			}
		}
	}
	return false;
}

int largestMinDist(int n, int c, int* pos) {

	int s = INT_MAX; 
	int e = pos[n-1]-pos[0];
	for(int i=1; i<n; i++) {
		if(pos[i]-pos[i-1] < s) {
			s = pos[i]-pos[i-1];
		}
	}

	int ans;

	while(s <= e) {
		int m = s + (e-s)/2;
		if(canPlaceCows(n, c, pos, m)) {
			ans = m;
			s = m+1;
		} else {
			e = m-1;
		}
		
	}

	return ans;

}

int main() {

	int n, c;
	int* pos = new int[n];

    cin >> n >> c;
    for(int i=0; i<n; i++) {
        cin >> pos[i];
    }
    sort(pos, pos+n);
    cout << largestMinDist(n, c, pos) << endl;

	return 0;
}