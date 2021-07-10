 int arr[m][3] = { 1000, 1030, 1,
                      1010, 1020, 1,
                      1025, 1040, 1,
                      1130, 1145, 2,
                      1130, 1140, 2 }
If we start with a single platform only then we have 1 platform and some trains with their arrival time and departure time and we have to maximize the number of trains on that platform. This task is similar as Activity Selection Problem. So, for n platforms we will simply make n-vectors and put the respective trains in those vectors according to platform number. After that by applying greedy approach we easily solve this problem.



int maxStop(int arr[][3])
{
    vector<pair<int,int> > vect[n+1]; //n platforms. platform no starting from 1 to n. vect[0] will be empty
    
    for(int i=0;i<m;i++){
        vect[arr[i][2]].push_back({arr[i][1], arr[i][0]});
    }
    
    for(int i=0;i<=n;i++){
        sort(vect[i].begin(), vect[i].end());
    }
    
    int count=0;
    
    for(int i=0;i<=n;i++){ //for every platform
        if(vect[i].size()==0) //if no train has to stop at platform i, its size will be zero.
            continue;
        int x=0;
        count++;
        for(int j=1;j<m;j++){
            if(vect[i][j].second > vect[i][x].first){
                count++;
                x=j;
            }
        }
    }
    return count;
}
