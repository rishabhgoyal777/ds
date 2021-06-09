vector<vector<int>> sortedMatrix(int n, vector<vector<int>> arr) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > minhp;
        int count=0;
        vector<vector<int>> res(n);
        for(int i=0;i<n;i++){
            minhp.push({arr[i][0],{i,0}});
        }
        while(!minhp.empty()){
          pair<int, pair<int,int>> p=minhp.top();
          int ele=p.first;
          pair<int, int> q=p.second;
          int i=q.first;
          int j=q.second;
          minhp.pop();
          res[(count/n)].push_back(ele);
          count++;
            if(j+1 < n){
              minhp.push({arr[i][j+1],{i,j+1}});
          }
        }
        return res;
