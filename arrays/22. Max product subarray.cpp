int maxSubarrayProduct(int arr[], int n)
{
    // max positive product 
    // ending at the current position
    int max_ending_here = 1;
 
    // min negative product ending 
    // at the current position
    int min_ending_here = 1;
 
    // Initialize overall max product
    int max_so_far = 0;

    int flag = 0;

    /* Traverse through the array. 
    Following values are maintained after the i'th iteration:
    max_ending_here is always 1 or some positive product ending with arr[i]
    min_ending_here is always 1 or some negative product ending with arr[i] */

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0) 
        {
            max_ending_here = max_ending_here * arr[i];
            min_ending_here = min(min_ending_here * arr[i], 1);
            flag = 1;
        }

        else if (arr[i] == 0) { // subarray breaks here. New subarray will start
            max_ending_here = 1;
            min_ending_here = 1;
        }

        else {
            int temp = max_ending_here;
            max_ending_here = max(min_ending_here * arr[i], 1);
            min_ending_here = temp * arr[i];
        }
 
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
    }

    if (flag == 0 && max_so_far == 0) // no positive element in whole array
        return 0;

    return max_so_far;
}
