Given a set of integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum.
If there is a set S with n elements, then if we assume Subset1 has m elements, Subset2 must have n-m elements and the value of abs(sum(Subset1) – sum(Subset2)) should be minimum.
=============================================================
arr ka sum nikala, usse humko range milgyi ki kisi bhi subset ki range hogi [0,sum].
ab subsetsum krne se jo matrix bne gi uski last row depict krti hai ki array ke sare elements included mei, kiska subset possible hai with subset sum equal to 0 to sum.
agar subset1 = j then subset2 will be equal to sum - j where subset1 is smaller
therefore we take half of this last row and the greatest index in this half with value true will be j
therefore ans = subset2 - subset1
							= (sum-j) - j = sum=2

class Solution{

	public:
	int minDiffernce(int arr[], int n)
	{   int sum=0;
	    int ans=0;
	    for(int i=0;i<n;i++)
	    sum+=arr[i];
	    bool t[n+1][sum+1];

	    for(int i=0;i<n+1;i++){
	        for(int j=0;j<sum+1;j++){
	         if(i==0)
               t[i][j]=false;
             if(j==0)
               t[i][j]=true;
	        }
	    }

	     for(int i=1;i<n+1;i++){
	        for(int j=1;j<sum+1;j++){
	             if(arr[i-1] <= j)
                    t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j] ;
                 else
                    t[i][j] = t[i-1][j];
            }
        }

	    for(int j=sum/2;j>=0;j--){
	        if(t[n][j] == 1){

	            ans=sum-(2*j);
	            break;

	    }}
	    return ans;
	}
};
