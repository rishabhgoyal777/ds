Given a value V, if we want to make change for V cents, and we have infinite supply of each of C = { C1, C2, .. , Cm} valued coins, what is the minimum number of coins to make the change?
Examples:
Input: coins[] = {25, 10, 5}, V = 30
Output: Minimum 2 coins required
We can use one coin of 25 cents and one of 5 cents

Input: coins[] = {9, 6, 5, 1}, V = 11
Output: Minimum 2 coins required
We can use one coin of 6 cents and 1 coin of 5 cents



initialize mei
jab coin arr 0 aur sum chahiye let 1 to t[0][1] mien 0 nhi infinity rkhege
aur ismei 2nd row bhi initialize krenge ki 2nd row matlb array ka 1st element aur j from 1 to v+1
agar wo modulus 0 matlb arr[0] wala coin hai sirf to usko bar bar lene se sum ban raha ya nhi agar ban raha to no of coin=sum/coin value
nhi to int_max-1
agr last mei ans int_max -1 ya bada hai mtlb possible nhi hai sum bnana in coins se to return -1

class Solution{

	public:
	int minCoins(int arr[], int m, int v)
	{
	   int t[m+1][v+1];

	   for(int i=0;i<m+1;i++)
	    t[i][0]=0;
	   for(int j=0;j<v+1;j++)
	    t[0][j]=INT_MAX-1;
	   for(int j=1;j<v+1;j++)
	    {if(arr[0]%j==0)
	        t[1][j]=j/arr[0];
	     else
	        t[1][j]=-1;}

	   for(int i=1;i<m+1;i++){
	       for(int j=1;j<v+1;j++){
	           if(arr[i-1] <= j)
	           t[i][j]= min(1+t[i][j-arr[i-1]], t[i-1][j]);
	           else
	           t[i][j]= t[i-1][j];
	       }
	   }
	  if(t[m][v] >= INT_MAX-1)
	    return -1;
	   return t[m][v];}
};
