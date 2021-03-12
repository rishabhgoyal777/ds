A directed graph is strongly connected if there is a path between all pairs of vertices. A strongly connected component (SCC) of a directed graph is a maximal strongly connected subgraph.

void dfs(vector<int> adj[], int vis[], stack<int> &s, int V, int start){
  vis[start]=1;
  for(auto x: adj[start]){
    if(!vis[x]){
      dfs(adj,vis,s,V,x);
    }
  }
  s.push(start);
}

void dfs1(vector<int> adj[], int vis[], int V, int start){
  vis[start]=1;
  for(auto x: adj[start]){
    if(!vis[x]){
      dfs1(adj,vis,V,x);
    }
  }
}


int kosaraju(int V, vector<int> adj[]){
  int vis[V]={0};
  stack<int> s;
  for(int i=0;i<V;i++){
        if(!vis[i])
             dfs(adj,vis,s,V,i);
    }


  for(int i = 0; i < V; i++)
    vis[i] = 0;

  vector<int> adj1[V];
  for(int i=0;i<V;i++){
    for(int j=0;j<adj[i].size();j++){
      adj1[adj[i][j]].push_back(i);
    }
  }

  int count=0;
  while(!s.empty()){
    int t=s.top();
    s.pop();
    if(!vis[t]){
      dfs1(adj1,vis,V,t);
      count++;
    }
  }
  return count;
}
