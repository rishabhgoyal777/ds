bool isShuffle(string A, string B, string C) 
    {
        int n1= A.length();
        int n2= B.length();
        int n3= C.length();
        
        int i=0,j=0,k=0;
        while(k<n3){
            if(i<n1 && A[i]==C[k])
                i++;
            else if(j<n2 && B[j]==C[k])
                j++;
            else{
                return false;
            }
                k++;
        }
        if(i < n1 || j < n2)
            return false;
        return true;
    }
