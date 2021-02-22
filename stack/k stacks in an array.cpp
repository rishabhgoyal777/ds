https://www.geeksforgeeks.org/efficiently-implement-k-stacks-single-array/

arr[n] for elements of all stacks
top[k]={-1,-1,-1,...} for top index of k stacks
next[n]={i+1 % n } && next[n-1]= -1 for next index in stack of every element in arr
int free=0  pointing free index for insertion in arr

push(ele , sn)
free==-1 full
ELSE
i= free;
free=next[i];
next[i]=top[sn];
top[sn]=i
arr[i]=ele;


pop(sn)
top[sn]==-1  empty
else
i=top[sn];
top[sn]=next[i];
next[i]=free ;
free=i ;
