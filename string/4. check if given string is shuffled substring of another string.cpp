bool compare(char arr1[], char arr2[])
{
    for (int i=0; i<MAX; i++)
        if (arr1[i] != arr2[i])
            return false;
    return true;
}
 
bool search(char *pat, char *txt)
{
    int M = strlen(pat), N = strlen(txt);

    char countP[MAX] = {0}, countTW[MAX] = {0};
    
    for (int i = 0; i < M; i++)
    {
        (countP[pat[i]])++;
        (countTW[txt[i]])++;
    }
 
    for (int i = M; i < N; i++)
    {
        if (compare(countP, countTW))
           return true;
 
      //window sliding
        countTW[txt[i]]++;
 
        countTW[txt[i-M]]--;
    }
 
    // Check last window
    if (compare(countP, countTW))
        return true;
        return false;
}
