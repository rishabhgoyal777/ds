lambi list jitni lambi utni traverse krdo phir dono lathe traverse ke jaha pe dono same point kr rahe wo answer

int intersectPoint(Node* head1, Node* head2)
{
    Node* p=head1;
    Node* q=head2;
    int count1=0, count2=0;
    while(p){
        count1++;
        p=p->next;
    }
    while(q){
        count2++;
        q=q->next;
    }
    int diff= abs(count1-count2);

    p=head1;
    q=head2;
    if(count1 > count2){
        while(diff--){
            p=p->next;
        }
    }
    if(count1 < count2){
        while(diff--){
            q=q->next;
        }
    }
    while(p!=q){
        q=q->next;
        p=p->next;
    }
    return p->data;
}
