class Solution {
public:

  bool wordUtil(int index, int length, int row, int column, int n, int m, vector<vector<char> >& board, string word,vector<bool> vis[]){
    if(index==length)
      return true;
    if(row<0 || row>=n || column<0 || column>=m)
      return false;
    if(vis[row][column] || board[row][column] != word[index])
      return false;

    vis[row][column]=true;

    for(int i=-1;i<2;i++){
      for(int j=-1;j<2;j++){
        if(i==0&&j==0)
          continue;
        if(wordUtil(index+1,length,row+i,column+j,n,m,board,word,vis))
          return true;
      }
    }
    vis[row][column]=false;
    return false;
  }

  bool findword(int n, int m, vector<vector<char> >& board, string word){
    vector<bool> vis[n];

    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++)
        vis[i].push_back(false);
    }

    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        if(word[0]==board[i][j]){
            if(wordUtil(0,word.length(),i,j,n,m,board,word,vis))
              return true;
        }
      }
    }
    return false;
  }

	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
	    int n=board.size();
      int m=board[0].size();
      vector<string> ans;

      for(int i=0;i<dictionary.size();i++){
        if(findword(n,m,board,dictionary[i]))
          ans.push_back(dictionary[i]);
      }
      return ans;
	}
};
