int lrs(int x, string s1){

    int t[x+1][x+1];
    for(int i=0;i<x+1;i++){
        for(int j=0;j<x+1;j++){
            if(i==0 || j==0)
                t[i][j]=0;
        }
    }

    for(int i=1;i<x+1;i++){
        for(int j=1;j<x+1;j++){
            if(s1[i-1]==s1[j-1] && i != j)
                t[i][j]= 1+t[i-1][j-1];
            else
                t[i][j]= max(t[i-1][j],t[i][j-1]);
        }
    }

    return t[x][x];
}

printing lrs
    string res = "";
    int i = n, j = n;

    while (i > 0 && j > 0)
    {
        if (dp[i][j] == dp[i-1][j-1] + 1)
        {
           res = res + str[i-1];
           i--;
           j--;
        }

        else if (dp[i][j] == dp[i-1][j])
            i--;
        else
            j--;
    }
    reverse(res.begin(), res.end());
    return res;
}
