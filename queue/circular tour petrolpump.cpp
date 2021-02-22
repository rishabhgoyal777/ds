int tour(petrolPump p[],int n)
{
   int total=0;
   int curr=0;
   int start=0;

   for(int i=0;i<n;i++){
      total += p[i].petrol -p[i].distance;
      curr += p[i].petrol -p[i].distance;
      if(curr<0){
          curr=0;
          start=i+1;
      }
   }
   return (total>=0)? start : -1;
}



ek total rakhna ek current aha pe current negative hua start se laike waha tak koi bhi startinng ke liye contender nhi ho skta isliye start ko i+1 kr denge
aur jab loop khtm ho jayega jo start hoga wo hoga answer
kyoki us start se end tk to aa hi gye hai.
aur end se start tk bhi chla jayega:

proof

let assume there is point b from end(c) to start in circular fashion such curr becomes negative
a___________b______start__________c
     y         z            x

    and x+y< 0    since at b it become negative
    x + y + z >= 0
    therfore z>=0
    but if it is >=0 start should have been somwehere in z (bw b and start) therefore
    assumption that a point bw a and start exist that curr will become negative is wrong therefore ans would be start only as it would again go from c to start without curr being negative
