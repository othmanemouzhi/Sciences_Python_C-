#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	srand(time(0));
	long double pi=0;
	float x=0;
	float y=0;

	int k=100000000;
	for(int i=0;i<k;i++){
		x=((float)rand())/RAND_MAX;
		y=((float)rand())/RAND_MAX;
		if(x*x+y*y<1){
			pi=pi+1;
		}
	}
	printf("pi=%Lg\n",(long double)4*pi/k);

	return 0;
}