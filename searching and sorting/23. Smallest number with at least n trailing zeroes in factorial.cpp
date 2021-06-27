bool check(int n, int mid){
            int d=5;
            int ans=0;
            while(mid/d){
                ans+=mid/d;
                d=d*5;
            }
            if(ans < n) return false;
            return true;
        }
    
        int findNum(int n){
            if(n==1) return 5;
            
            int l=0;
            int h=1e7;
            int ans=0;
            
            while(l<=h){
                int mid=(l+h)/2;
                
                if(check(n, mid)){
                    ans=mid;
                    h=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            return ans;
        }
