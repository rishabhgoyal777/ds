applying bfs


class Solution {
public:
    void rot(vector<vector<int>>& grid,int X, int Y, queue<pair<int,int>>& q, int r, int c){
      int x[]={-1,1,0,0};
      int y[]={0,0,-1,1};
      for(int i=0;i<4;i++){
        if(X+x[i]<0 || Y+y[i]<0 || X+x[i]>=r || Y+y[i]>=c || grid[X+x[i]][Y+y[i]]!=1)
          continue;
        grid[X+x[i]][Y+y[i]]=2;
        q.push({X+x[i],Y+y[i]});
      }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int r=grid.size();
        int c=grid[0].size();

        for(int i=0;i<r;i++){                 //push all currently rott indexes in queue
          for(int j=0;j<c;j++){
            if(grid[i][j]==2)
              q.push({i,j});
          }
        }
        int count=q.size();
        int time=0;
        while(count>0){
          for(int i=0;i<count;i++){         // for every index rot its 4 neighbour whichever possible
            pair<int,int> p=q.front();
            q.pop();
            rot(grid,p.first,p.second,q,r,c);
          }
          count=q.size();
          if(count>0)              // if after traversal any new rotted repeat process for these
            time++;
        }
        for(int i=0;i<r;i++){
          for(int j=0;j<c;j++){
            if(grid[i][j]==1)
              return -1;         // if any fresh present
          }
        }
        return time;
    }
};
