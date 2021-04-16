void findMaximumNum(
    string str, int k, string& max)
{
    if (k == 0)
        return;

    int n = str.length();

    for (int i = 0; i < n - 1; i++) {

        for (int j = i + 1; j < n; j++) {

            if (str[i] < str[j]) {

                swap(str[i], str[j]);

                if (str.compare(max) > 0)
                    max = str;

                findMaximumNum(str, k - 1, max);

                swap(str[i], str[j]);
            }
        }
    }
}

string findmax(string str, int k){
  string max=str;
  findMaximumNum(str, k, max);
  return max;
}

============================
optimized
============================

void findMaximumNum(string str, int k, string& max, int ctr)
{
    if (k == 0)
        return;

    int n = str.length();

    char maxm = str[ctr];

    for (int j = ctr + 1; j < n; j++) {
        // Find maximum digit greater
        // than at ctr among rest
        if (maxm < str[j])
            maxm = str[j];
    }

    // If maxm is possible
    if (maxm != str[ctr])
        --k;

    // search this maximum among the rest
    for (int j = ctr; j < n; j++) {

        if (str[j] == maxm) {

            swap(str[ctr], str[j]);

            if (str.compare(max) > 0)
                max = str;

            findMaximumNum(str, k, max, ctr + 1);
             // Backtrack
            swap(str[ctr], str[j]);
        }
    }
}

string findmax(string str, int k){
  string max=str;
  findMaximumNum(str, k, max, 0);
  return max;
}
