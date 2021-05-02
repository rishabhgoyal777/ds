Given a NxN matrix of positive integers. There are only three possible moves from a cell Matrix[r][c].

Matrix [r+1] [c]
Matrix [r+1] [c-1]
Matrix [r+1] [c+1]
â€‹Starting from any column in row 0, return the largest sum of any of the paths up to row N-1.
Example 1:

Input: N = 2
Matrix = {{348, 391},
          {618, 193}}
Output: 1009
Explaination: The best path is 391 -> 618.
It gives the sum = 1009.


int maximumPath(int n, vector<vector<int>> m)
    {
        int t[n][n];

        for(int j=0;j<n;j++){  //initilaising 1st row as it is
            t[0][j]=m[0][j];
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){

                if(j>0 && j<n-1){
                    t[i][j]=max(max(t[i-1][j],t[i-1][j-1]), t[i-1][j+1]) + m[i][j];
                }

                else if(j>0){
                    t[i][j]=max(t[i-1][j],t[i-1][j-1]) + m[i][j];
                }

                else if(j<n-1){
                    t[i][j]=max(t[i-1][j],t[i-1][j+1]) + m[i][j];
                }
            }
        }
        int ans=INT_MIN;
        for(int j=0;j<n;j++){                  //max ans in last row
            ans=max(ans,t[n-1][j]);
        }
        return ans;
    }
