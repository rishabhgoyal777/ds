Given a graph and a source vertex in the graph, find shortest paths from source to all vertices in the given graph.

vector <int> dijkstra(vector<vector<int>> g, int source, int N){

  vector<int> distance(N,INT_MAX);
  distance[source]=0;

  set<pair<int,int>>s;
  s.insert(make_pair(distance[source],source));

  while(!s.empty()){
    auto itr= *(s.begin());
    int u=itr.second;
    s.erase(s.begin());

    for(int v=0;v<N;v++){
      if(g[u][v]){
        if(distance[u]!=INT_MAX && distance[u] + g[u][v] < distance[v]){
          auto it= s.find(make_pair(distance[v],v));
          if(it != s.end()){
            s.erase(it);}
            distance[v]=distance[u] + g[u][v];
            s.insert(make_pair(distance[v],v));
        }
      }
    }
  }
  return distance;
}
