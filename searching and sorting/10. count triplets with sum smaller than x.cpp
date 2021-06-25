long long countTriplets(long long arr[], int n, long long sum)
	{
	    sort(arr,arr+n);
	    long long count=0;
	    
	    for(int i=0;i<n;i++){
	        int l=i+1;
	        int h=n-1;
	        while(l<h){
	            if(arr[i] + arr[l] +arr[h] < sum){
	                count+= h-l; //kepping l fixed h can be any element between l and h. as sum will be less only.
	                l++; 
	            }
	            else
	                h--;
	        }
	    }
	    return count;
	}
