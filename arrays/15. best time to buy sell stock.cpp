You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currPrice=INT_MAX;
        int profit=0;
        int n = prices.size();
        for(int i=0;i<n;i++){
            if(prices[i] < currPrice){
                currPrice = prices[i];
            }
            else if(prices[i] - currPrice > profit){
                profit = prices[i] - currPrice;
            }
        }
        return profit;
    }
};

================================================================================================================================

GFG
=========================================
The cost of stock on each day is given in an array A[] of size N. Find all the days on which you buy and sell the stock so that in between those days your profit is maximum.
Note: There may be multiple possible solutions. Return any one of them.

Example 1:

Input:
N = 7
A[] = {100,180,260,310,40,535,695}
Output:
1
Explanation:
One possible solution is (0 3) (4 6)
We can buy stock on day 0,
and sell it on 3rd day, which will
give us maximum profit. Now, we buy
stock on day 4 and sell it on day 6.

vector<vector<int> > stockBuySell(vector<int> a, int n){
        int i=0;
        vector<vector<int>> res;

        while(i<n-1){

            while( (i<n-1) && (a[i+1] <= a[i]) )   //find buy index. lowest value (local minima)
                i++;

            if(i==n-1)
                break;

            int temp1 = i;  //buy index

            while( (i<n-1) && (a[i+1] >= a[i]))   // find sell index. Highest value (local maxima)
                i++;

            int temp2=i;   //sell index

            res.push_back({temp1, temp2});

            i++; // find next buy & sell index

        }
        return res;
    }
