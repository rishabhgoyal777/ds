bool isvalid(int r, int c, int n){
	    if(r>=0 && r<n && c>=0 && c<n)
	        return true;
        return false;
	}

	vector<int> upwardDigonal(int n, vector<vector<int>> a)
	{
		vector<int> v;
  //1st column elemnts as starting points
		for(int i=0;i<n;i++){
		    v.push_back(a[i][0]);
		    int r=i-1;
		    int c=1;
		    
      //going upright
		    while(isvalid(r,c,n)){
		        v.push_back(a[r][c]);
		        r--;
		        c++;
		    }
		}
		
    //last row elements as stating point
		for(int i=1;i<n;i++){
		    v.push_back(a[n-1][i]);
		    int r=n-2;
		    int c=i+1;
      
		    //going upright
		    while(isvalid(r,c,n)){
		        v.push_back(a[r][c]);
		        r--;
		        c++;
		    }
		}
		return v;
	}

another method - (the sum of i and j index of elemnts of diagonal is same throughout)
===============
void diagonalOrder(int arr[][C],
                   int n, int m)
{
    // we will use a 2D vector to store the diagonals of our array. the 2D vector will have (n+m-1)
    // rows that is equal to the number of diagnols
    vector<vector<int> > ans(n + m - 1);
 
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans[i + j].push_back(arr[j][i]);
        }
    }
 
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
 
        cout << endl;
    }
}


from top to bottom
========================
	vector<int> downwardDigonal(int n, vector<vector<int>> a)
	{

		vector<int> v;
		for(int i=0;i<n;i++){
		    v.push_back(a[0][i]);
		    int r=1;
		    int c=i-1;
		    
		    while(isvalid(r,c,n)){
		        v.push_back(a[r][c]);
		        r++;
		        c--;
		    }
		}
		
		for(int i=1;i<n;i++){
		    v.push_back(a[i][n-1]);
		    int r=i+1;
		    int c=n-2;
		    
		    while(isvalid(r,c,n)){
		        v.push_back(a[r][c]);
		        r++;
		        c--;
		    }
		}
		return v;
		
	}
