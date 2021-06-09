do transpse and reverese all row or column ele according to que
=============================================================

void reverseColumns(int arr[R][C])
{
    for (int i = 0; i < C; i++)
        for (int j = 0, k = C - 1;
             j < k; j++, k--)
            swap(
                arr[j][i], arr[k][i]);
}
 
// Function for do transpose of matrix
void transpose(int arr[R][C])
{
    for (int i = 0; i < R; i++)
        for (int j = i; j < C; j++)
            swap(arr[i][j], arr[j][i]);
}
