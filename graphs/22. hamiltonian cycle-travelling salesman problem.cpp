this code has O(n!) time compexity. also see dp solution. this will give tle

#include <bits/stdc++.h>
using namespace std;
int m[12][12];

void tsp(int u, bool vis[], int n, int &min_cost, int curr_cost,int count){
  vis[u]=true;
  count++;

  if(count==n){            // agr last node toh dekho last se 0 pe waps ja rha?
    if(m[u][0] && curr_cost+m[u][0] < min_cost){//agr ja rha aur min hai purane wale se so update min
      min_cost=curr_cost+m[u][0];
    }
    // last npde hi thi to ab dusre paths dekhne ke liye false kiya aur return krdiya
    vis[u]=false;
    return;
  }

  for(int v=0;v<n;v++){
    if(m[u][v] && !vis[v]){ // if neighbour exist and non visited
      tsp(v,vis,n,min_cost,curr_cost+m[u][v],count);
    }
    vis[u]=false;    // node pura visit krliya. uske sare children wgaira dekh liye. Ab false krdiya ki ab kisi dussre paths bhi dekh sakke
  }
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          cin>>m[i][j];
        }
	    }
      int min_cost=INT_MAX;
      bool vis[n]={false};
      tsp(0,vis,n,min_cost,0,0);
      cout<<min_cost<<endl;
	}
	return 0;
}
