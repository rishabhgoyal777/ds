int maximizeTheCuts(int n, int x, int y, int z)
{   int arr[3];
    arr[0]=x;
    arr[1]=y;
    arr[2]=z;

    int t[4][n+1];

    for(int i=0;i<4;i++){
        for(int j=0;j<n+1;j++){
            if(j==0)
            t[i][j]=0;
            if(i==0)
            t[i][j]=0;
        }
    }
    for(int i=1;i<4;i++){
        for(int j=1;j<n+1;j++){
            if(arr[i-1] > j)
                t[i][j]= t[i-1][j];
            else{
                if(t[i][j-arr[i-1]]==0 & j-arr[i-1] != 0)        // agar rod mei se arr[i-1] lenght kaat de aur uske bad jo bche wo na kat
                                                        // pye further(t[i][j-arr[i-1]]=0)  aur bachi rod ki length 0 nhi to dont include this segment kyoki agar bachi lenght na kat pye aur rod length 0 ho jaye tobhi is segment ko kr skte hai include. example let rod length 9 and segments be 2,3,8 agar 9 mei se 8 kat de bchi 1 isko kisi available segment mei nhi kat kste aur bchi rod 0 nhi hai isliye isko nhi gine ge. balki 9 mei se 2 ya 3 kaateinge.
                    t[i][j]= t[i-1][j];
                else
                    t[i][j]= max(1+t[i][j-arr[i-1]], t[i-1][j]);
            }
        }
    }
    return t[3][n];
}
