class Solution{
public:
  bool isSafe(int n, int row, vector<int> curr){  // curr mei row postions hai jaha pe queens rakhi hui hai

    //checking if any queen already in row
    for(int i=0;i<curr.size();i++){
      if(curr[i]==row)
      return false;
    }

    //checking upper diagonal
    int temp=row-1;
    for(int i=curr.size()-1;i>=0;i--){
      if(temp<0) break;
      if(curr[i]==temp)
        return false;
      temp--;
    }

    // checking lower diagonal
    temp=row+1;
    for(int i=curr.size()-1;i>=0;i--){
      if(temp>n) break;
      if(curr[i]==temp)
        return false;
      temp++;
    }
    return true;
  }

  void sol(int n,vector<vector<int>> &all, vector<int> &curr, int column){
    if(column>n){         // 1 based indexing
      all.push_back(curr);
      return;
    }
    for(int r=1;r<=n;r++){    // row pe iterate kiye jaha pe safe pher next column pe move krgye
      if(isSafe(n,r,curr)){
        curr.push_back(r);
        sol(n,all,curr,column+1);
        curr.pop_back();    // return time pop krdiya
      }
    }
  }

    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> all;
        vector<int> curr;
        sol(n,all,curr,1);
        return all;
    }
};
