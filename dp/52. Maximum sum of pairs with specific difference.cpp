Given an array of integers and a number k. We can pair two number of the array if the difference between them is strictly less than k. The task is to find the maximum possible sum of disjoint pairs. Sum of P pairs is the sum of all 2P numbers of pairs.
Examples:

Input  : arr[] = {3, 5, 10, 15, 17, 12, 9}, K = 4
Output : 62
Explanation:
Then disjoint pairs with difference less than K are, (3, 5), (10, 12), (15, 17)
So maximum sum which we can get is 3 + 5 + 12 + 10 + 15 + 17 = 62
Note that an alternate way to form disjoint pairs is, (3, 5), (9, 12), (15, 17), but this pairing produces lesser sum.

int maxSumPairWithDifferenceLessThanK(int arr[], int n, int k)
    {
        sort(arr, arr+n, greater<int>());   // we want max sum so in decreasing order

        int i=0;
        int sum=0;

        while(i<n-1){
            if(arr[i]-arr[i+1]<k){
                sum+=arr[i]+arr[i+1];
                i+=2;
            }
            else
                i++;
        }
        return sum;
    }
