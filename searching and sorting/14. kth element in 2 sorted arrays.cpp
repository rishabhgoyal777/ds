int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int i=0;
        int j=0;
        int count=1;
        while(i<n && j<m){
            if(count==k){
                return min(arr1[i], arr2[j]);
            }
            if(arr1[i] < arr2[j]){
                i++;
                count++;
            }
            else{
                j++;
                count++;
            }
        }
        
        while(i<n){
            if(count==k)
                return arr1[i];
            i++;
            count++;
        }
        
        while(j<m){
            if(count==k)
                return arr2[j];
            j++;
            count++;
        }
    }
