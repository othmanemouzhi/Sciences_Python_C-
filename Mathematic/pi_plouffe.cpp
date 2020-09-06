#include <iostream>
#include <cmath>

// pi avec la forume BBP (Baley-Borwein-Plouffe)

long double  piSeri(int n,int k,int cst);
long double  constante_depart(int n);


int main(int ar,char **argv)
{
  long double sum=0;
  int i=0;
  int n[4]= {4,2,1,1};
  int cst[4]= {1,4,5,6};
  int maxK=10;

  for (i=0; i<maxK; i++)
  {
    sum= sum+ (constante_depart(i)*\
               ((piSeri(n[0],i,cst[0])- piSeri(n[1],i,cst[1])-\
                 piSeri(n[2],i,cst[2])-piSeri(n[3],i,cst[3]))));
  }
  printf("pi vaut %1.18Lg  après %d itérations \n",sum,i);
}

long double  constante_depart(int  n)
{
  return( 1/ (pow(16,n)) );
}

long double  piSeri(int n,int k,int cst)
{
  return (long double ) n/double ((8*k)+(double )cst);
}
