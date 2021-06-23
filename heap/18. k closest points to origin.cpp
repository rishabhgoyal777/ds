class Solution {

    public:
    typedef pair<int, pair<int,int> > ppi;   //dist, x coordinate, y coordinate  // dist= sqrt(x^2 + y^2) // but we need to compare distances so sqrt can be avoided
       
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<ppi> maxhp;
        int n=points.size();
        for(int i=0;i<n;i++){
            int dist=points[i][0]*points[i][0] + points[i][1]*points[i][1];
            maxhp.push({dist,{points[i][0],points[i][1]}});
            if(maxhp.size()>k){
                maxhp.pop();
            }
        }
        vector<vector<int>> v;
        
        while(!maxhp.empty()){
            vector<int> a;
            int x=maxhp.top().second.first;
            int y=maxhp.top().second.second;
            maxhp.pop();
            a.push_back(x);
            a.push_back(y);
            v.push_back(a);
        }
        return v;
    }
};
