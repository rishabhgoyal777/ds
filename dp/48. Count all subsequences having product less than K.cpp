Given a non negative array, find the number of subsequences having product smaller than K.

Examples:
Input : [1, 2, 3, 4]
        k = 10
Output :11
The subsequences are {1}, {2}, {3}, {4},
{1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4},
{1, 2, 3}, {1, 2, 4}

Input  : [4, 8, 7, 2]
         k = 50
Output : 9

t[i][j] denoting no of subsequences possible with product less than i with first j terms of array

int productSubSeqCount(vector<int> &arr, int k){
  int n=arr.size();
  int t[k+1][n+1];

  memset(t,0;sizeof(t));

  for(int i=1;i<=k;i++){
    for(int j=1;j<=n;j++){
      t[i][j] = t[i][j-1];  // j-1 terms tak jo ans hai wo to hoga hi plus

      if(arr[j-1] <=i)                 // agar current element req product se chota hai toh
        t[i][j]+= t[i/arr[j-1]][j-1] + 1;  //ek nyi subseq, adding it. 1 add krliya ans mei. ex; product is 20. curr elemnt is 3 so ans = ans till prev index + ans of product 20/3=6 + 1(adding 3 in subsequence creates new subsequence)
    }
  }
  return t[k][n];


}
