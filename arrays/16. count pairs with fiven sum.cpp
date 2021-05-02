Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum is equal to K.
Example 1:

Input:
N = 4, K = 6
arr[] = {1, 5, 7, 1}
Output: 2
Explanation:
arr[0] + arr[1] = 1 + 5 = 6
and arr[1] + arr[3] = 5 + 1 = 6.

int getPairsCount(int arr[], int n, int k) {
        map<int,int> m;
        int count=0;
        for(int i=0;i<n;i++){
            if(m[k-arr[i]]){
                count+=m[k-arr[i]];
            }
            m[arr[i]]++;
        }
        return count;
    }
