jo matrix bnta lcs mei uske end se shuru krte.
dono mei se agar koi bhi string 0 waha tak krna bas.
agar dono index pe same character
    to include in ans and i-- j-- ( matrix mei diagonaly upar ja rhe)
else(not same character nwo we will not include it in answer)
    agar [i-1][j] wala bada hai [i][j-1] wale se
      to i-- jana mtrix mei
    else
      j-- krna hai.
==========================


string lcs(int x, int y, string s1, string s2){
  int t[x+1][y+1];
  for(int i=0;i<x+1;i++){
    for(int j=0;j<y+1;j++){
      if(i==0||j==0)
        t[i][j]=0;
    }
  }

  for(int i=1;i<x+1;i++){
    for(int j=1;j<y+1;j++){
      if(s1[i-1]==s2[j-1])
        t[i][j]= 1 + t[i-1][j-1];
      else
        t[i][j]= max(t[i-1][j], t[i][j-1]);
    }
  }
  int i=x; int j=y;
  string s="";
  while(i > 0 && j > 0){
    if(s1[i-1]==s2[j-1]){
      s.push_back(s1[i-1]);
      i--;
      j--;
    }
    else{
      if(t[i-1][j] > t[i][j-1])
        i--;
      else
        j--;
    }
  }
  reverse(s.begin(),s.end());
  return s;
}
