Given a sequence of matrices, find the most efficient way to multiply these matrices together. The problem is not actually to perform the multiplications, but merely to decide in which order to perform the multiplications.
We have many options to multiply a chain of matrices because matrix multiplication is associative. In other words, no matter how we parenthesize the product, the result will be the same. For example, if we had four matrices A, B, C, and D, we would have:

(ABC)D = (AB)(CD) = A(BCD) = ....
However, the order in which we parenthesize the product affects the number of simple arithmetic operations needed to compute the product, or the efficiency. For example, suppose A is a 10 × 30 matrix, B is a 30 × 5 matrix, and C is a 5 × 60 matrix. Then,

(AB)C = (10×30×5) + (10×5×60) = 1500 + 3000 = 4500 operations
A(BC) = (30×5×60) + (10×30×60) = 9000 + 18000 = 27000 operations.

int t[1001][1001];

int mcmUtil(int arr[], int i, int j){
  if(i>=j)
    return 0;
  if(t[i][j]!=-1)
    return t[i][j];

  int ans=INT_MAX;

  for(int k=i;k<=j-1;k++){ //k last index se ek piche kyoki k+1 nhi bche ga kuch agar k last index tk jayega to
    int temp = mcm(arr,i,k) + mcm(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
    ans=min(ans,temp);
  }
  return t[i][j]=ans;
}
 int mcm(int arr[]){
   int n= sizeof(arr)/sizeof(arr[0]);
   return mcmUtil(arr,1,n-1);   //starting from 1 as Ai will show matrix having size arr[i-1]×arr[i]
 }
