Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
Note that the same word in the dictionary may be reused multiple times in the segmentation.
Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        bool t[n+1];
        t[0]=1;
        for(int i=1;i<=n;i++)
            t[i]=0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                if(find(wordDict.begin(), wordDict.end(), s.substr(i-j,j)) != wordDict.end() && t[i-j]){
                    t[i]=1;
                    break;
                }
            }
        }
        return t[n];
    }
};
