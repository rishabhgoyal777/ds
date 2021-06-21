typedef pair<int, pair<int,int> > ppi;

vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        priority_queue<ppi, vector<ppi>, greater<ppi> > minhp;
        
        vector<int> res;
        
        for(int i=0;i<k;i++){
            minhp.push({arr[i][0], {i,0}});
        }
        
        while(!minhp.empty()){
            ppi x=minhp.top();
            minhp.pop();
            res.push_back(x.first);
            int arrind=x.second.first;
            int charind=x.second.second;
            if(charind+1 < k){
                minhp.push({arr[arrind][charind+1], {arrind, charind+1}});
            }
        }
        return res;
        
    }
