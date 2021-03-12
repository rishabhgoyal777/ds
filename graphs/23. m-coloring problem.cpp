bool isSafe(int u, int i, bool graph[101][101],int color[], int V, int m){
  for(int v=0;v<V;v++){
    if(graph[u][v] && color[v]==i)
      return false;
  }
  return true;
}

bool gc(bool graph[101][101], int color[], int m, int V, int u){
  if(u==V) return true;    // agar node V pe phunch gyi hai mtlb sbh colour hogye kyoki 0 to V-1 mei V nodes hogye.

//color loop started from 1 cuz 0 taken as no color
  for(int i=1;i<=m;i++){  // check for every color
    if(isSafe(u,i,graph,color,V,m)){ // if it is safe to color
      color[u]=i;     //colored it

      bool flag=gc(graph,color,m,V,u+1);// now recursing and checking if other nodes can be assigned other colors
      if(flag) return true;  // return true if the current allocation was successful

      color[u]=0;  // if not true, backtrack, and remove the colour for that node
    }
  }
  return false;// if all possibilities are false, and no colour can be assigned, return false
}

bool graphColoring(bool graph[101][101], int m, int V) {
      int color[V]={0};
      return gc(graph,color,m,V,0);
}




same solution gfg
===========================

bool isSafe(int v, bool graph[101][101], int color[101], int c, int V) {
    // checking if the connected nodes to v have same colour as c
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i]) return false;
    return true; // return true if no connected node has same colour
}

bool graphColoringUtil(bool graph[101][101], int m, int color[101], int v,
                       int V) {
    // all vertices have been assigned colour
    if (v == V) return true;

    for (int c = 1; c <= m; c++) {
        // check for if this colour can be given to a particular node
        if (isSafe(v, graph, color, c, V)) {
            // assigning colour to the node
            color[v] = c;

            // now recursing and checking if other nodes can be assigned other
            // colours
            if (graphColoringUtil(graph, m, color, v + 1, V) == true)
                return true; // return true if the current allocation was
                             // successful

            // if not true, backtrack, and remove the colour for that node
            color[v] = 0;
        }
    }

    // if all possibilities are false, and no colour can be assigned, return
    // false
    return false;
}

bool graphColoring(bool graph[101][101], int m, int V) {
    int color[v];
    for (int i = 0; i < V; i++) color[i] = 0;

    // check if colours can be assigned
    if (graphColoringUtil(graph, m, color, 0, V) == false) {

        return false;
    }

    return true;
}
