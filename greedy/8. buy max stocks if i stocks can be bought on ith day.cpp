int buyMaximumProducts(int n, int k, int price[])
{
    vector<pair<int, int> > v;

    for (int i = 0; i < n; ++i) 
        v.push_back(make_pair(price[i], i + 1));    

    sort(v.begin(), v.end());    

    int ans = 0;
    int temp=0;
    for (int i = 0; i < n; ++i) {
        temp = min(v[i].second, k / v[i].first);
        ans += temp;
        k -= v[i].first * temp;
    }
  
    return ans;
}
