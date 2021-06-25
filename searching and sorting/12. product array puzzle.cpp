Given an array nums[] of size n, construct a Product Array P (of same size n) such that P[i] is equal to the product of all the elements of nums except nums[i].
  without uing division operator

vector<long long int> productExceptSelf(vector<long long int>& arr, int n) {
       
        vector<long long int> res(n);
        vector<long long int> l(n);  //l[i] stores product from 0 to i-1 
        vector<long long int> r(n);  //r[i] stores product from i+1 to n-1
        l[0]=1;
        r[n-1]=1;
        for(int i=1;i<n;i++){
            l[i]=arr[i-1] * l[i-1];
        }
        for(int i=n-2;i>=0;i--){
            r[i]=arr[i+1] * r[i+1];
        }
        for(int i=0;i<n;i++){
            res[i]=l[i]*r[i];  // product[i] = product[0 to i-1] * product[i+1 to n-1] 
        }
        return res;
    }
