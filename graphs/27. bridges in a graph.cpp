

#include <bits/stdc++.h>
using namespace std;

void articulation(int u,int dis[],int low[],int &timer,vector<int> adj[],int parent,bool arp[]){
	dis[u]=low[u]=timer++;
	int children=0;
	for(auto v:adj[u]){
    if(v==parent)
    continue;
		children++;
		//tree edge
		if(dis[v]==-1){
			articulation(v,dis,low,timer,adj,u,arp);
			low[u]=min(low[u],low[v]);             //child v jis min disc node pe ja skta parent u bhi uspe ja skta.
			if(low[v]>=dis[u] && parent != -1){// matlab v ya usse niche wala koi bhi node u ke upar wale se connected nhi.so u is articpoint
				arp[u]=true;         // keeping array so no point counted twice
			}
		}
		//back edge
		else{
			low[u]=min(low[u],dis[v]); //update low of parent. as it is a back edge v might have less dis time therefore update low of parent u
		}
	}
	//starting root condition
	if(parent==-1 && children > 1)  //agar root ke 2 children to root bhi articulation point
		arp[u]=true;
}

void bridge(int u,int dis[],int low[],int &timer,vector<int> adj[],vector<pair<int,int>> &bridges, int parent){
	dis[u]=low[u]=timer++;
	for(auto v:adj[u]){
		if(v==parent)
		continue;
		//tree edge
		if(dis[v]==-1){
			bridge(v,dis,low,timer,adj,bridges,u);
			low[u]=min(low[u],low[v]);
			if(low[v]>dis[u]){ //matlb v ya use niche wale u ya usee upar nhi connected. so u-v is a brdige
        	bridges.push_back(make_pair(u,v));
			}
		}
		//back edge
		else{
			low[u]=min(low[u],dis[v]);
		}
	}
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

		for(int i=0;i<n;i++)
      dis[i]=low[i]=-1;
    timer=0;
    vector<pair<int,int>> bridges;

    bridge(0,dis,low,timer,adj,bridges,-1);

		int count=0;
		for(int i=0;i<n;i++){
			if(arp[i]) count++;
		}
		cout<<count<<endl;
		for(int i=0;i<n;i++){
			if(arp[i])
			cout<<i<<" ";
		}cout<<endl;
		cout<<bridges.size()<<endl;
		sort(bridges.begin(),bridges.end());
    for(auto p:bridges){
      cout<<p.first<<" "<<p.second<<endl;
    }
	}
