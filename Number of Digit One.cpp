/*
Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

Example 1:

Input: n = 13
Output: 6
Example 2:

Input: n = 0
Output: 0
 

Constraints:

0 <= n <= 109
*/

/*   
         Runtime Error(Time Complexity)
class Solution {
public:
    int countDigitOne(int n) {
        //base case
        if(n==0) return 0;
        //recursive case
        int x = countDigitOne(n-1);
        while(n>0){
            if(n%10 == 1) x++;
            n/=10;
        }
        return x;
    }
};
*/

class Solution {
public:
    int countDigitOne(int n){
        int count = 0;
        for (long long i = 1; i <= n; i *= 10) {
            long long d = i * 10;
            count += (n / d) * i + min(max(n % d - i + 1, 0LL), i);
        }
        return count;
    }
};