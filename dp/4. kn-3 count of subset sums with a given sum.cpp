pehle or le rhe tha ab sirf plus kr dege jo bhi include kr rahe.

int subsetsum(int arr[], int N, int req){
     int t[N+1][req+1];
     for(int i=0;i<N+1;i++){
         for(int j=0;j<req+1;j++){
             if(i==0)
               t[i][j]=0;
             if(j==0)
               t[i][j]=1;
         }
     }
     for(int i=1;i<N+1;i++){
         for(int j=1;j<req+1;j++){
           if(arr[i-1] <= j)
           t[i][j]= t[i-1][j-arr[i-1]] + t[i-1][j] ;
           else
           t[i][j] = t[i-1][j];
         }
     }
     return t[N][req];
   }
