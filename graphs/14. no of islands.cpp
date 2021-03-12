Given a boolean 2D matrix, find the number of islands. A group of connected 1s forms an island. For example, the below matrix contains 5 islands

Example:

Input : mat[][] = {{1, 1, 0, 0, 0},
                   {0, 1, 0, 0, 1},
                   {1, 0, 0, 1, 1},
                   {0, 0, 0, 0, 0},
                   {1, 0, 1, 0, 1}
Output : 5

convert this array to bool array .Where water mark as visited. where land mark as unvisited. now make dfs calls on unvisited and count no. of dfs calls. that will be ans. 1 element has 8 neighbours


class Solution {
public:
    bool ans[500][500];

    bool valid(int x, int y, int n, int m){
      if(x>=0 && y>=0 && x<n && y<m && ans[x][y]==false)
        return true;
      return false;
    }

    void dfs(int x, int y, int n, int m){
      ans[x][y]=true;
      for(int i=-1;i<2;i++){                  //these loop cover 9 points. 8 neighbours + point itself
        for(int j=-1;j<2;j++){
          if(i==j && i==0)                    // leave the point itself
            continue;
          if(valid(x+i,y+j,n,m))              //  check if neighbour is unvisited and possible inside array boundaries
            dfs(x+i,y+j,n,m);                   // then call dfs on neighbour
        }
      }
    }

    int numIslands(vector<vector<char>>& grid) {
      int n=grid.size();
      int m=grid[0].size();

      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
          if(grid[i][j] == '0')
            ans[i][j] = true;
          if(grid[i][j] == '1')
            ans[i][j] = false;
        }
      }

      int count=0;
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
          if(!ans[i][j]){
            dfs(i,j,n,m);
            count++;
          }
        }
      }
      return count;
    }
};
