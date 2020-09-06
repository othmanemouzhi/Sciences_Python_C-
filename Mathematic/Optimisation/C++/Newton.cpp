 #include <iostream>
#include <cmath>
using namespace std;

auto f = [](long double x) { return exp(x)+x*x*x; };
auto deriv = [](long double x){ return exp(x)+3*x*x;};

void newton(float x0, float epsilon, int Niter, float eta){

    int i=0;
    float x=x0-f(x0)/deriv(x0);
    while(i<Niter){

        if(eta>abs(f(x))){
            cout << " L'algorithme de dichotomie donne "<< x<< "et f(x) vaut "<< f(x) << " après "<< i <<" itérations.\n"<<endl;
            break;
        }
        x=x-f(x)/deriv(x);
        i++;
    }
    if(i==Niter){
        cout << "L'algorithme n'a pas convergé au bout de " << Niter << "itérations \n"<<endl;
    }
}

void newton_appro(float x0, float epsilon, int Niter, float eta){

    int i=0;
    float x=x0-f(x0)/((f(x0+epsilon/2)-f(x0-epsilon/2))/epsilon);
    while(i<Niter){

        if(eta>abs(f(x))){
            cout << " L'algorithme de dichotomie donne "<< x<< " et f(x) vaut "<< f(x) << " après "<< i <<" itérations.\n"<<endl;
            break;
        }
        x=x-f(x)/((f(x+epsilon/2)-f(x-epsilon/2))/epsilon);
        i++;
    }
    if(i==Niter){
        cout << "L'algorithme n'a pas convergé au bout de " << Niter << "itérations \n"<<endl;
    }
}

 int main(){

     newton(-5,1e-3, 100, 1e-5);
     cout << endl;
     newton_appro(-5,1e-5, 100, 1e-5);

     return 0;
 }