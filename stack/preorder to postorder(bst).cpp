#include<bits/stdc++.h>
using namespace std;
int search(int arr[], int x, int n)
{
for (int i = 0; i < n; i++)
if (arr[i] == x)
return i;
return -1;
}
void printPostOrder(int in[], int pre[], int n)
{

int root = search(in, pre[0], n);
if (root != 0)
printPostOrder(in, pre + 1, root);
if (root != n - 1)
printPostOrder(in + root + 1, pre + root + 1, n - root - 1);
cout << pre[0] << " ";
}

int main()
{
int t;
cin>>t;
while(t--){
int n;
cin>>n;
int pre[n],in[n];
for(int i=0;i<n;i++){ cin>>pre[i];
in[i]=pre[i];
}
sort(in,in+n);
printPostOrder(in, pre, n);
cout<<endl; } return 0; }
