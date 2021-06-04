Input : arr[] = {1, 4, 5, 1}
Output : 1
We can make given array palindrome with
minimum one merging (merging 4 and 5 to
make 9)

Input : arr[] = {11, 14, 15, 99}
Output : 3
We need to merge all elements to make
a palindrome.
  
time complexity => O(n).
==========================
  
int findMinOps(int arr[], int n)
{
    int ans = 0; 

  for (int i=0,j=n-1; i<=j;)
    {
        if (arr[i] == arr[j])
        {
            i++;
            j--;
        }
         else if (arr[i] > arr[j])
        {
             j--;
            arr[j] += arr[j+1] ;
            ans++;
        }
       else
        {
            i++;
            arr[i] += arr[i-1];
            ans++;
        }
    }
    return ans;
}
