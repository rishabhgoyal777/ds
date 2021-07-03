double fractionalKnapsack(int w, Item arr[], int n)
    {
        sort(arr, arr+n, compare());

        double ans=0.0;
        double wei=0.0;
        
        for(int i=0;i<n;i++){
            if(wei + arr[i].weight <= w){
                ans+=arr[i].value;
                wei+=arr[i].weight;
            } else{
                ans+=((double)arr[i].value/(double)arr[i].weight) * (double)(w - wei);
                break;
            }
        }
        return ans;
    }
