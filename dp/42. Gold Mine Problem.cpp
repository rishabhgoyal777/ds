Given a gold mine called M of (n x m) dimensions. Each field in this mine contains a positive integer which is the amount of gold in tons. Initially the miner can start from any row in the first column. From a given cell, the miner can move
to the cell diagonally up towards the right
to the right
to the cell diagonally down towards the right
Find out maximum amount of gold which he can collect.
==================================================================

int maxGold(int n, int m, vector<vector<int>> M)
{
    int t[n][m];
    memset(t,0,sizeof(t));

    for(int i=0;i<n;i++){
        t[i][0]=M[i][0];      // Initiallised 1st column same as mine matrix
    }

    for(int j=1;j<m;j++){     //for rest columns
        for(int i=0;i<n;i++){
            //taking max way possible to reaching [i][j] => Max from (1,2,3) and added value in that. 
            t[i][j]=t[i][j-1];             //1. if moved right
            if(i>0)
                t[i][j]=max(t[i][j], t[i-1][j-1]);   //2. moved to the cell diagonally down towards the right

            if(i<n-1)
                t[i][j]=max(t[i][j], t[i+1][j-1]); //3. moved to the cell diagonally up towards the right

            t[i][j]+=M[i][j];
        }
    }

    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        ans=max(ans,t[i][m-1]);
    }
    return ans;
}
