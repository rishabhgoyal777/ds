long long minCost(long long arr[], long long n) {
        priority_queue<long long, vector<long long>, greater<long long> >minhp;
        for(int i=0;i<n;i++){
            minhp.push(arr[i]);
        }
        long long sum=0;
        while(minhp.size()>1){
            long long first=minhp.top();
            minhp.pop();
            long long second=minhp.top();
            minhp.pop();
            sum+= first + second;
            minhp.push(first + second);
        }
        return sum;
    }
