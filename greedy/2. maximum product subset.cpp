int maxProductSubset(int a[], int n){
  int negcount=0;
  int zerocount=0;
  int product=1;
  int maxneg=INT_MIN;
  
  for(int i=0;i<n;i++){
   if(a[i]==0){
     zerocount++;
     continue;
   }
   if(a[i] < 0({
     negcount++;
     maxneg=max(maxneg, a[i]);
   }   
   product=product* a[i];
  }
 
  if(zerocount==n)
    return 0;
               
  if(negcount%2 !=0 ){
     if (negcount == 1 && zerocount > 0 && zerocount + negcount == n)
            return 0;
  
        product = product / maxneg;
  }
               
  return product;
}
