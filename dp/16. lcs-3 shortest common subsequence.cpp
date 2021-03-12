Given two strings str1 and str2, the task is to find the length of the shortest string that has both str1 and str2 as subsequences.
Examples :
Input:   str1 = "geek",  str2 = "eke"
Output: 5
Explanation:
String "geeke" has both string "geek"
and "eke" as subsequences.

Input:   str1 = "AGGTAB",  str2 = "GXTXAYB"
Output:  9
Explanation:
String "AGXGTXAYB" has both string
"AGGTAB" and "GXTXAYB" as subsequences.

add both the strings and subtract the lcs. As the common character in both strings should be wriiten only once.

int shortestCommonSupersequence(char* X, char* Y, int m, int n) {
  int t[m+1][n+1];
  for(int i=0;i<m+1;i++){
      for(int j=0;j<n+1;j++){
          if(i==0 || j==0)
              t[i][j]=0;
      }
  }

  for(int i=1;i<m+1;i++){
      for(int j=1;j<n+1;j++){
          if(X[i-1]==Y[j-1])
              t[i][j]= 1+t[i-1][j-1];
          else
              t[i][j]= max(t[i-1][j],t[i][j-1]);
      }
  }
  return m+n-t[m][n];
}
