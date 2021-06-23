class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>> > minhp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        
        for(auto it=mp.begin();it!=mp.end();it++){
            minhp.push({it->second,it->first});  //arrow is used with iterators not .
            if(minhp.size() > k){
                minhp.pop();
            }
        }
        
        vector<int> v;
        
        while(!minhp.empty()){
            v.push_back(minhp.top().second);
            minhp.pop();
        }
        return v;
    }
};
