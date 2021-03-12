Given a graph and a source vertex src in graph, find shortest paths from src to all vertices in the given graph. The graph may contain negative weight edges.

vector<int> bellman(vector<vector<int>> g, int source, int N){
  vector<pair<int,int>> edgelist;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(g[i][j]){
        edgelist.push_back(make_pair(i,j));
      }
    }
  }
  vector<int> distance(N,INT_MAX);
  distance[source]=0;

  for(int i=0;i<N-1;i++){ // iterating over edgelist n-1 times. cuz it is possible that we are finding distance and after that
                          // ther vertex has been relaxed so its new distance should be taken. iterated n-1 time.
    for(int j=0;j<edgelist.size();j++){      // iterating over edgelist
      int u=edgelist[j].first;
      int v=edgelist[j].second;
      if(distance[u]!=INT_MAX && distance[u] + g[u][v] < distance[v]){
        distance[v]=distance[u] + g[u][v];
      }
    }
  }
  return distance;
}
