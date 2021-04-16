Given two strings s and t. Find the minimum number of operations that need to be performed on str1 to convert it to str2. The possible operations are:
1. Insert
2. Remove
3. Replace
Example 1:
Input:
s = "geek", t = "gesek"
Output: 1
Explanation: One operation is required
inserting 's' between two 'e's of str1.
Example 2:

Input :
s = "gfg", t = "gfg"
Output:
0
Explanation: Both strings are same.

int editDistance(string s, string r) {
        int n=s.length();
        int m=r.length();

        int t[n+1][m+1];

        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0)
                    t[i][j]=j;
                else if(j==0)
                    t[i][j]=i;
                else{
                    if(s[i-1]==r[j-1])
                        t[i][j]=t[i-1][j-1];
                    else
                    t[i][j]=1+(min(t[i-1][j-1],   //replace- str1 ke char ko replace krke str2 wala char daala, match, so move on next index for both
                                  min(t[i-1][j],  //remove-str1 se remove kiya jo match nhi kr raha, par str2 ka match nhi kiya abhi isliye str1 ka to kam hogya ek par str2 ka wohi index
                                        t[i][j-1])) );   //insert- str2 mei jo char tha similar str1 mei dal diya recur for next char in str2, but str1 mei wohi index rhega 
                }
            }
        }
        return t[n][m];
    }
