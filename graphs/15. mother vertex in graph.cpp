A mother vertex in a graph G = (V,E) is a vertex v such that all other vertices in G can be reached by a path from v.

class Solution {
public:
  void dfs(int v, bool vis[], int i, vector<int>adj[]){
    vis[i]= true;

    for(auto x: adj[i]){
      if(!vis[x]){
        dfs(v,vis,x,adj);
      }
    }
  };

	int findMotherVertex(int v, vector<int>adj[]){
	    bool vis[v]={false};
      int last;
      for(int i=0;i<v;i++){
        if(!vis[i]){
          dfs(v,vis,i,adj);
          last=i;
        }
      }
      for(int i=0;i<v;i++){
        vis[i]=false;
      }
      dfs(v,vis,last,adj);
      for(int i=0;i<v;i++){
        if(!vis[i])
          return -1;
      }
      return last;
	}
};
