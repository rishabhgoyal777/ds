O(n^2) 
O(1) and order preserved
======================
// Utility function to right rotate all elements between
// [outofplace, cur]

void rightrotate(int arr[], int n, int outofplace, int cur)
{
    char tmp = arr[cur];

    for (int i = cur; i > outofplace; i--)
        arr[i] = arr[i - 1];
    arr[outofplace] = tmp;
}
 
void rearrange(int arr[], int n)
{
    int outofplace = -1;

    for (int index = 0; index < n; index++)
    {
        if (outofplace >= 0)
        {
            // find the item which must be moved into the
            // out-of-place entry if out-of-place entry is
            // positive and current entry is negative OR if
            // out-of-place entry is negative and current
            // entry is negative then right rotate

            if (((arr[index] >= 0) && (arr[outofplace] < 0))
                || ((arr[index] < 0 && (arr[outofplace] >= 0)))
            {
                rightrotate(arr, n, outofplace, index);

                // the new out-of-place entry is now 2 steps
                // ahead
                if (index - outofplace >= 2)
                    outofplace = outofplace + 2;

                else
                    outofplace = -1;
            }
        }
 
        // if no entry has been flagged out-of-place
        if (outofplace == -1) {

            // check if current entry is out-of-place
            if (((arr[index] >= 0) && (!(index & 0x01)))
                || ((arr[index] < 0) && (index & 0x01))) {

                outofplace = index;
            }
        }
    }
}


O(n)
O(1) and order not preserved
============================

void rearrange(int arr[], int n)
{
    int i = -1, j = n;

    // shift all negative values to the end
    while (i < j)
    {
        while(i <= n - 1 and arr[i] > 0)
            i += 1;

        while (j >= 0 and arr[j] < 0)
            j -= 1;

        if (i < j)
            swap(arr[i], arr[j]);
    }
 
    // i has index of leftmost 
    // negative element
    if (i == 0 || i == n)
        return;
 

    // start with first positive 
    // element at index 0
    // Rearrange array in alternating 
    // positive &
    // negative items
    int k = 0;

    while (k < n && i < n)
    {
        // swap next positive 
        // element at even position
        // from next negative element.
        swap(arr[k], arr[i]);
        i = i + 1;
        k = k + 2;
    }
}
