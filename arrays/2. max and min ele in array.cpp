struct elepair{
  int max; int min;
};

struct elepair getMinMax(int arr[], int n){
  struct elepair p;

  if(n==1){
    p.max=arr[0];
    p.min=arr[0];
    return p;
  }

  else{
    p.max=max(arr[0],arr[1]);
    p.min=min(arr[0],arr[1]);

    for(int i=2;i<n;i++){
      p.max=max(p.max,arr[i]);
      p.min=min(p.min,arr[i]);
    }
    return p;
  }

}
