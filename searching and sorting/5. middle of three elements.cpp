int middle(int a, int b, int c){
        if(a<b)
            return a>c? a: min(b,c);
        return b>c? b : min(a,c);
    }
