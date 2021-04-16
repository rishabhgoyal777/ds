Given a floor of dimensions 2 x W and tiles of dimensions 2 x 1, the task is to find the number of ways the floor can be tiled. A tile can either be placed horizontally i.e as a 1 x 2 tile or vertically i.e as 2 x 1 tile. Print the answer modulo 109+7.


long long numberOfWays(long long N) {
    long long t[N+1];
     t[0]=t[1]=1;

     for(int i=2;i<=N;i++){
         t[i]=(t[i-1]+t[i-2])%1000000007;
     }
     return t[N];
}
