Given a fence with n posts and k colors, find out the number of ways of painting the fence such that at most 2 adjacent posts have the same color. Since answer can be large return it modulo 10^9 + 7.

//diff = the one being added diff than prev
//same = the one being added same as prev

long long countWays(int n, int k){

    if(n==1) return k;
    long long diff=k;
    long long same=0;
    long long temp;
    for(int i=2;i<=n;i++){
        temp=diff;
        diff=((same + diff)*(k-1))%1000000007;    //total diff now = same(previously)*k-1 + diff(prev)*k-1
        same=temp%1000000007;                     // same= diff(prev)*1(since here it would be same as previous color)
    }
    return (same+diff)%1000000007;
}
