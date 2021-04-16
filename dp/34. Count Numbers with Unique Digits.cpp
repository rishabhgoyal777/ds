Given an integer n, return the count of all numbers with unique digits, x, where 0 <= x < 10n.
Example 1:

Input: n = 2
Output: 91
Explanation: The answer should be the total numbers in the range of 0 ≤ x < 100, excluding 11,22,33,44,55,66,77,88,99
Example 2:

Input: n = 0
Output: 1


class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int t[n+1];
        t[0]=1;
        int d=0; // duplicates
        int nd=0; //non duplicates

        for(int i=1;i<=n;i++){
            d=d*10 + nd*(i-1);
            nd=pow(10,i)-pow(10,i-1)-d; // total numbers with that digits - dupliactes
            t[i]=nd+t[i-1];  // submation with previous values
        }

        return t[n];
    }
};
