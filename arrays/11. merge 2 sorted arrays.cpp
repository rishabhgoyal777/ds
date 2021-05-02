time O(m*n)
space O(1)
====================
void merge(int X[], int Y[], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        // compare the current element of `X[]` with the first element of `Y[]`
        if (X[i] > Y[0])
        {
            swap(X[i], Y[0]);

            // move new `Y[0]` to its correct position to maintain the sorted
            // order of `Y[]`. Note: `Y[1…n-1]` is already sorted
            int first = Y[0];
            int k;
            for (k = 1; k < n && Y[k] < first; k++) {
                Y[k - 1] = Y[k];
            }
            Y[k - 1] = first;
        }
    }
}

time O( (n+m)log(m+n) )
space O(1)
=====================
int nextGap(int gap)
{
    if (gap <= 1)
        return 0;
    return (gap / 2) + (gap % 2);   //ceiling value of gap/2
}

void merge(int* arr1, int* arr2, int n, int m)
{
    int i, j, gap = n + m;
    for (gap = nextGap(gap);gap > 0; gap = nextGap(gap))
    {
        // comparing elements in the first array.
        for (i = 0; i + gap < n; i++)
            if (arr1[i] > arr1[i + gap])
                swap(arr1[i], arr1[i + gap]);

        // comparing elements in both arrays.
        for (j = gap > n ? gap - n : 0;
             i < n && j < m;
             i++, j++)
            if (arr1[i] > arr2[j])
                swap(arr1[i], arr2[j]);

        if (j < m) {
            // comparing elements in the second array.
            for (j = 0; j + gap < m; j++)
                if (arr2[j] > arr2[j + gap])
                    swap(arr2[j], arr2[j + gap]);
        }
    }
}
