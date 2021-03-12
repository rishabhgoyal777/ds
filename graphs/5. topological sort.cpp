void topoSortUtil(int V, vector<int> adj[], int vis[], stack<int> &s,int start){
  vis[start]=1;

  for(auto x:adj[start]){
    if(!vis[x]){
      topoSortUtil(V,adj,vis,s,x);
    }
  }
  s.push(start);
}

vector<int> topoSort(int V, vector<int> adj[]) {
    int vis[V]={0};
    vector<int> ans;
    stack<int> s;
    for(int i=0;i<V;i++){
        if(!vis[i])
            topoSortUtil(V,adj,vis,s,0);
    }
    while(!s.empty()){
      ans.push_back(s.top());
      s.pop();
    }
    return ans;
}
