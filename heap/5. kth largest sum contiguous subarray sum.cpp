Time complexity: O(n^2 log (k)) 
Auxiliary Space : O(k) for min-heap and we can store the sum array in the array itself as it is of no use.
	https://www.codingninjas.com/codestudio/problems/k-th-largest-sum-contiguous-subarray_920398?leftPanelTab=1

// int arr= [10, -10, 20, -40]
// =>
// int sum=[0, 10, 0, 20, -20]
// sum of subarray from i to j = sum[j] - sum[i]

int getKthLargest(vector<int> &arr, int k)
{
	priority_queue <int, vector<int>, greater<int> > minhp;
    int n = arr.size();
    
  //array to keep sum of first i elements
    int sum[n+1];
    sum[0]=0;
    sum[1]=arr[0];
    for(int i=2;i<=n;i++){
        sum[i]=sum[i-1] + arr[i-1];
    }
    
//starting index of subarray in sum array
   for(int i=0;i<n;i++){   
     //ending index of subarray in sum array
        for(int j=i+1;j<=n;j++){
            //sum of subarray from i to j
            int x = sum[j]-sum[i];
            
            if(minhp.size()<k){
                minhp.push(x);
            } else{
                if(minhp.top() < x){
             		minhp.pop();
                    minhp.push(x);
                }
            }
               
        }
    }
    return minhp.top();
}
