class Solution {
public:
    void func(vector<int> &A, int target, set<vector<int>> &ans, vector<int> &curr,int &sum, int i){
      if(sum==target){
        ans.insert(curr);
        return;
      }

      if(sum>target || i>=A.size())
        return;

      sum+=A[i];
      curr.push_back(A[i]);
      func(A,target,ans,curr,sum,i+1);
      sum-=A[i];
      curr.pop_back();

      func(A,target,ans,curr,sum,i+1);
    }

    vector<vector<int>> combinationSum2(vector<int>& A, int target) {
        sort(A.begin(), A.end());
        set<vector<int>> ans;
        vector<vector<int>> res;
        vector<int> curr;
        int sum=0;
        func(A,target,ans,curr,sum,0);
        for(auto x: ans){
            res.push_back(x);
        }
        return res;
    }
};
