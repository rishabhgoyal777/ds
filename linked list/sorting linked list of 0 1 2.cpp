Node* segregate(Node *head) {

    Node *zerohead=new Node(0),*onehead=new Node(0),*twohead=new Node(0);
    Node *zp=zerohead, *op=onehead, *tp=twohead;
    Node* p= head;
    while(p){
        if(p->data==0){
            zp->next=p;
            zp=zp->next;
        }
        else if(p->data==1){
            op->next=p;
            op=op->next;
        }
        else{
            tp->next=p;
            tp=tp->next;
        }
        p=p->next;
    }
    tp->next=NULL;

    if(onehead->next){
        zp->next=onehead->next;
        op->next=twohead->next;
    }
    else{
        zp->next=twohead->next;
    }
    return zerohead->next;
}



// 3 LIST BNAI NAYI, EK MEI 0 EK MEI 1 EK MEI 2 BAD MEI TEENO JOIN KRDI
//
// Node* segregate(Node *head) {
//
//     Node * p = head;
//
//     Node * zd = new Node(0);         //PEHLE ELEMENT TEENO MEI 0 RKH DIYA
//     Node * od = new Node(0);         //KUCH BHI RKH SKTE NULL NHI HONA CHAHIYA
//     Node * td = new Node(0);         //ERROR AAA SKTA HAI
//
//     Node * z = zd;
//     Node * o = od;
//     Node * t = td;
//
//     while(p)
//     {
//         if(p->data == 0)
//           {z->next=p;
//            z=z->next;}
//         else if(p->data == 1)
//           {o->next=p;
//            o=o->next; }
//         else if(p->data == 2)
//           {t->next=p;
//            t=t->next; }
//     p=p->next;
//     }
//
//     if(od->next)
//       z->next=od->next;
//     else
//       z->next=td->next;
//
//     o->next=td->next; //--> AGAR ELSE CHLEGA TO YEH CHLE NA CHLE KOI FRAK NHI
//     t->next= NULL;
//
//     head= zd->next; //0 KE AGLE WALA HOGA HEAD(KYONKI 0 TO AISE HI BNAYA THA EK)
//     return head;
//
//
//
// }
