Given an unsorted array of size n. Array elements are in the range from 1 to n. One number from set {1, 2, …n} is missing and one number occurs twice in the array. Find these two numbers.
  
Traverse the array. While traversing, use the absolute value of every element as an index and make the value at this index as negative to mark it visited. If something is already marked negative then this is the repeating element. To find missing, traverse the array again and look for a positive value.


int *findTwoElement(int *arr, int n) {
        int *ans = new int[2];
        for(int i=0;i<n;i++){
            if(arr[abs(arr[i])-1] > 0)
                arr[abs(arr[i])-1] = -arr[abs(arr[i])-1];
            else
                ans[0]=abs(arr[i]);
        }
        
        for(int i=0;i<n;i++){
            if(arr[i] > 0){
                ans[1]=i+1;
            }
        }
        return ans;
    }
