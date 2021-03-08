#include <iostream>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;

    node(int val){
        data=val;
        left=right=NULL;
    }
};

node* createtree(int a[], int l, int h){
    if(l>h)
    return NULL;

    int mid=(l+h)/2;
    node* root=new node(a[mid]);
    root->left=createtree(a,l,mid-1);
    root->right=createtree(a,mid+1,h);

    return root;
}

void preorder(node* root){
    if(!root)
    return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    }


int main() {
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	int l=0;
	int h=n-1;
	int mid;
	node* root=createtree(a,l,h);
	preorder(root);
	cout<<endl;
	}
}
