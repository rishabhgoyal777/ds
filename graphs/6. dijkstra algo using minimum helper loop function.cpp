

// function for returning node that is not processed yet and is closest to the source
int minimum(int processed[], int distance[], int N){
  int m=INT_MAX;
  int index;
  for(int i=0;i<N;i++){
    if(!processed[i] && distance[i]<m){
      index=i; m=distance[i];
    }
  }
  return index;
}

vector<int> dijkstra(vector<vector<int>> &g, int N, int source){
//initialization
  int processed[N]={0};
  int distance[N];
  for(int i=0;i<N;i++)
  distance[i]=INT_MAX;
  distance[source]=0;
// nonprocessed closest node dhundo usko processed krdo aur phir uske neighbours ka relax krdo. dekho ki, kya unka distance source se through this node < their original distance. agar hai to use nye se update krdo
  for(int i=0;i<N;i++){
    int u = minimum(processed,distance,N);
    processed[u]=1;

    for(int v=0;v<N;v++){
      if(g[u][v]){
        if(distance[u] + g[u][v] > distance[v])
          distance[v]=distance[u] + g[u][v];
      }
    }
  }
}
