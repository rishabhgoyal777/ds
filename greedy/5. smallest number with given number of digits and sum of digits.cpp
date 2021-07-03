string smallestNumber(int s, int d){
        if(9*d < s)
            return "-1";
        string res="";
        for(int i=d-1;i>=0;i--){
            if(s>9){
                res = '9' + res;
                s-=9;
            } else{
                if(i==0){
                    res = to_string(s) + res;
                }
                else{
                    res = to_string(s-1) + res;
                    i--;
                    while(i>0){
                        res = '0' + res;
                        i--;
                    }
                    res = '1' + res;
                    break;
                }
            }   
        }
     return res;   
    }
