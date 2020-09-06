#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define max 10
#define pi 3.1415926535897932385E0

int main(int argc, char *argv[])
{
  
  FILE *output;
  output=fopen("fourier.dat", "w");
  if(output==NULL){
    printf("Allocation memory error");
    exit(0);
  }
  double h;
  double x;
  int i,j,k;
  double f[max+1];
  double imag=0;
  double real=0;
  
  h = 1.0/(max-1); /* pas */
    
  // On calcul les valeurs de f(x)=x*(1-x) 
  // avec un pas de h
  for (i = 0; i < max; ++i)
  {
  
  x = h*i;
  f[i] = x;
    
  }
  
  
   for (j=0; j<i; j++)			/* boucle pour l'index de frequence */
   {
      real=0.0;
      imag=0.0;			/* variables a zero */
      for (k=0; k<i; k++)		/* boucle pour la somme */
      {
         real+=f[k]*cos((2*pi*k*j)/i);
         imag+=f[k]*sin((2*pi*k*j)/i);
               
      }
      fprintf(output, "%d %f %f %f\n", j, real, real/i, imag/i );
   }
   printf("donnees sauvegardees dans fourier.dat.\n");
   
   fclose(output);
   
  system("PAUSE");	
  return 0;
}

