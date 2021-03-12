Given a sequence, find the length of the longest palindromic subsequence in it.

int lcs(int x, int y, string s1, string s2){

    int t[x+1][y+1];
    for(int i=0;i<x+1;i++){
        for(int j=0;j<y+1;j++){
            if(i==0 || j==0)
                t[i][j]=0;
        }
    }

    for(int i=1;i<x+1;i++){
        for(int j=1;j<y+1;j++){
            if(s1[i-1]==s2[j-1])
                t[i][j]= 1+t[i-1][j-1];
            else
                t[i][j]= max(t[i-1][j],t[i][j-1]);
        }
    }

    return t[x][y];
}

int longestPalindromeSubseq(string s){
  int x=s.length();
  string a=s;
  reverse(a.begin(), a.end());
  return lcs(x,x,s,a);
}
