Given a string, a partitioning of the string is a palindrome partitioning if every substring of the partition is a palindrome. For example, “aba|b|bbabb|a|b|aba” is a palindrome partitioning of “ababbbabbababa”. Determine the fewest cuts needed for a palindrome partitioning of a given string. For example, minimum of 3 cuts are needed for “ababbbabbababa”. The three cuts are “a|babbbab|b|ababa”. If a string is a palindrome, then minimum 0 cuts are needed. If a string of length n containing all different characters, then minimum n-1 cuts are needed.
class Solution {
public:

  int t[2001][2001];

  bool isPalindrome(string str,int i,int j){
    while(i<j){
      if(str[i] != str[j])
          return false;
      i++;
      j--;
    }
    return true;
  }

  int palindromicPartitionUtil(string str, int i, int j){
    if(i>=j)
      return 0;
    if(isPalindrome(str,i,j)==true)
      return 0;
    if(t[i][j]!=-1)
      return t[i][j];
    int ans=INT_MAX;
    for(int k=i;k<=j-1;k++){
      int l=-1;
      int r=-1;
      if(t[i][k]!=-1)
          l=t[i][k];
      else{
          l=palindromicPartitionUtil(str,i,k);
          t[i][k]=l;}
      if(t[k+1][j]!=-1)
          r=t[k+1][j];
      else{
          r=palindromicPartitionUtil(str,k+1,j);
          t[k+1][j]=r;
        }
      int temp=1+ l + r;
      ans= min(ans,temp);
    }
    return t[i][j]=ans;
  }

  int minCut(string str) {
    memset(t,-1,sizeof(t));
    int n=str.length();
    return palindromicPartitionUtil(str,0,n-1);
  }
};




tle on last case. incomplete
