int first(int arr[], int n, int x){
    int l=0;
    int h=n-1;
    int res=-1;

    while(l<=h){
        int mid=(l+h)/2;

        if(arr[mid] > x)
            h=mid-1;
        else if(arr[mid] < x)
            l=mid+1;
        else{
           res=mid;
           h=mid-1;
        }
    }
    return res;
}

int last(int arr[], int n, int x){
    int l=0;
    int h=n-1;
    int res=-1;

    while(l<=h){
        int mid=(l+h)/2;

        if(arr[mid] > x)
            h=mid-1;
        else if(arr[mid] < x)
            l=mid+1;
        else{
           res=mid;
           l=mid+1;
        }
    }
    return res;
}

vector<int> find(int arr[], int n , int x )
{
    vector<int> v;
    v.push_back(first(arr,n,x));
    v.push_back(last(arr,n,x));
    return v;
}
