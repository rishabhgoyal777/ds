Given two strings str1 and str2. The task is to remove or insert the minimum number of characters from/in str1 so as to transform it into str2. It could be possible that the same character needs to be removed/deleted from one point of str1 and inserted to some another point.

convert string1  ->   lcs   ->   string2
            (deletions)  (additions)

            int minOperations(string str1, string str2)
          	{
                int x= str1.length();
                int y= str2.length();
                int t[x+1][y+1];
                for(int i=0;i<x+1;i++){
                    for(int j=0;j<y+1;j++){
                        if(i==0 || j==0)
                            t[i][j]=0;
                    }
                }

                for(int i=1;i<x+1;i++){
                    for(int j=1;j<y+1;j++){
                        if(str1[i-1]==str2[j-1])
                            t[i][j]= 1+t[i-1][j-1];
                        else
                            t[i][j]= max(t[i-1][j],t[i][j-1]);
                    }
                }
                int lcs=t[x][y];

                return (x-lcs) + ( y-lcs) ;          // deletions + additions
          	}
