vector<int> nextPermutation(int n, vector<int> arr){

        int j=n-2;
        for(j;j>=0;j--){
            if(arr[j] < arr[j+1]){
                break;
            }
        }
        
        if(j==-1){
            sort(arr.begin(), arr.end());
            return arr;
        }
        
        int nextgreater = j+1;
        int ele=arr[j];
        
        for(int i=j+1;i<n;i++){
            if(arr[i]>ele && arr[i]<arr[nextgreater]){
                nextgreater=i;
            }    
        }
        
        swap(arr[j],arr[nextgreater]);
        sort(arr.begin()+j+1, arr.end());
        return arr;
    }
