time=> O(n*logn)

// 0 1 2 3 4 5  6  7
// 1 3 4 7 9 9 12 56

  long long findMinDiff(vector<long long> a, long long n, long long m){
        sort(a.begin(),a.end());
        long long diff=INT_MAX;
        for(int i=0;i+m-1<n;i++){
            if(a[i+m-1]-a[i]<diff){
                diff=a[i+m-1]-a[i];
            }
        }
            return diff;
    }   
