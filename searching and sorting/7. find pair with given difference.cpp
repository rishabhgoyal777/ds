bool findPair(int arr[], int n, int x){
    sort(arr, arr+n);
    int i=0; int j=1;
    while(i<n && j<n){
        if(i != j && arr[j]-arr[i]==x){
            return true;
        }
        else if(arr[j]-arr[i] < x){
            j++;
        }
        else
            i++;
    }
    return false;
}
