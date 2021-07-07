long long int maximizeSum(long long int a[], int n, int k)
    {
        long long int sum=0;
        sort(a,a+n);
        
        int i=0;
        
        while(a[i] < 0 && k){
            a[i] = -a[i];
            k--;
            i++;
        }
        
        sort(a,a+n);
        i=0;
        
        while(k--){
            a[i]= -a[i];
        }
        
        for(int i=0;i<n;i++){
            sum+=a[i];
        }
        return sum;
    }
