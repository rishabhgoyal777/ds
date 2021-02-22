The idea is similar to the stack post, here we need to use three extra arrays. In stack post, we needed two extra arrays, one more array is required because in queues, enqueue() and dequeue() operations are done at different ends.

Following are the three extra arrays are used:
1) front[-1,-1,-1,...]: This is of size k and stores indexes of front elements in all queues.
2) rear[]: This is of size k and stores indexes of rear elements in all queues.
2) next[i+1 % n]: This is of size n and stores indexes of next item for all items in array arr[].
int free

isfull()
return free==-1;

isEmpty(qn)
front[qn]==-1


push(ele , qn)
free==-1 full
ELSE
i= free;
free=next[i];
if(qn.empty())             // agar qn khali to front will point to i
  front[qn]=i;
else                      // warna jo abhi rear end pe hai uska next will point to i and front will not change
  next[rear[qn]]=i;

next[i]=-1   ;            // i rear hai ab to i ka next -1
rear[qn]=i;

arr[i]= ele;


pop(sn)
top[qn]==-1  empty
else
i=front[qn];
front[qn]= next[i];
next[i]=free;
free=i;
return arr[i];
