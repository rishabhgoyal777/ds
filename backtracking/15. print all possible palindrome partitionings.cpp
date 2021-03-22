class Solution {
public:
    bool isPalindrome(string s, int i, int j){
        while(i<j){
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    void Util(vector<vector<string>> &ans, vector<string> &curr, int index, int n, string s){
        if(index >= n){
            ans.push_back(curr);
            return;
        }

        for(int i=index;i<n;i++){
            if(isPalindrome(s,index,i)){
                curr.push_back(s.substr(index,i-index+1));

                Util(ans, curr, i+1, n, s);

                curr.pop_back();
            }
        }
    }



    vector<vector<string>> partition(string s) {
        int n = s.length();

        vector<vector<string>> ans;
        vector<string> curr;

        Util(ans, curr, 0, n, s);

        return ans;
    }
};
