vector<vector<int>> allPaths;

void findPathsUtil(vector<vector<int>> maze, int m, int n, int i, int j, vector<int> path, int indx){

    if (i == m - 1)
    {
        for(int k = j; k < n; k++)
        {
            path[indx + k - j] = maze[i][k];
        }

        allPaths.push_back(path);
        return;
    }

    if (j == n - 1)
    {
        for(int k = i; k < m; k++)
        {
            path[indx + k - i] = maze[k][j];
        }

        allPaths.push_back(path);
        return;
    }

    path[indx] = maze[i][j];

    findPathsUtil(maze, m, n, i + 1,
                  j, path, indx + 1);

    findPathsUtil(maze, m, n, i, j + 1,
                        path, indx + 1);
}

void findPaths(vector<vector<int>> maze, int m, int n){
    vector<int> path(m + n - 1, 0);
    findPathsUtil(maze, m, n, 0, 0, path, 0);
}
