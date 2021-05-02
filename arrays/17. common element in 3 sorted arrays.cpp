vector <int> commonElements (int a[], int b[], int c[], int n1, int n2, int n3){
  int i,j,k;
  i=j=k=0;
  vector<int> v;
  while(i<n1 && j<n2 && k<n3){
    if(a[i]==b[j] && b[j]==c[k]){
      if(v.size() && v[v.size()-1]==a[i]){
        i++;j++;
      }
      else{
        v.push_back(a[i]);
        i++;j++;
      }
    }
    else if(a[i] < b[j])   //x<y
      i++;
    else if(b[j] < c[k])   //y<x & y<z
      j++;
    else               // y<x & z<y
      k++;
  }
  return v;
}

vector <int> commonElements (int a[], int b[], int c[], int n1, int n2, int n3)
        {
            vector<int> v;
            vector<int> res;

            int i=0,j=0;

            while(i<n1 && j<n2){
                if(a[i] < b[j])
                    i++;
                else if(a[i] > b[j])
                    j++;
                else{
                    if(v.size() && v[v.size()-1]==a[i]){ // to write duplicates only once
                        i++; j++;
                    }
                    else{
                        v.push_back(a[i]);
                        i++; j++;
                    }
                }
            }

            i=0,j=0;
            int n4=v.size();

            while(i<n3 && j<n4){
                if(c[i] < v[j])
                    i++;
                else if(c[i] > v[j])
                    j++;
                else{
                    res.push_back(c[i]);
                    i++; j++;
                }
            }
            return res;
        }
