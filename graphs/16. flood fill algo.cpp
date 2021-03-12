In MS-Paint, when we take the brush to a pixel and click, the color of the region of that pixel is replaced with a new selected color. Following is the problem statement to do this task.
Given a 2D screen, location of a pixel in the screen and a color, replace color of the given pixel and all adjacent same colored pixels with the given color.

Example:

Input:
screen[M][N] = {{1, 1, 1, 1, 1, 1, 1, 1},
               {1, 1, 1, 1, 1, 1, 0, 0},
               {1, 0, 0, 1, 1, 0, 1, 1},
               {1, 2, 2, 2, 2, 0, 1, 0},
               {1, 1, 1, 2, 2, 0, 1, 0},
               {1, 1, 1, 2, 2, 2, 2, 0},
               {1, 1, 1, 1, 1, 2, 1, 1},
               {1, 1, 1, 1, 1, 2, 2, 1},
               };
    x = 4, y = 4, newColor = 3
The values in the given 2D screen indicate colors of the pixels.x and y are coordinates of the brush,newColor is the color that should replace the previous color on screen[x][y] and all surrounding pixels with same color.

Output:
Screen should be changed to following.
screen[M][N] = {{1, 1, 1, 1, 1, 1, 1, 1},
               {1, 1, 1, 1, 1, 1, 0, 0},
               {1, 0, 0, 1, 1, 0, 1, 1},
               {1, 3, 3, 3, 3, 0, 1, 0},
               {1, 1, 1, 3, 3, 0, 1, 0},
               {1, 1, 1, 3, 3, 3, 3, 0},
               {1, 1, 1, 1, 1, 3, 1, 1},
               {1, 1, 1, 1, 1, 3, 3, 1},
               };

class Solution {
public:
  void dfs(int oldColor, int newColor, int sr, int sc, vector<vector<int>>& image, int n, int m){
    if(sr<0 || sr>=n || sc<0 || sc>=m)
    return;
    if(image[sr][sc]!=oldColor)
    return;
    if(image[sr][sc]==newColor)
    return;

    image[sr][sc]= newColor;

    dfs(oldColor,newColor,sr-1,sc,image,n,m);
    dfs(oldColor,newColor,sr+1,sc,image,n,m);
    dfs(oldColor,newColor,sr,sc-1,image,n,m);
    dfs(oldColor,newColor,sr,sc+1,image,n,m);
  }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor= image[sr][sc];
        int n=image.size();
        int m=image[0].size();
        dfs(oldColor,newColor,sr,sc,image,n,m);

        return image;
    }
};

//teqip test id-158472294206301
