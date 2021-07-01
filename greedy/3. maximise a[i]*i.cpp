int mod=1e9+7;
    public:
    int Maximize(int a[],int n)
    {
      sort(a,a+n);
      long long int sum=0; int mod=1e9+7;
      for(long long int i=0;i<n;i++)
      {
          sum=(sum+(a[i]*i)%mod)%mod;
      }
      return sum;
    }
