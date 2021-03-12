similar to lcs bas jaha pe continuity tuuti waha pe 0 kr diya length. aur maximum length return kr denge

int lcs(int x, int y, string s1, string s2){
    int result=0;
    int t[x+1][y+1];
    for(int i=0;i<x+1;i++){
        for(int j=0;j<y+1;j++){
            if(i==0 || j==0)
                t[i][j]=0;
        }
    }

    for(int i=1;i<x+1;i++){
        for(int j=1;j<y+1;j++){
            if(s1[i-1]==s2[j-1]){
                t[i][j]= 1+t[i-1][j-1];
                result=max(result, t[i][j]);
            }
            else
                t[i][j]= 0;
        }
    }

    return result;
}
