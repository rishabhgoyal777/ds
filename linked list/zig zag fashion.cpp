 A<B>C<D>E<F>G ...

Node *zigZag(Node* head)
{ Node *p = head;
 int flag=0;
 while(p->next){
  if(flag==0)              // FLAG=0 INDICATES THERE SHULD BE LESS THAN

   {if(p->data > p->next->data)      // IF GRETAER THAN SWAP CUZ THERE SHLD BE <
    { swap(p->data , p->next->data);
      p=p->next;}
    else   p=p->next;  }            //  ELSE INCREMENT

  else if(flag==1)            //INDICATES THERE SHULD BE GREATER THAN SIGN

   {if(p->data < p->next->data)
      {swap(p->data , p->next->data);
       p=p->next;}
    else   p=p->next;  }

  flag = !flag ; }


    return head;
}
