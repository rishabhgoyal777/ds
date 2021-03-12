void subsets(int i, vector<int> A, int n, set<vector<int>> &ans, vector<int> &curr){
    if(i==n){
        ans.insert(curr);
        return;
    }
      // donot include this index element in curr vector
    subsets(i+1,A,n,ans,curr);
    // include
    curr.push_back(A[i]);
    subsets(i+1,A,n,ans,curr);
    //delete element while returning so can check another ans
    curr.pop_back();
}

vector<vector<int> > AllSubsets(vector<int> A, int n)
{
    set<vector<int>> ans;   // using set so sets dont repeat
    vector<int> curr;
    sort(A.begin(),A.end());
    subsets(0,A,n,ans,curr);
    vector<vector<int>> res;
    for(auto z:ans){
        res.push_back(z);
    }
    return res;
}
