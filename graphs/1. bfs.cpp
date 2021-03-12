vector <int> bfs(vector<int> g[], int N) {

    queue<int> q;
    vector<int> ans;
    int vis[N]={0};

    q.push(0);
    vis[0]=1;

    while(!q.empty()){
      int temp=q.front();
      ans.push_back(temp);
      q.pop();

      for(auto x:g[temp]){
        if(!vis[x]){
          q.push(x);
          vis[x]=1;
        }
      }

    }
    return ans;
}
