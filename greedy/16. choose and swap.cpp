string chooseandswap(string a){
    set<char> s;
    for(int i=0;i<a.length();i++){
        s.insert(a[i]);
    } //set. so will be in increasing order

    for(int i=0;i<a.length();i++){
        s.erase(a[i]); //now this wont be used afterwards so erase it.
        if(s.empty())
            break;
        char temp=*s.begin();  // smallest from the set
        if(temp < a[i]){ // if smaller than current. swap all their occurences
            char temp2=a[i];
            for(int j=0;j<a.length();j++){
                if(a[j]==temp2) a[j]=temp;
                else if(a[j]==temp) a[j]=temp2;
            }
            break;
        }
    }
    return a;
}
