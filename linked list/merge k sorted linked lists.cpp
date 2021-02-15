Node* merge(Node* a, Node* b){
    if(!a)
        return b;
    if(!b)
        return a;
    Node* result;
    if(a->data < b->data){
        result=a;
        result->next=merge(a->next,b);
    }
    else{
        result=b;
        result->next=merge(a,b->next);
    }
    return result;
}

Node * mergeKLists(Node *arr[], int N)
{   Node* ans=arr[0];
    for(int i=1;i<N;i++){
        ans=merge(ans,arr[i]);
    }
    return ans;
}
