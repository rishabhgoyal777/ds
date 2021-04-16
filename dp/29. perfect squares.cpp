Given a number N. Find the minimum number of squares of any number that sums to N. For Example: If N = 100 , N can be expressed as (10*10) and also as (5*5 + 5*5 + 5*5 + 5*5) but the output will be 1 as minimum number of square is 1 , i.e (10*10)

class Solution{
	public:
	int MinSquares(int n)
	{
	    int t[n+1];
	    t[0]=0;

	    for(int i=1;i<=n;i++)
	        t[i]=INT_MAX;

	    for(int i=1;i<=n;i++){
	        for(int k=1;k*k<=i;k++){
	                t[i]=min(t[i], t[i-k*k]+1);
	        }
	    }
	    return t[n];
	}
};
