int MaxSumDifference(int a[], int n)
{
    vector<int> v;
    sort(a, a + n);
    for (int i = 0; i < n / 2; ++i) {
        v.push_back(a[i]);
        v.push_back(a[n - i - 1]);
    }
 
    // If there are odd elements, push the
    // middle element at the end.
    if (n % 2 != 0)
        v.push_back(a[n/2]);
  
    int MaximumSum = 0;
 
    for (int i = 0; i < n - 1; ++i) {
        MaximumSum = MaximumSum + abs(v[i] - v[i + 1]);
    }
 
    // absolute difference of last element
    // and 1st element
    MaximumSum = MaximumSum + abs(v[n - 1] - v[0]);
 
    return MaximumSum;
}
 
