O(n^2)
O(1)
=========
bool find3Numbers(int A[], int arr_size, int sum)
{
    int l, r;

    sort(A, A + arr_size);
 
    for (int i = 0; i < arr_size - 2; i++) {
        l = i + 1; // index of the first element in the remaining elements
 
        r = arr_size - 1; // index of the last element

        while (l < r) {
            if (A[i] + A[l] + A[r] == sum) {
                printf("Triplet is %d, %d, %d", A[i],
                       A[l], A[r]);
                return true;
            }
            else if (A[i] + A[l] + A[r] < sum)
                l++;
            else // A[i] + A[l] + A[r] > sum
                r--;
        }
    }
    return false;
}

O(n^2)
O(n)
============
bool find3Numbers(int A[], int arr_size, int sum)
{
    // Fix the first element as A[i]
    for (int i = 0; i < arr_size - 2; i++) 
    {
        // Find pair in subarray A[i+1..n-1]
        // with sum equal to sum - A[i]
        unordered_set<int> s;

        int curr_sum = sum - A[i];

        for (int j = i + 1; j < arr_size; j++) 
        {
            if (s.find(curr_sum - A[j]) != s.end()) 
            {
                printf("Triplet is %d, %d, %d", A[i],
                       A[j], curr_sum - A[j]);
                return true;
            }
            s.insert(A[j]);
        }
    }
    // If we reach here, then no triplet was found
    return false;
}
