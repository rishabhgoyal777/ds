  //pepcoding

                      0 0 5 5  0  0
  prefix sum      sum=0 0 5 10 10 10
  start with map with freq of 0 as 1


ll findSubarray(vector<ll> arr, int n ) {
        int count=0;
        unordered_map<int, int> mp;
        int sum=0;
        mp[0]=1;
        
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(mp.find(sum) != mp.end()){ // if present in map
                count+= mp[sum];  // then ans will be the freq of that sum. not including this time one example 0 0 5 .at 0 index count+=1. and map[0]++. therefore at 
                mp[sum]++; //increase freq after calculating count
            }
            else{
                mp[sum]=1;
            }
        }
        
        return count;
    }
