

#include <bits/stdc++.h>
using namespace std;

void articulation(int u,int dis[],int low[],int &timer,vector<int> adj[],int parent,bool arp[]){
	dis[u]=low[u]=timer++;
	int children=0;
	for(auto v:adj[u]){
    if(v==parent)
    continue;
		children++;
		if(dis[v]==-1){
			articulation(v,dis,low,timer,adj,u,arp);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dis[u] && parent != -1){
				arp[u]=true;
			}
		}
		else{
			low[u]=min(low[u],dis[v]);
		}
	}
	if(parent==-1 && children > 1)
		arp[u]=true;
}
int main() {
	    int n,m;
	    cin>>n>>m;
	    vector<int> adj[11];
	    int u,v;
	    for(int i=0;i<m;i++){
	        cin>>u>>v;
	        adj[u].push_back(v);
	        adj[v].push_back(u);              // to make it undirected graph
	    }
		int dis[n];
		int low[n];
		for(int i=0;i<n;i++)
			dis[i]=low[i]=-1;
		bool arp[n]={false};
		int timer=0;
		articulation(0,dis,low,timer,adj,-1,arp);
		int count=0;
		for(int i=0;i<n;i++){
			if(arp[i])
			cout<<i<<" ";
		}
	}
