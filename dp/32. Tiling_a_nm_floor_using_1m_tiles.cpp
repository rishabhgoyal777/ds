Given a floor of size n x m and tiles of size 1 x m. The problem is to count the number of ways to tile the given floor using 1 x m tiles. A tile can either be placed horizontally or vertically.
Both n and m are positive integers and 2 < = m.

class Solution{
	public:
		int countWays(int n, int m)
	{
	    if(m>n)
	        return 1;
	    int t[n+1];
	    t[0]=1;

	    for(int i=1;i<=n;i++){
	        if(i-m >=0)
	            t[i]=(t[i-1]% 1000000007+t[i-m]% 1000000007)% 1000000007;
	        else
	            t[i]=t[i-1];
	    }
	    return t[n];
	}
};
