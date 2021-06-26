Time O(nLogn)
space O(n)
===============================
vector<vector<int>> merge(vector<vector<int>>& v) {
        sort(v.begin(), v.end());

        stack<pair<int, int>> s;
        s.push({v[0][0], v[0][1]});

        for(int i=1;i<v.size();i++){
            pair<int, int> p=s.top();

            if(p.second < v[i][0]){
                s.push({v[i][0], v[i][1]});
            }
            else if(p.second <= v[i][1]){
                s.pop();
                p.second=v[i][1];
                s.push(p);
            }
        }
        vector<vector<int>> res;
        vector<int> temp;
        while(!s.empty()){
            pair<int, int> q=s.top();
            temp.push_back(q.first);
            temp.push_back(q.second);
            res.push_back(temp);
            temp.pop_back();
            temp.pop_back();
            s.pop();
        }
        return res;
    }

  Time O(nLogn)
  space O(1)
  ===============================
  void merge(vector<vector<int>>& v) {
    sort(v.begin(), v.end());

    int index=0;

    for(int i=1;i<v.size();i++){
        if(v[index][1] < v[i][0]){
            index++;
            v[index][0]=v[i][0];
            v[index][1]=v[i][1];
        }
        else if(v[index][1] < v[i][1]){
            v[index][1]=v[i][1];
        }
    }
    //return vector till index
    for(int i=0;i<=index;i++){
        cout<<v[i][0]<<v[i][1]<<" ";
    }
  }



for(int i=1;i<v.size();i++){
        if(v[index].second >= v[i].first ){
	        v[index].second=max(v[index].second, v[i].second);
	}
	else{
        	index++;
		v[index]=v[i];
	}
}
