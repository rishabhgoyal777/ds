rotate array by one
=======================
void rotate(int arr[], int n)
{   int x=arr[n-1];
    for(int i=n-1;i>0;i--){
        arr[i]=arr[i-1];
    }
    arr[0]=x;
}

rotate right by k
k=3
1234567 => step1 7654321
step2 5674321
step3 5671234
===========================
class Solution {
public:
    void reverse(vector<int>& v, int i, int j){
        while(i<j){
            swap(v[i++], v[j--]);
        }
    }

    void rotate(vector<int>& v, int k) {
        int n=v.size();
        k %= n;
        reverse(v,0,n-1);
        reverse(v,0,k-1);
        reverse(v,k,n-1);
    }
};

rotate left by k
k=3
1234567   => 3214567
            3217654
            4567123

===================
class Solution {
public:
  void reverse(vector<int>& v, int i, int j){
    while(i<j){
      swap(v[i++], v[j--]);
    }
  }

  void rotate(vector<int>& v, int k) {
    int n=v.size();
    k %= n;
    reverse(v,0,k-1);
    reverse(v,k,n-1);
    reverse(v,0,n-1);
  }
};
