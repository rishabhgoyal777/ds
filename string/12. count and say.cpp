Input: n = 4
Output: "1211"
Explanation:
countAndSay(1) = "1"
countAndSay(2) = say "1" = one 1 = "11"
countAndSay(3) = say "11" = two 1's = "21"
countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"

class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        if(n==2) return "11";
        
        string res="11";
        for(int i=3;i<=n;i++){
            string temp="";
            int count=1;
            res=res+'$';    //we add a delimiter at end because. let say when string becomes "11" then at end first if condition will never occur and for loop will end.
            for(int j=1;j<res.length();j++){
                if(res[j]!=res[j-1]){
                    temp=temp+to_string(count);
                    count=1; // resset count
                    temp=temp+res[j-1];
                }
                else{
                    count++;
                }
            }
            res=temp; //for next traversal
        }
        return res;
    }
};
