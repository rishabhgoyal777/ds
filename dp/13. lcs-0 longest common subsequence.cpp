LCS Problem Statement: Given two sequences, find the length of longest subsequence present in both of them. A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous. For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are subsequences of “abcdefg”.
LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.
LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4.


RECURSION - agar same letter to add 1 and recursion. Agar nhi same to ya s1 ka letter rkhe ge aur s2 ke next pe jayege ya ulta. aur iska
            max nikal liya
==============
int lcs(int x, int y, string s1, string s2){
  if(x==0 || y==0 )
    return 0;
  if(s1[x-1] == s2[y-1])
    return 1 + lcs(x-1,y-1,s1,s2);
  else
    return max(lcs(x-1,y,s1,s2), lcs(x,y-1,s1,s2) );
  }
}


TOPDOWN - globally matrix declare kr di, main function mei memmset se -1 initialise krdi.
=========
int lcs(int x, int y, string s1, string s2){
  if(x==0 || y==0 )
    return 0;
  if(t[x][y] != -1)
    return t[x][y];
  if(s1[x-1] == s2[y-1])
    return t[x][y] = 1 + lcs(x-1,y-1,s1,s2);
  else
    return t[x][y] = max(lcs(x-1,y,s1,s2), lcs(x,y-1,s1,s2) );
  }
}

BOTTOM UP
============
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
