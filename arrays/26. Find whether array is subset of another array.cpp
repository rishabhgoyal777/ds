O(nlogn+mlogm)
=============
bool isSubset(int arr1[], int arr2[], 
              int m, int n)
{
    int i = 0, j = 0;

    if (m < n)
        return 0;

    sort(arr1, arr1 + m);
    sort(arr2, arr2 + n);

    while (i < n && j < m) 
    {
        if (arr1[j] < arr2[i])
            j++;

        else if (arr1[j] == arr2[i]) 
        {
            j++;
            i++;
        }

        else if (arr1[j] > arr2[i])
            return 0;
    }
    return (i < n) ? false : true;
}

O(m+n)
O(m+n)
Duplicates not handeled
=========
int main()
{
    int arr1[] = { 11, 1, 13, 21, 3, 7 };

    int arr2[] = { 11, 3, 7, 1 };

    int m = sizeof(arr1) / sizeof(arr1[0]);

    int n = sizeof(arr2) / sizeof(arr2[0]);

    unordered_set<int> s;

    for (int i = 0; i < m; i++) {
        s.insert(arr1[i]);
    }

    int p = s.size();

    for (int i = 0; i < n; i++) {
        s.insert(arr2[i]);
    }

    if (s.size() == p) {
       cout << "arr2[] is subset of arr1[] "
             << "\n";
    }
    else {
        cout << "arr2[] is not subset of arr1[] "
             << "\n";
    }
    return 0;
}

O(m+n)
O(m)
==============
bool isSubset(int arr1[], int m, 
              int arr2[], int n)
{
    map<int, int> frequency;

    for (int i = 0; i < m; i++)
    {
        frequency[arr1[i]]++;
    }
    for (int i = 0; i < n; i++) 
    {
        if (frequency[arr2[i]] > 0)
            frequency[arr2[i]]--;

        else
        {
            return false;
        }
    }
    return true;
}
