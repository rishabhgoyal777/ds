Given 3 strings A, B and C, the task is to find the longest common sub-sequence in all three given sequences.

Example 1:
Input:
A = "geeks", B = "geeksfor",
C = "geeksforgeeks"
Output: 5
Explanation: "geeks"is the longest common
subsequence with length 5.


int LCSof3 (string a, string b, string c, int n, int m, int p)
{
  int t[n+1][m+1][p+1];
  memset(t,0,sizeof(t));

  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
        for(int k=1;k<=p;k++){
          if(a[i-1]==b[j-1] && b[j-1]==c[k-1])
            t[i][j][k]=t[i-1][j-1][k-1]+1;
          else
            t[i][j][k]=max(max(t[i-1][j][k], t[i][j-1][k]), t[i][j][k-1]);
        }
    }
  }
  return t[n][m][p];
}
