vector<vector<int>> fourSum(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n= arr.size();
        vector<vector<int>> res;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int target2 = k- arr[j] -arr[i];
                int front = j+1;
                int back= n-1;
                while(front < back){
                    int two_sum = arr[front] + arr[back];
                    
                    if(two_sum < target2)
                        front++;
                    
                    else if(two_sum > target2)
                        back--;
                    
                    else{
                        vector<int> v={arr[i], arr[j], arr[front], arr[back]};
                        res.push_back(v);
                        
                      //to skip duplicates of front
                        while(front < back && arr[front]==v[2])
                            front++;
                            
                      //to skip duplicates of back
                        while(front < back && arr[back]==v[3])
                            back--;
                    }
                }
              //to skip duplicates of j
                while(j+1<n && arr[j+1]==arr[j]) j++; // we check arr[j] with arr[j+1]. when we do j++. it will end on last duplicate character. and for loop will do another j++
            }
          //to skip duplicates of i
            while(i+1<n && arr[i+1]==arr[i]) i++; //simlar as j loop

        }
        return res;
    }
