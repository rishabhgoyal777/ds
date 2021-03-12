#include <bits/stdc++.h>
using namespace std;

bool checkHamiltonian(vector<int> adj[], int n, bool vis[], int &count, int start){
  vis[start]=true;               //vis every node. increase count. .
  count++;
  if(count==n)             //when count reaches total nodes. means its is the path
    return true;
  for(auto x: adj[start]){     // at every node check neighbour
    if(!vis[x]){
      bool flag=checkHamiltonian(adj,n,vis,count,x);  //what neighbour is returning. if returns true, next.  other wise see
      if(flag) return true;        // other neighbours
    }
  }                                //if comes out of loop means no nwiehbour possible from this node. therefore remove previous
  vis[start]= false;               //node and take another node in its place.
  count--;
  return false;
}

bool check(vector<int> adj[], int n){            // we need to check by starting from every node. its possible that graph has
      bool flag=false;                        //hamiltonian path but not from 0th node or the node from w are starting
      for(int i=0;i<n;i++){
        int count=0;
        bool vis[n]={false};
        bool flag=checkHamiltonian(adj,n,vis,count,i);
        if(flag) return true;            // if from any node path is formed just return true. no need for any further.
      }
return false;
	}


int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    vector<int> adj[11];
	    int u,v;
	    for(int i=0;i<m;i++){
	        cin>>u>>v;
	        adj[u-1].push_back(v-1);
	        adj[v-1].push_back(u-1);              // to make it undirected graph
	    }
	  if(check(adj,n)) cout<<1<<endl;
	  else cout<<0<<endl;

	}
	return 0;
}
