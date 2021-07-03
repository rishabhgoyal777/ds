vector<int> candyStore(int candies[], int n, int k)
    {
        sort(candies, candies+n, greater<int>());
        int count = n/(k+1);
        if(n % (k+1) !=0 )
            count++;
        int minbuy=0;
        int maxbuy=0;
        
        int i=0,j=n-1;
        // cout<<"count="<<count;
        while(count--){
            minbuy+=candies[j--];
            maxbuy+=candies[i++];
        }
        vector<int> v(2,0);
        v[0]=minbuy;
        v[1]=maxbuy;
        return v;
    }
