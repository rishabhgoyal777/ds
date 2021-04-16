void util(int arr[], int n, vector<int> &v1, vector<int> &v2, int &mindiff, int i, int sum1, int sum2, vector<int> &r1, vector<int> &r2){
    if(i==n){
      if(abs(sum1-sum2)<mindiff){
        mindiff=abs(sum1-sum2);
        r1=v1;
        r2=v2;
      }
      return;
    }

    if(v1.size() < (n+1)/2){
      v1.push_back(arr[i]);
      util(arr,n,v1,v2,mindiff,i+1,sum1+arr[i],sum2,r1,r2);
      v1.pop_back();
    }
    if(v2.size() < (n+1)/2){
      v2.push_back(arr[i]);
      util(arr,n,v1,v2,mindiff,i+1,sum1,sum2+arr[i],r1,r2);
      v2.pop_back();
    }

}

void tugofwar(int arr[], int n){
    vector<int> v1;
    vector<int> v2;
    vector<int> r1;
    vector<int> r2;
    int sum1=0;
    int sum2=0;
    int mindiff= INT_MAX;
    util(arr,n,v1,v2,mindiff,0,sum1,sum2,r1,r2);
    for(auto x:r1){
        cout<<x<<" ";
    }
    for(auto y:r2){
        cout<<y<<" ";
    }
}
