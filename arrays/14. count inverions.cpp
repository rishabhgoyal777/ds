long long mergeutil(long long arr[], long long temp[], long long l, long long mid, long long h){
    long long i=l;
    long long j=mid;
    long long k=l;
    long long count=0;

    while(i<=mid-1 && j<=h){
        if(arr[i] <= arr[j])
            temp[k++]=arr[i++];
        else{
            temp[k++]=arr[j++];
            count+=(mid - i);
        }
    }

    while(i<=mid-1){
        temp[k++] = arr[i++];
    }

    while(j<=h){
        temp[k++] = arr[j++];
    }

    for(int i=l;i<=h;i++)
        arr[i]=temp[i];

    return count;
}

    long long int mergearr(long long arr[], long long temp[], long long l, long long h){
        long long count=0;

        if(l<h){
            long long mid=(l+h)/2;

            count+=mergearr(arr,temp,l,mid);
            count+=mergearr(arr,temp,mid+1,h);

            count+=mergeutil(arr,temp,l,mid+1,h);
        }
        return count;
    }

    long long int inversionCount(long long arr[], long long n)
    {   long long temp[n];
        return mergearr(arr, temp, 0, n-1);
    }
