Given a sequence of positive numbers, find the maximum sum that can be formed which has no three consecutive elements present.
Examples :

Input: arr[] = {1, 2, 3}
Output: 5
We can't take three of them, so answer is
2 + 3 = 5

Input: arr[] = {3000, 2000, 1000, 3, 10}
Output: 5013
3000 + 2000 + 3 + 10 = 5013


int maxSumWO3Consec(int arr[], int n){
  if(n==0)
    return 0;
  if(n==1)
    return arr[0];
  if(n==2)
    return arr[0]+arr[1];

  if(t[n]!=-1)
    return t[n];

  return t[n]=max(max(maxSumWO3Consec(arr,n-1), arr[n]+ maxSumWO3Consec(arr,n-2), arr[n]+arr[n-1]+maxSumWO3Consec(arr,n-3);
}
