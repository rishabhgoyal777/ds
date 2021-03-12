bool isCyclicUtil(int V, vector<int> adj[],int vis[], int start, int parents[]){
  vis[start]=1;
  parents[start]=1;

  for(auto x:adj[start]){
    if(!vis[x]){
      if(isCyclicUtil(V,adj,vis,x,parents))
        return true;
    }
    else{
      if(parents[x])
        return true;
    }
  }
  parents[start]=0;
  return false;
}


bool isCyclic(int V, vector<int> adj[])
{
    int vis[V]={0};
    int parents[V]={0};
    for(int i=0;i<V;i++){
      if(!vis[i])
        if(isCyclicUtil(V,adj,vis,i,parents))
            return true;
    }
    return false;
}
