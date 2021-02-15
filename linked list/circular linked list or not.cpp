bool isCircular(Node *head)
{
   if(!head) return 1;

   Node* p=head;
   Node* q=head->next;
   while(q&&q!=p){
       q=q->next;
   }
   if(p==q) return 1;
   return 0;
}
