class Solution {
public:
    
    struct compare{
        bool operator()(vector<int> a, vector<int> b){
            return a[1] < b[1];
        }
    };
       
    int jobScheduling(vector<int>& st, vector<int>& et, vector<int>& p) {
        int n=st.size();
        vector<vector<int>> v;
        for(int i=0;i<n;i++){
            vector<int> t{st[i], et[i], p[i]}; //starttime, endtime, profit
            v.push_back(t);
        }
      //sorting according to end time
        sort(v.begin(), v.end(), compare());
        
      //dp[i] stores max profit till ith index
        int dp[n];
        dp[0]=v[0][2];
        
        for(int i=1;i<n;i++){
          //include i and check in 0 to i-1, the highest dp[i] using binary search with which it can be paired. store it in last 
          int include=v[i][2]; //profit of i
            int last=-1;
            int l=0;
            int h=i-1;
            
            while(l<=h){
                int mid=(l+h)/2;
                
                if(v[mid][1] <= v[i][0]){ // if posible with mid store in last and check if greater posible. so move to rigth subarray.
                    last=mid;
                    l=mid+1;
                }
                else{
                    h=mid-1;
                }
            }
             //if it can be paired add profit
            if(last != -1) include+=dp[last];
            
          //if not including i profit will be same as last one
            int exclude = dp[i-1];
            
          //assign max value with including or excluding
            dp[i]= max(include, exclude);
        }
        return dp[n-1];
    }
};
