// TO CHECK TRAILING ZEROS IN FACTORIAL WE CHECK NO OF 5 IN DIVISORS. BEC NO OF 2's WILL BE HIGHER ONLY
EXAMPLE => 10! = 10*9*8*7*6*5*4*3*2*1 => NO OF 5's = 2 => 10/2 THERFORE N/2
            BUT FOR NUMBERS LIKE 25, 125 THERE ARE EXTRA 5's IN ANSWER
            SO FORMULAE FOR TOTAL 5's IN N = floor(N/5) + floor(N/5^2) + floor(N/5^3) + ... UNTIL TERM BECOMES ZERO

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
                int mid=(l+h)/2; // posible number
                
                if(check(n, mid)){ // if this mid has more than equal to n zeros than check in lower numbers. all higher will also have.
                    ans=mid;
                    h=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            return ans;
        }
