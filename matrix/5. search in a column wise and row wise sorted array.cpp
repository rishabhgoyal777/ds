int matSearch (vector <vector <int>> &mat, int n, int m, int x)
	{
	    int i=0;
	    int j=m-1;
	    
	    while(i<n && j>=0){
	        if(mat[i][j]==x)
	            return true;
	        if(mat[i][j] > x)
	            j--;
	        if(mat[i][j] < x)
	            i++;
	    }
	    return false;
	}
