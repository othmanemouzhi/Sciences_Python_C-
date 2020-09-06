#include <iostream>

using namespace std;

// METHODE DU GRAIDENT POUR UN MAXIMUM

auto f = [](long double x) { return -x*x+4*x-19; };

long double deriv(float x, float epsilon){

    return (f(x+epsilon)-f(x))/epsilon;

}

void gradient(float x0, float epsilon, int Niter,float alpha){

    int i=0;
    float x=x0+alpha*deriv(x0,epsilon);
    //cout << deriv(x0,epsilon) << endl;
    while(i<Niter){

        if(abs(x-x0)<epsilon){
            cout << "L'alogrithme donne x= " << x <<" et ça donne f(x)= " << f(x)<<" après "<<i<<" itérations"<<endl;
            break;
        }
        x0=x;
        x=x+alpha*deriv(x,epsilon);
        i++;
    }
    if(i==Niter){
        cout << "l’algorithme n’a pas convergé après"<< Niter <<"itérations"<<endl;
    }
}

int main(int argc, char** argv){
    /*
    cout << "\t What is the function that you want to study ? " << endl;
    cout << "\t Write it using the unknow x and operators such +,*,/,- " << endl;
    char function[];
    cin >> function; 
    */

    gradient(-5, 1e-5, 10000, 1e-3);

    return 0;
}