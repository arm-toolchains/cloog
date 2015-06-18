#include <stdio.h>
#define floord(n,d) (((n)<0) ? -((-(n)+(d)-1)/(d)) : (n)/(d))
#define ceild(n,d)  (((n)<0) ? -((-(n))/(d)) : ((n)+(d)-1)/(d))
#define max(x,y)    ((x) > (y) ? (x) : (y))
#define min(x,y)    ((x) < (y) ? (x) : (y))

#define S1(t0, t1, t2) printf("%d %d %d\n", t0, t1, t2)
#define N 4

int main() {
int t0, t1, t2;

for (t0=0;t0<=2*N-2;t0++) {
  for (t1=max(0,ceild(t0-N,2));t1<=min(floord(t0,2),floord(N-1,2));t1++) {
    for (t2=max(2*t1,t0-N+1);t2<=min(min(t0,N-1),2*t1+1);t2++) {
    S1(t0, t1, t2);
    //  S1(t0-t2,t2);
    }
  }
}
/*
for (t0=0;t0<=2*N-2;t0++) {
  for (t1=max(0,t0-N+1);t1<=min(t0,N-1);t1++) {
    //S1(t0-t1,t1);
    S1(t0, t1, t2);
  }
}
*/
/*
for (t0=0;t0<=6;t0++) {
  for (t1=max(0,ceild(t0-4,2));t1<=min(1,floord(t0,2));t1++) {
    for (t2=max(0,t0-2*t1-3);t2<=min(1,t0-2*t1);t2++) {
      //S1(t0-2*t1-t2,2*t1+t2);
    S1(t0, t1, t2);
    }
  }
}
*/

}
