Given an array of integers, find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers,
The consecutive numbers can be in any order. 
Examples:  
Input: arr[] = {1, 9, 3, 10, 4, 20, 2}
Output: 4
Explanation: 
The subsequence 1, 3, 4, 2 is the longest 
subsequence of consecutive elements

O(nlogn)
O(1)
=================
int findLongestConseqSubseq(int arr[], int n)
{
    int ans = 0, count = 0;
 
    // sort the array
    sort(arr, arr + n);
 
    vector<int> v;
    v.push_back(arr[0]);
 
    //insert repeated elements only once in the vector
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[i - 1])
            v.push_back(arr[i]);
    }
    // find the maximum length
    // by traversing the array
    for (int i = 0; i < v.size(); i++)
    {     
        // Check if the current element is equal
        // to previous element +1
        if (i > 0 && v[i] == v[i - 1] + 1)
            count++;
        // reset the count
        else
            count = 1;
 
        // update the maximum
        ans = max(ans, count);
    }
    return ans;
}

O(n)
O(n)
==================

int findLongestConseqSubseq(int arr[], int n)
{
    int ans = 0, count = 0;
 
    // sort the array
    sort(arr, arr + n);
 
    vector<int> v;
    v.push_back(arr[0]);
 
    //insert repeated elements only once in the vector
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[i - 1])
            v.push_back(arr[i]);
    }
    // find the maximum length
    // by traversing the array
    for (int i = 0; i < v.size(); i++)
    {   
        // Check if the current element is equal
        // to previous element +1
        if (i > 0 && v[i] == v[i - 1] + 1)
            count++;
        // reset the count
        else
            count = 1;
 
        // update the maximum
        ans = max(ans, count);
    }
    return ans;
}
