#include <bits/stdc++.h>
using namespace std;
#define mod 1003

int dp[205][205][2];
int parenthesis_count(string s, int i, int j, int isTrue)
{
    // Base Condition
    if (i > j)
        return false;
    if (i == j) {
        if (isTrue == 1)
            return s[i] == 'T';
        else
            return s[i] == 'F';
    }

    if (dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];
    int ans = 0;
    for (int k = i + 1
         ; k <= j - 1; k = k + 2)
    {
        int leftF, leftT, rightT, rightF;
        if (dp[i][k - 1][1] == -1)
        {
            leftT = parenthesis_count(s, i, k - 1, 1);
        } // Count no. of T in left partition
        else {
            leftT = dp[i][k - 1][1];
        }

        if (dp[k + 1][j][1] == -1)
        {
            rightT = parenthesis_count(s, k + 1, j, 1);
        } // Count no. of T in right partition
        else
        {
            rightT = dp[k + 1][j][1];
        }

        if (dp[i][k - 1][0] == -1)
        {
            // Count no. of F in left partition
            leftF = parenthesis_count(s, i, k - 1, 0);
        }
        else
        {
            leftF = dp[i][k - 1][0];
        }

        if (dp[k + 1][j][0] == -1)
        {
            // Count no. of F in right partition
            rightF = parenthesis_count(s, k + 1, j, 0);
        }
        else
        {
            rightF = dp[k + 1][j][0];
        }

        if (s[k] == '&')
        {
            if (isTrue == 1)
                ans =(ans+ (leftT * rightT)%mod)%mod;
            else
                ans =(ans+ (leftF * rightF)%mod + (leftT * rightF)%mod
                       + (leftF * rightT)%mod) %mod;
        }
        else if (s[k] == '|')
        {
            if (isTrue == 1)
                ans = (ans+ (leftT * rightT)%mod + (leftT * rightF)%mod
                       + (leftF * rightT)%mod) %mod;
            else
                ans = (ans + (leftF * rightF)%mod ) %mod;
        }
        else if (s[k] == '^')
        {
            if (isTrue == 1)
                ans = (ans + (leftF * rightT)%mod + (leftT * rightF)%mod) %mod;
            else
                ans = (ans + (leftT * rightT)%mod + (leftF * rightF)%mod) %mod;
        }
      dp[i][j][isTrue] = ans;
    }
    return   ans;
}
int main() {
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        string s;
        cin>>n>>s;
        memset(dp,-1,sizeof(dp));
        cout<<parenthesis_count(s,0,n-1,1)<<endl;

    }
}
