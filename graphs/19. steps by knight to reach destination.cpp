class Solution {
public:
  bool vis[1000][1000];

  void stepsm(int X, int Y,int dr,int dc,queue<pair<int,int>> &q, int &count, bool &flag, int N){
    int x[]={-1,-1,1,1,2,2,-2,-2};     // possible steps by knight in all directions
    int y[]={2,-2,2,-2,1,-1,1,-1};
    for(int i=0;i<8;i++){
      if(X+x[i]<0 || X+x[i]>=N || Y+y[i]<0 || Y+y[i]>=N || vis[X+x[i]][Y+y[i]])
        continue;
      if(X+x[i]==dr && Y+y[i]==dc){ // agar destination aagyi true krdiya
        flag=true;
        return;
      }
      q.push({X+x[i],Y+y[i]});    // wrna iss nyi position ko q mein push aur vis true krdiya
      vis[X+x[i]][Y+y[i]]=true;
    }
  }

  int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    int sr=KnightPos[0]-1;  // -1 to make it 0 indexing. que mei indexing 1 se hai
	    int sc=KnightPos[1]-1;
      int dr=TargetPos[0]-1;
      int dc=TargetPos[1]-1;
      int steps=0;
      int count=0;
      if(sr==dr && sc==dc)
        return 0;

     for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            vis[i][j] = false;

      queue<pair<int,int>> q;
      q.push({sr,sc});
      vis[sr][sc]=true;
      count=q.size();

      bool flag=false;
      while(count>0){
          steps++;
        for(int i=0;i<count;i++){
          pair<int,int> p=q.front();
          q.pop();
          stepsm(p.first, p.second,dr,dc,q,count,flag,N);
          if(flag) return steps;
        }
        count=q.size();
      }
      return -1;
	}
};
