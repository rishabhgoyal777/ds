You are given a string S of 2N characters consisting of N ‘[‘ brackets and N ‘]’ brackets. A string is considered balanced if 
it can be represented in the for S2[S1] where S1 and S2 are balanced strings. We can make an unbalanced string balanced by swapping adjacent characters. 
Calculate the minimum number of swaps necessary to make a string balanced.
Note - Strings S1 and S2 can be empty.

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
                     imbalance--; //ye open ne ek imbalance thik krdiya swap krke
                 }
             }
             else if(s[i]==']'){
                 close++;
                 imbalance=close-open;
             }
         }
         return ans;
    }
