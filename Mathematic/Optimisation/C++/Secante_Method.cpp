#include <iostream>
#include <cmath>

using namespace std;

auto f = [](long double x) { return exp(x)+x*x*x; };
auto g = [](long double x) { return sin(x); };

void Secante_method_f(float x0,float x1,int Niter,float eta){

    int i=0;
    float x=x1-(x1-x0)/(f(x1)-f(x0))*f(x1);
    while(i<Niter){

        if(eta>abs(f(x))){
            cout << " L'algorithme de dichotomie donne "<< x<< " et f(x) vaut "<< f(x) << " après "<< i <<" itérations.\n"<<endl;
            break;
        }
        x=x1-(x1-x0)/(f(x1)-f(x0))*f(x1);
        x0=x1;
        x1=x;
        i++;
    }
    if(i==Niter){
        cout << "L'algorithme n'a pas convergé au bout de " << Niter << "itérations \n"<<endl;
    }
}

void Secante_method_g(float x0,float x1,int Niter,float eta){

    int i=0;
    float x=x1-(x1-x0)/(g(x1)-g(x0))*g(x1);
    while(i<Niter){

        if(eta>abs(g(x))){
            cout << " L'algorithme de dichotomie donne "<< x<< " et g(x) vaut "<< g(x) << " après "<< i <<" itérations.\n"<<endl;
            break;
        }
        x=x1-(x1-x0)/(g(x1)-g(x0))*g(x1);
        x0=x1;
        x1=x;
        i++;
    }
    if(i==Niter){
        cout << "L'algorithme n'a pas convergé au bout de " << Niter << "itérations \n"<<endl;
    }
}

int main(){

    Secante_method_f(-5,4,100,1e-4);
    Secante_method_g(3,4,100,1e-6);

    return 0;
}