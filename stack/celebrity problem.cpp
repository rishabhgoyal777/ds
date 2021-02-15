int getId(int M[MAX][MAX], int n)
{
    stack<int> s;
    for(int i=0;i<n;i++)
        s.push(i);

    int a= s.top(); s.pop();

    int b= s.top(); s.pop();

    if(n==2){
        if(M[a][b]==1 && M[b][a]==0)
            return b;
        else if(M[a][b]==0 && M[b][a]==1)
            return a;
        else return -1;
    }

    while(s.size()>1){
        if(M[a][b]){
            a=s.top(); s.pop();}
        else{
            b=s.top(); s.pop();
        }
    }

    if(s.empty())
        return -1;

    int c= s.top(); s.pop();

    if(M[c][a])
        c=a;
    if(M[c][b])
        c=b;

    for(int i=0;i<n;i++){
        if(i!=c && (M[i][c]==0 || M[c][i]==1))
            return -1;
    }
         return c;

}
