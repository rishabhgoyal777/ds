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




Time Complexity=>O(logn + logm) => first on rows finding ans possible in which row. then in that row
    ==========================

    bool bsearch(vector<vector<int>> &v, int target, int row, int n, int m){
        int low=0;
        int high=m-1;
        
        while(low<=high){
            int mid= (low+high)/2;
            if(v[row][mid]==target)
                return true;
            if(v[row][mid] > target )
                high= mid-1;
            if(v[row][mid] < target )
                low= mid+1;
        }
        
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int low=0;
        int high=n-1;
        
        while(low<=high){
            int mid=(low+high)/2;
            if(target==matrix[mid][0])
                return true;
            if(target==matrix[mid][m-1])
                return true;
            
            if(target > matrix[mid][0] && target < matrix[mid][m-1]){
               return bsearch(matrix, target,mid,n,m);
            }
            else if(target < matrix[mid][0]){
                high = mid-1;
            }
            else if(target > matrix[mid][0]){
                low = mid+1;
            }
        }
        return false;
    }
