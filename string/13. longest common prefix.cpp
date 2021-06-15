Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".
Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"

class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        if(v.size()==0) return "";
        int minlen=INT_MAX;
        
        string first=v[0]; // taking first string then comparing with other and taking minvalue of prefix with all
        int j,k,count;
        
        for(int i=1;i<v.size();i++){
            j=0,k=0,count=0;
            while( j<first.size() && k<v[i].size() ){
                if(first[j]==v[i][k]){
                    j++;
                    k++;
                    count++;
                }
                else{
                    break;
                }
            }
            minlen=min(minlen,count);
        }
        return first.substr(0,minlen);
    }
};
