#include <iostream>

using namespace std;

auto f = [](long double x) { return x*x+4*x-19; };

void decoupage_max(long double a, long double b, long double epsilon, int Niter,int n){

    int i=0,j=0;
    while(i<Niter){

        if(abs(a-b)<epsilon){
            cout << "L'algorithme donne x= " << (a+b)/2 <<" et ça donne f(x)= " << f((a+b)/2)<<" après "<<i<<" itérations"<<endl;
            break;
        }
        for(int j=0;j<n;j++){
            if(f(a+(b-a)/n*j)>f(a+(b-a)/n*(j+1))){
                // cout << f(a+(b-a)/n*j) << ">" <<  f(a+(b-a)/n*(j+1)) <<endl;
                if(j<n-1 && f(a+(b-a)/n*(j+2))>f(a+(b-a)/n*j)){
                        a=a+(b-a)/n*(j+1);
                        b=a+(b-a)/n*(j+2);
                    }
                else{
                    a=a+(b-a)/n*j;
                    b=a+(b-a)/n*(j+1);
                }
                break;
            }
        }
        i++;
        //cout <<" a = " << a << " b = " << b << endl;
        }
    if(i==Niter){
        cout << "l’algorithme n’a pas convergé après "<< Niter <<" itérations"<<endl;
    }
}

void decoupage_min(long double a, long double b, long double epsilon, int Niter,int n){

    int i=0,j=0;
    while(i<Niter){

        if(abs(a-b)<epsilon){
            cout << "L'algorithme donne x= " << (a+b)/2 <<" et ça donne f(x)= " << f((a+b)/2)<<" après "<<i<<" itérations"<<endl;
            break;
        }
        for(int j=0;j<n;j++){
            if(f(a+(b-a)/n*j)<f(a+(b-a)/n*(j+1))){
                cout << f(a+(b-a)/n*j) << ">" <<  f(a+(b-a)/n*(j+1)) <<endl;
                if(j<n-1 && f(a+(b-a)/n*(j+2))<f(a+(b-a)/n*j)){
                        a=a+(b-a)/n*(j+1);
                        b=a+(b-a)/n*(j+2);
                    }
                else{
                    a=a+(b-a)/n*j;
                    b=a+(b-a)/n*(j+1);
                }
                break;
            }
        }
        i++;
        cout <<" a = " << a << " b = " << b << endl;
        }
    if(i==Niter){
        cout << "l’algorithme n’a pas convergé après "<< Niter <<" itérations"<<endl;
    }
}

int main(int argc,char** argv){

    float temps;
    clock_t t1, t2;
 
    t1 = clock();

    decoupage_max(-10,10,1e-8,1000,100);
    //decoupage_min(-10,10,1e-8,1000,100);

    t2 = clock();
    temps = (float)(t2-t1)/CLOCKS_PER_SEC;
    printf("temps = %f\n", temps);
 

    return 0;

}