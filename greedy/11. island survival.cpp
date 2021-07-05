int minimumDays(int days, int buy, int required){
        int x=days/7;
        int y=days-x;
        int sm= days * required;
        int a=sm/buy;
        if(sm%buy !=0)
            a++;
        if(a<=y) return a;
        return -1;
    }
