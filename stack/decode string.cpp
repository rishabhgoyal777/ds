class Solution {
public:

    bool isalpha(char a){
        if(a>=65 && a<=90)
            return 1;
        else if(a>=97 && a<=122)
            return 1;
        else if(a=='[')
            return 1;
        else return 0;
    }

    string decodeString(string e) {
        stack<int> num;
        stack<char> s;
        num.push(1);
        string r="";
        string t="";
        for(int i=0;i<e.length();i++){
            if(isalpha(e[i])){
                s.push(e[i]);
            }
            else if(e[i]==']'){
                t="";
                int n=num.top(); num.pop();
                t=s.top()+t; s.pop();
                while(s.top()!='['){
                    t=s.top()+t; s.pop();
                } s.pop();
                for(int j=0;j<n;j++){
                    r=r+t;
                }
                for(int k=0;k<r.length();k++){
                    s.push(r[k]);
                }
                r="";
            }
            else{
                int m=0;
                while(e[i]>='0' && e[i] <= '9'){
                    m=m*10 + e[i]-'0' ;
                    i++;
                }
                i--;
                num.push(m);
            }
        }
        while(!s.empty()){
            r=s.top() + r;
            s.pop();
        }
        return r;
    }
};



// while loop
==============
// class Solution {
// public:
//
//     bool isalpha(char a){
//         if(a>=65 && a<=90)
//             return 1;
//         else if(a>=97 && a<=122)
//             return 1;
//         else if(a=='[')
//             return 1;
//         else return 0;
//     }
//
//     string decodeString(string e) {
//         stack<int> num;
//         stack<char> s;
//         num.push(1);
//         string r="";
//         string t="";
//         int i=0;
//         while(e[i]){
//             if(isalpha(e[i])){
//                 s.push(e[i++]);
//             }
//             else if(e[i]==']'){
//                 t="";
//                 int n=num.top(); num.pop();
//                 t=s.top()+t; s.pop();
//                 while(s.top()!='['){
//                     t=s.top()+t; s.pop();
//                 } s.pop();
//                 for(int j=0;j<n;j++){
//                     r=r+t;
//                 }
//                 for(int k=0;k<r.length();k++){
//                     s.push(r[k]);
//                 }
//                 r="";
//                 i++;
//             }
//             else{
//                 int m=0;
//                 while(e[i]>='0' && e[i] <= '9'){
//                     m=m*10 + e[i]-'0' ;
//                     i++;
//                 }
//                 num.push(m);
//             }
//         }
//         while(!s.empty()){
//             r=s.top() + r;
//             s.pop();
//         }
//         return r;
//     }
// };
