
jo matrix bnta lcs mei uske end se shuru krte.
dono mei se agar koi bhi string 0 waha tak krna
agar dono index pe same character
    to include in ans and i-- j-- ( matrix mei diagonaly upar ja rhe)
else(not same character)
    agar [i-1][j] wala bada hai [i][j-1] wale se
      to str1[i] ans mei daalke i-- jana mtrix mei
    else
      str2[j] ans mei daalke j-- krna hai.
 jab dono mei se ki bhi 0 hogyi string uske bad dusri string bchi hui as it ans mei add krlayi

class Solution {
public:
string shortestCommonSupersequence(string str1, string str2) {
  int m= str1.length();
  int n= str2.length();
  int t[m+1][n+1];
  for(int i=0;i<m+1;i++){
      for(int j=0;j<n+1;j++){
          if(i==0 || j==0)
              t[i][j]=0;
      }
  }

  for(int i=1;i<m+1;i++){
      for(int j=1;j<n+1;j++){
          if(str1[i-1]==str2[j-1])
              t[i][j]= 1+t[i-1][j-1];
          else
              t[i][j]= max(t[i-1][j],t[i][j-1]);
      }
  }

  int i=m; int j=n;
  string s="";
  while(i>0 && j>0){
    if(str1[i-1]==str2[j-1]){
      s.push_back(str1[i-1]);
      i--; j--;
    }
    else{
      if(t[i][j-1] > t[i-1][j]){
        s.push_back(str2[j-1]);
        j--;
      }
      else{
        s.push_back(str1[i-1]);
        i--;
      }
    }}
    while(i>0){
      s.push_back(str1[i-1]);
      i--;
    }
    while(j>0){
      s.push_back(str2[j-1]);
      j--;
    }
    reverse(s.begin(), s.end());
    return s;
  }
};
