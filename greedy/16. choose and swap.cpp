string chooseandswap(string a){
    set<char> s;
    for(int i=0;i<a.length();i++){
        s.insert(a[i]);
    }

    for(int i=0;i<a.length();i++){
        s.erase(a[i]);
        if(s.empty())
            break;
        char temp=*s.begin();
        if(temp < a[i]){
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
