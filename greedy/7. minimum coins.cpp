 vector<int> findmin(int v){
   vector<int> v;
   int deno[]=  { 1, 2, 5, 10, 20, 50, 100, 500, 1000};
   int d=deno.size();
   for(int i=d-1;i>=0;i++){
     while(v >=deno[i]){
       v.push_back(deno[i]);
       v-=deno[i];
     }
   }
   return v;
 }
