void twoStacks :: push1(int x)
{
    if(top2-top1>1)
        arr[++top1]=x;

}

void twoStacks ::push2(int x)
{
    if(top2-top1>1)
        arr[--top2]=x;
}

int twoStacks ::pop1()
{
    if(top1==-1)
        return -1;
    else {int x=arr[top1--]; return x;}
}

int twoStacks :: pop2()
{
if(top2==size)
        return -1;
    else {int x=arr[top2++]; return x;}
}
