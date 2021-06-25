// striver
// what ever number will be left at last in ele will have the possibility of being the ans.
// if any ele is present greater than n/2 times. the minortiy ele will cancel out majority ele counts in some subarray. and left out subarray will give ans in count and ele. but we have to check again for that elemnet.

int majorityElement(int arr[], int n)
{
    int count=0;
    int ele=-1;
    for(int i=0;i<n;i++){
        if(count==0){
            ele=arr[i];
            count++;
        }
        else{
            if(ele==arr[i])
                count++;
            else
                count--;
        }
    }
    int cnt=0;
    
    for(int i=0;i<n;i++){
        if(arr[i]==ele)
            cnt++;
    }
    return cnt>n/2 ? ele:-1;
}
