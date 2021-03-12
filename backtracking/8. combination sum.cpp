Given an array of integers and a sum B, find all unique combinations in the array where the sum is equal to B. The same number may be chosen from the array any number of times to make B.

void func(vector<int> &A, int target, vector<vector<int>> &ans, vector<int> &curr,int &sum, int i){
  if(sum==target){
   ans.push_back(curr);
   return;
  }
  if(sum>target || i>=A.size())
   return;

  sum+=A[i];
  curr.push_back(A[i]);
  func(A,target,ans,curr,sum,i);
  sum-=A[i];
  curr.pop_back();

  func(A,target,ans,curr,sum,i+1);
}

vector<vector<int> > combinationSum(vector<int> &A, int target) {
 sort(A.begin(), A.end());
 A.erase( unique(A.begin(), A.end()) , A.end() );//erases duplicate.so ans dont contain duplicate.no need to use set
 vector<vector<int>> ans;
 vector<int> curr;
 int sum=0;
 func(A,target,ans,curr,sum,0);
 return ans;
}
