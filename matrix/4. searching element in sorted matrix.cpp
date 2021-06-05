    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        bool flag=false;
        int p,q,i;
        
        for(i=0;i<n;i++){
            if(matrix[i][0]>target){
                break;    
            }
        }
        if(i>0){
            p=i-1;
            for(int j=0;j<m;j++){
                if(matrix[p][j]==target)
                    flag=true;
            }    
        }   
        return flag;
    }
