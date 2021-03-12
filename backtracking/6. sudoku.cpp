
bool isvalid(int row, int column, int k, int grid[N][N]){
  for(int i=0;i<9;i++){
    if(grid[row][i]==k)
      return false;
  }
  for(int i=0;i<9;i++){
    if(grid[i][column]==k)
      return false;
  }

  int rs, re, cs,ce;
  for(int i=0;i<9;i+=3){
    if(row>=i && row<i+3){
      rs=i;
      re=i+2;
    }
    if(column>=i && column<i+3){
      cs=i;
      ce=i+2;
    }
  }

  for(int i=rs;i<=re;i++){
    for(int j=cs;j<=ce;j++){
      if(grid[i][j]==k)
        return false;
    }
  }
  return true;
}

bool sudoku(int i, int j, int grid[N][N]){
  if(i==N)
    return true;

  if(grid[i][j]!=0){
    if(j==8)
      return sudoku(i+1,0,grid);
    else
      return sudoku(i,j+1,grid);
  }

  for(int k=1;k<=9;k++){
    if(isvalid(i,j,k,grid)){
      grid[i][j]=k;
      if(j==8){
        if(sudoku(i+1,0,grid))
        return true;
      }
      else{
        if(sudoku(i,j+1,grid))
        return true;
      }
      grid[i][j]=0;
    }
  }
  return false;
}

bool SolveSudoku(int grid[N][N])
{
    return sudoku(0,0,grid);
}

void printGrid (int grid[N][N])
{
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<grid[i][j]<<" ";
        }
    }
}
