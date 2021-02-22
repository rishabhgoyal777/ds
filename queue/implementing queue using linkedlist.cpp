void MyQueue:: push(int x)
{
        QueueNode* t= new QueueNode(x);
        if(front==NULL){
            front= rear = t;
        }
        else{ rear->next=t; rear=t;}
}

/*The method pop which return the element
  poped out of the queue*/
int MyQueue :: pop()
{
        if(front==NULL)
            return -1;
        else{
            int x= front->data;
            if(front->next)
                front=front->next;
            else front=rear=NULL;
            return x;
        }
}
