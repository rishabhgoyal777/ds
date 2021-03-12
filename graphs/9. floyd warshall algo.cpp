The Floyd Warshall Algorithm is for solving the All Pairs Shortest Path problem. The problem is to find shortest distances between every pair of vertices in a given edge weighted directed Graph.
Input:
       graph[][] = { {0,   5,  INF, 10},
                    {INF,  0,  3,  INF},
                    {INF, INF, 0,   1},
                    {INF, INF, INF, 0} }
which represents the following graph
             10
       (0)------->(3)
        |         /|\
      5 |          |
        |          | 1
       \|/         |
       (1)------->(2)
            3
                  0      1      2        3
                ===========================
  ans =        0 |0        5      8      9
               1 |INF      0      3      4
               2 |INF    INF      0      1
               3 |INF    INF    INF      0

#include <iostream>
using namespace std;
const int INF=1e7;
int main() {
	int t;
	cin>>t;
	while(t--){
	    int v;
	    cin>>v;
	    int g[v][v];
	    for(int i=0;i<v;i++){
	        for(int j=0;j<v;j++){
	            cin>>g[i][j];
	        }
	    }

	    for(int k=0;k<v;k++){ // k is intermediatery vertex bw 2 vertex. k starting from 0 to V. when k=0 it is dist bw i and j through 0. when 1 it is dist bw i and j through 1. 0 would automatically be included in this.
	        for(int i=0;i<v;i++){  // iterating weighted matrix
	            for(int j=0;j<v;j++){
	                if(g[i][k]!=INF && g[k][j]!=INF && g[i][k] + g[k][j] < g[i][j])
	                    g[i][j]=g[i][k] + g[k][j];       // updating weights
	            }
	        }
	    }
      //printing final weights
	    for(int i=0;i<v;i++){
	        for(int j=0;j<v;j++){
	            if(g[i][j] == INF)
                    cout<<"INF"<<" ";
                else
                    cout<<g[i][j]<<" ";
	        }cout<<endl;
	    }
	}
}
