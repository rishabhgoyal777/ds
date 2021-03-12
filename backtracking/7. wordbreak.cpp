Given a string A and a dictionary of n words B, find out if A can be segmented into a space-separated sequence of dictionary words.
output 1 if can be else output 0

//start with i and j= 0. i denotes starting index of substr and j denotes ending index of substr
bool func(int i, int j, int n, string &a, vector<string> &b){
  if(j==n){     //agar j str se bahr ja chuka aur i andar hi hai kisi pe matlb ye substr nhi mili to return 0
    if(i==n)
      return true;  // agr i j dono hi str se bahr matlb khmt, string ke sab parts hai dict mei
    return false;
  }

  if(find(b.begin(), b.end(), a.substr(i,j-i+1))==b.end())  // agr substr nhi dict mei to increment j
    return func(i,j+1,n,a,b);
  else{                      // agr hai to
      if(func(j+1,j+1,n,a,b))  // agar yaha pe seperate krne se ans ata to true
        return true;
      else               // wrna yaha pe separate nhi krne se. mtlb j increment krne se ans ata ya nhi
        return func(i,j+1,n,a,b);  // agar aata toh true wrna false. kyoki kisi bhi trah ans nhi aaya
  }
}

int wordBreak(string A, vector<string> &B) {
    return func(0,0,A.length(),A,B);
}
