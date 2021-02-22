void push(queue<int> &q,int x)
{
    q.push(x);
}


/*pop out the front element
from the queue q and returns it */
int pop(queue<int> &q)
{
   if(!q.empty()){
      int x=q.front();
      q.pop();
       return x;
   }
   else return -1;
}

/*returns the size of the queue q */
int getSize(queue<int> &q)
{
    int x= q.size();
    return x;
}

/*returns the last element of the queue */
int getBack(queue<int> &q)
{if(!q.empty()){
	int x= q.back();
	return x;}
 else return -1;
}

/*returns the first element of the queue */
int getFront(queue<int> &q)
{   if(!q.empty()){
	int x= q.front();
	return x;}
	else return -1;
}
