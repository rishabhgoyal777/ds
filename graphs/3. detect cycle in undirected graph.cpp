bool isCyclicUtil(vector<int> g[], int V, int vis[], int start, int parent){
  vis[start]=1;

  for(auto x:g[start]){
    if(!vis[x]){
      if(isCyclicUtil(g,V,vis,x,start))
        return true;
    }
    else{
      if(x!=parent)
        return true;
    }
  }

  return false;
}

bool isCyclic(vector<int> g[], int V)
{
  bool flag= false;
   int vis[V]={0};
   for(int i=0;i<V;i++){
     if(!vis[i])
      if(isCyclicUtil(g,V,vis,i,-1))
          return true;
   }
  return false;
}
