A directed graph is strongly connected if there is a path between all pairs of vertices. A strongly connected component (SCC) of a directed graph is a maximal strongly connected subgraph. We have discussed Kosaraju’s algorithm for strongly connected components. The previously discussed algorithm requires two DFS traversals of a Graph. In this post, Tarjan’s algorithm is discussed that requires only one DFS traversal.


#include<bits/stdc++.h>
using namespace std;

void ssc(vector<int> adj[], int V, int discovery[], int low[], stack<int> &s, int instack[], int &time, int start){
  discovery[start]=time;
  low[start]=time++;
  s.push(start);
  instack[start]=1;

  for(auto x: adj[start]){
    if(discovery[x]==-1){
      ssc(adj,V,discovery,low,s,instack,time,x);
      low[start]=min(low[start],low[x]);
    }
    else{
      if(instack[x]!=-1){
        low[start]=min(low[start], discovery[x]);
      }
    }
  }


}


int main(){
	int t;
	cin>>t;
	while(t--){
	    int vertex,edges;
	    cin>>vertex>>edges;
	    int u,v;
	    vector<int> adj[vertex];
	    for(int i=0;i<edges;i++){
        cin>>u>>v;
        adj[u].push_back(v);
      }

      int discovery[vertex];
      int low[vertex];
      int instack[vertex];
      for(int i=0;i<vertex;i++){
        discovery[i]=-1;
        instack[i]=-1;
      }
      stack<int> s;
      int time=0;
      for(int i=0;i<vertex;i++){
        if(discovery[i]==-1)
          ssc(adj,vertex,discovery,low,s,instack,time,0);
      }
      int count=0;
      while(!s.empty()){
        int t=s.top();
        s,pop();
        if(discovery[t]==low[t])
        count++;
      }
      cout<<count<<endl;
  }
}
