int minimumNumberOfSwaps(string s){
         int n=s.length();
         int ans=0;
         int open=0;
         int close=0;
         int imbalance=0;
         
         for(int i=0;i<n;i++){
             if(s[i]=='['){
                 open++;
                 if(imbalance > 0){
                     ans+=imbalance;
                     imbalance--;
                 }
             }
             else if(s[i]==']'){
                 close++;
                 imbalance=close-open;
             }
         }
         return ans;
    }
