Given N friends, each one can remain single or can be paired up with some other friend. Each friend can be paired only once. Find out the total number of ways in which friends can remain single or can be paired up.
Note: Since answer can be very large, return your answer mod 10^9+7.
Example 1:

Input:N = 3
Output: 4
Explanation:
{1}, {2}, {3} : All single
{1}, {2,3} : 2 and 3 paired but 1 is single.
{1,2}, {3} : 1 and 2 are paired but 3 is single.
{1,3}, {2} : 1 and 3 are paired but 2 is single.
Note that {1,2} and {2,1} are considered same.

int countFriendsPairings(int n)
{
    long long int t[n+1];
    t[0]=t[1]=1;
    for(int i=2;i<=n;i++){
        t[i]=((t[i-1]%1000000007)+(t[i-2]*(i-1))%1000000007)%1000000007;
    }
    return t[n];
}    
