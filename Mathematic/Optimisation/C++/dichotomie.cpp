
#include <iostream>
#include <cmath>
using namespace std;

auto f = [](long double x) { return exp(x)+x*x*x; };

float absolue(long double x){
    if(x<0){
        return -x;
    }
    return x;
}

void dichotomie(long double a, long double b,long double epsilon, int Niter){
    float m=0;
    m=(a+b)/2;
    int i=0;
        
    while(i<Niter){
        if(epsilon>absolue(f(m))){
            cout << " L'algorithme de dichotomie donne "<< m<< " et i vaut "<< i<<".\n"<<endl;
            break;
        }
        if(f(m)<0){
            a=m;
        }
        else{
            b=m;
        }
        m=(a+b)/2;
        i=i+1;
    }
    if(i==Niter){
        cout << "L'algorithme n'a pas convergé au bout de " << Niter << "itérations \n"<<endl;
    }
}

int main(int argc, char** argv){

    dichotomie(-10,10,1e-5,100);

    return 0;
}

