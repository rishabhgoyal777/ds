Given a cost matrix cost[][] and a position (m, n) in cost[][], write a function that returns cost of minimum cost path to reach (m, n) from (0, 0). Each cell of the matrix represents a cost to traverse through that cell. The total cost of a path to reach (m, n) is the sum of all the costs on that path (including both source and destination). You can only traverse down, right and diagonally lower cells from a given cell, i.e., from a given cell (i, j), cells (i+1, j), (i, j+1), and (i+1, j+1) can be traversed. You may assume that all costs are positive integers.


int minCost(int cost[R][C], int m, int n){
  int t[R][C];
   t[0][0]= cost[0][0];

   for(int i=1;i<=m;i++){
     t[i][0]=t[i-1][0]+cost[i][0];
   }
   for(int j=1;j<=n;j++){
     t[0][j]=t[0][j-1]+cost[0][j];
   }

   for(int i=1;i<=m;i++){
     for(int j=1;j<=n;j++){
       t[i][j]=min(min(t[i-1][j-1], t[i][j-1]), t[i-1][j])+cost[i][j];
     }
   }
   return t[m][n];
}
