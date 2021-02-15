void MyStack ::push(int x) {
    StackNode * t = new StackNode(x);
    if(top==NULL){
        top=t;
    }
    else{
        t->next=top;
        top=t;
    }
}

/* The method pop which return the element
  poped out of the stack*/
int MyStack ::pop() {
    int a;
    if(top==NULL)
        return -1;
    else{
        StackNode * p= top;
        a=top->data;
        top=top->next;
        free(p);
        return a;
    }
}
