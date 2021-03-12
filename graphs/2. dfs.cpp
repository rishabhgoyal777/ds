void dfsUtil(vector<int> g[], int N, int start, int vis[], vector<int> &v){

  v.push_back(start);
  vis[start]=1;

  for(auto x:g[start]){
    if(!vis[x]){
      dfsUtil(g,N,x,vis,v);
    }
  }
}

vector <int> dfs(vector<int> g[], int N)
{
    vector<int> v;
    int vis[N]={0};
    dfsUtil(g,N,0,vis,v);
    return v;
}
