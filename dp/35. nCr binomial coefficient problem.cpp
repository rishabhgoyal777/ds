class Solution{
public:
    int t[1001][801];

    int nCr(int n, int r){
        for(int i=0;i<=n;i++){
            for(int j=0;j<=min(i,r);j++){
                if(j==0)
                    t[i][j]=1;
                else{
                    t[i][j]=(t[i-1][j-1]+ t[i-1][j])%1000000007;
                }
            }
        }
        return t[n][r];
    }
};
