class Solution{
public:

    long long nPr(int n, int r){
        long long t[n+1][r+1];

        for(int i=0;i<=n;i++){
            for(int j=0;j<=min(i,r);j++){
                if(j==0)
                    t[i][j]=1;
                else{
                    t[i][j]= t[i-1][j] + t[i-1][j-1]*j;
                }
                t[i][j+1]=0;
            }
        }
        return t[n][r];
    }
};

======================================
nPr = n!/(n-r)!

class Solution{
public:
    long long nPr(int n, int r){
        long long int arr[n+1];
        arr[0]=1;
        for(int i=1;i<=n;i++){
            arr[i]=i*arr[i-1];
        }
        return arr[n]/arr[n-r];
    }
};
