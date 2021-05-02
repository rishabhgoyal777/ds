Given an array of integers where each element represents the max number of steps that can be made forward from that element. Find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then you cannot move through that element.
Example 1:
Input:
N=11
arr=1 3 5 8 9 2 6 7 6 8 9
Output: 3

dp
time => O(n^2)
space => O(n)
==================
int minJumps(int arr[], int n){
    if(arr[0]==0 || n==0)
        return -1;

    int t[n];
    t[0]=0;
    for(int i=1;i<n;i++){
        t[i]=INT_MAX;
        for(int j=0;j<i;j++){
            if(i<= j+arr[j] && t[j]!=INT_MAX){
                t[i]=min(t[i],t[j]+1);
                break;
            }
        }
    }
    return t[n-1];
}



optimised
time => O(n)
space => O(1)
=============================
int minJumps(int arr[], int n){
    if(arr[0]==0 || n==0)
        return -1;

    int maxreach=arr[0];
    int steps=arr[0];
    int jump=1;

    for(int i=1;i<n;i++){
        if(i==n-1)
            return jump;

        steps--;
        maxreach=max(maxreach, i+arr[i]);

        if(steps==0){
            jump++;
            if(i >= maxreach){
                return -1;
            }
            steps=maxreach-i;
        }
    }
    return -1;
}
