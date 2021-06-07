Time Complexity => O(N*log(M))
==============================

int median(vector<vector<int>> &matrix, int n, int m){
        int minele=INT_MAX;
        int maxele=INT_MIN;
        
        for(int i=0;i<n;i++){
            minele=min(minele,matrix[i][0]); //min element in mtrix
            maxele=max(maxele,matrix[i][m-1]); //max
        }
        int elebeforemedian=(n*m)/2;  //i means, there shud be i-1 elements less than and i-1 elements greater than median in matrix.  
        
        int l=minele; int h=maxele; //this will be space for binary search
  
        while(l<=h){
            int count=0;  // for every mid. keeping no. of elemnets that are <= mid in the matrix
            int mid=(l+h)/2;
            
            for(int i=0;i<n;i++){ //for every row
                count+=upper_bound(matrix[i].begin(), matrix[i].end(),mid)-matrix[i].begin(); 
            }
            if(count <= elebeforemedian)  //agar = ata to bhi low ko mid+1 krna kyoki count is for less than equla to 
                l=mid+1; 
            else
                h=mid-1;
        }
  //when low > high value of low is ans. 
        return l;
    }
