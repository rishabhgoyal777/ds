int rowNum[] = { -1, 0, 0, 1 };
int colNum[] = { 0, -1, 1, 0 };

bool isSafe(int mat[R][C], int visited[R][C], int x, int y){
    if (mat[x][y] == 0 || visited[x][y])
        return false;
    return true;
}

bool isValid(int x, int y){
    if (x < R && y < C && x >= 0 && y >= 0)
        return true;
    return false;
}

void markUnsafeCells(int mat[R][C])
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            // if a landmines is found
            if (mat[i][j] == 0)
            {
              // mark all adjacent cells which are not mines as -1
              for (int k = 0; k < 4; k++)
                if (isValid(i + rowNum[k], j + colNum[k])
                     && mat[i + rowNum[k]][j + colNum[k]]==1)
                    mat[i + rowNum[k]][j + colNum[k]] = -1;
            }
        }
    }
    // mark all found adjacent cells as unsafe
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (mat[i][j] == -1)
                mat[i][j] = 0;
        }
    }
}

void findShortestPathUtil(int mat[R][C], int visited[R][C], i, int j, int &min_dist, int dist){
    if (j == C-1){
        min_dist = min(dist, min_dist);
        return;
    }

    if (dist > min_dist)
        return;

    visited[i][j] = 1;

    for (int k = 0; k < 4; k++)
    {
        if (isValid(i + rowNum[k], j + colNum[k]) &&
            isSafe(mat, visited, i + rowNum[k], j + colNum[k]))
        {
            findShortestPathUtil(mat, visited, i + rowNum[k],
                           j + colNum[k], min_dist, dist + 1);
        }
    }

    visited[i][j] = 0;
}

void findShortestPath(int mat[R][C])
{   int min_dist = INT_MAX;
    int visited[R][C];
    markUnsafeCells(mat);
    // start from first column and take minimum
    for (int i = 0; i < R; i++)
    {   // if path is safe from current cell
        if (mat[i][0] == 1)
        {   // initailize visited to false
            memset(visited, 0, sizeof visited);
            // find shortest route from (i, 0) to any
            // cell of last column (x, C - 1) where
            // 0 <= x < R
            findShortestPathUtil(mat, visited, i, 0,
                                 min_dist, 0);

            // if min distance is already found
            if(min_dist == C - 1) //because cant be less than this
                break;
        }
    }
    cout<<min_dist;
}

===============================
bfs
===============================
struct Key{
    int x,y;
    Key(int i,int j){ x=i;y=j;};
};

int rowNum[] = { -1, 0, 0, 1 };
int colNum[] = { 0, -1, 1, 0 };

bool isValid(int x, int y)
{
    if (x < R && y < C && x >= 0 && y >= 0)
        return true;
    return false;
}

void findShortestPath(int mat[R][C]){
    int i,j;

    for (i = 0; i < R; i++){
        for (j = 0; j < C; j++)
        {
            if (mat[i][j] == 0){
            for (int k = 0; k < 4; k++)
                if (isValid(i + rowNum[k], j + colNum[k]))
                    mat[i + rowNum[k]][j + colNum[k]] = -1;
            }
        }
    }
// mark all found adjacent cells as unsafe
    for (i = 0; i < R; i++){
        for (j = 0; j < C; j++){
            if (mat[i][j] == -1)
                mat[i][j] = 0;
        }
    }

    int dist[R][C];

    for(i=0;i<R;i++){
        for(j=0;j<C;j++)
            dist[i][j] = -1;
    }

    queue<Key> q;

    for(i=0;i<R;i++){
        if(mat[i][0] == 1){
            q.push(Key(i,0));
            dist[i][0] = 0;
        }
    }

    while(!q.empty()){
        Key k = q.front();
        q.pop();

        int d = dist[k.x][k.y];
        int x = k.x;
        int y = k.y;

        for (int k = 0; k < 4; k++) {
            int xp = x + rowNum[k];
            int yp = y + colNum[k];
            if(isValid(xp,yp) && dist[xp][yp] == -1 && mat[xp][yp] == 1){
                dist[xp][yp] = d+1;
                q.push(Key(xp,yp));
            }
        }
    }

    int ans = INT_MAX;
    // start from first column and take minimum
    for(i=0;i<R;i++){
        if(mat[i][C-1] == 1 && dist[i][C-1] != -1){
            ans = min(ans,dist[i][C-1]);
        }
    }
