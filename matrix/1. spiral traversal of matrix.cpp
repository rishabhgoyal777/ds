vector<int> spirallyTraverse(vector<vector<int> > matrix, int n, int m)
    {   int k=0,l=0;
        vector<int> v;

        while(k<n && l<m){

        for(int i=l;i<m;i++){
            v.push_back(matrix[k][i]);
        }
        k++;

        for(int i=k;i<n;i++){
            v.push_back(matrix[i][m-1]);
        }
        m--;

        if(k<n){
            for(int i=m-1;i>=l;i--){
                v.push_back(matrix[n-1][i]);
            }
            n--;
        }
        if(l<m){
            for(int i=n-1;i>=k;i--){
                v.push_back(matrix[i][l]);
            }
            l++;
        }
    }
    return v;
    }
