
#include <iostream>
#include <cmath>
using namespace std;

// condition to respect to have convergence
// f(a) and f(b) have to be close and the function f has to satisfy the condition of increasing and then decreasing or contrary !

auto f = [](long double x) { return -x*x+4*x+19; };
float alpha((sqrt(5)-1)/2);

// The minimum version of the optimisation algorithm 
void section_doree_min(long double a, long double b, double epsilon, int Niter){

    float an=a,bn=b,cn=a*alpha+(1-alpha)*b,dn= b*alpha+(1-alpha)*a;
    float Fan=f(an),Fbn=f(bn),Fcn=f(cn),Fdn=f(dn);
    int i=0;
    while(i<Niter){
        if((bn-an)<epsilon){
            cout << "L'alogrithme donne " << (bn+an)/2 <<" et ça donne " << f((bn+an)/2)<<" après "<<i<<" itérations"<<endl;
            break;
        }
        if(Fcn<Fan and Fcn<Fdn){
            bn=dn,cn=alpha*an + (1-alpha)*dn , dn=cn;
            Fbn=Fdn,Fcn=f(cn),Fdn=Fcn;
        }
        else{
            an=cn , cn=dn,dn=(1-alpha)*cn + alpha*bn;
            Fan=Fcn,Fcn=Fdn,Fdn=f(dn);
        }
        i=i+1;
        if(i==Niter){
            cout << "l’algorithme n’a pas convergé après"<< Niter <<"itérations"<<endl;
        }
    }
}

// The maximum version of the optimisation algorithm 
void section_doree_max(long double a, long double b, double epsilon, int Niter){

    float an=a,bn=b,cn=a*alpha+(1-alpha)*b,dn= b*alpha+(1-alpha)*a;
    float Fan=f(an),Fbn=f(bn),Fcn=f(cn),Fdn=f(dn);
    int i=0;
    while(i<Niter){
        if((bn-an)<epsilon){
            cout << "L'alogrithme donne " << (bn+an)/2 <<" et ça donne " << f((bn+an)/2)<<" après "<<i<<" itérations"<<endl;
            break;
        }
        if(Fcn>Fan and Fcn>Fdn){
            bn=dn,cn=alpha*an + (1-alpha)*dn , dn=cn;
            Fbn=Fdn,Fcn=f(cn),Fdn=Fcn;
        }
        else{
            an=cn , cn=dn,dn=(1-alpha)*cn + alpha*bn;
            Fan=Fcn,Fcn=Fdn,Fdn=f(dn);
        }
        i=i+1;
        //cout << " an  =  "<< an <<" cn =  "<<cn<<" dn = "<<dn <<" bn = "<<bn << endl;
        //cout << " f(an)  =  "<< f(an) <<" f(cn) =  "<<f(cn)<<" f(dn) = "<<f(dn) <<" f(bn) = "<<f(bn) << endl;
        if(i==Niter){
            cout << "l’algorithme n’a pas convergé après "<< Niter <<" itérations"<<endl;
        }
    }
}

int main(){

    float temps;
    clock_t t1, t2;
 
    t1 = clock();

    section_doree_max(-5,3,1e-15,1000);
    //section_doree_min(-10,10,1e-8,100);

    t2 = clock();
    temps = (float)(t2-t1)/CLOCKS_PER_SEC;
    printf("temps = %f\n", temps);

    return 0;

}