Given a binary string, that is it contains only 0s and 1s. We need to make this string a sequence of alternate characters by flipping some of the bits,
our goal is to minimize the number of bits to be flipped.
  
int minFlips (string s)
{
    int n=s.length();
    int cnt1=0; //taking sequence as 10101010101010...
    int cnt2=0; //taking sequence as 01010101010101...
    
    for(int i=0;i<n;i++){
      //101010101010101010 => if diff ele at even and odd positions
        if(i%2 ==0 && s[i]=='0') cnt1++;
        if(i%2 !=0 && s[i]=='1') cnt1++;
      //010101010101010101 => if diff ele at even and odd positions
        if(i%2 ==0 && s[i]=='1') cnt2++;
        if(i%2 !=0 && s[i]=='0') cnt2++;
    }
    return min(cnt1,cnt2); //return minimum flips
}
