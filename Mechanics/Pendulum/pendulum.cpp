#include "pendulum.hpp"
#include <cmath>
#define PI 3.14159265

using namespace std;

Pendulum::Pendulum(long double theta1,long double theta2,long double dtheta1,long double dtheta2,long double l1,long double l2,long double m1,long double m2,
long double J1, long double J2):theta1(theta1),theta2(theta2),dtheta1(dtheta1),dtheta2(dtheta2),l1(l1),l2(l2),m1(m1),m2(m2),J1(J1),J2(J2)
{
    a11=m1*l1*l1/4+m2*l1*l1+J1;
    a22=m1*l1*l1/4+J2;
    d=a11*a22;
    u=0.5*m2*l1*l2;
    v=m1*l1*0.5+m2*l1;
    w=m2*l2*0.5;
}

Pendulum::~Pendulum(){

}

void Pendulum::pas_euler(long double h){

    theta1+=dtheta1*h;
    theta2+=dtheta2*h;
    long double sin1(sin(theta1*PI/180));
    long double cos1(cos(theta1*PI/180));
    long double sin2(sin(theta2*PI/180));
    long double cos2(cos(theta2*PI/180));
    long double a12(u*(sin1*sin2+cos1*cos2));
    long double det(d-a12*a12);
    long double b1(u*(cos1*sin2-sin1*cos2)*dtheta2*dtheta2-v*sin1);
    long double b2(u*(sin1*cos2-cos1*sin2)*dtheta1*dtheta1-w*sin2);
    if(det==0){
        cout << "det=0" <<endl;
    }
    else{
        dtheta1+=(a22*b1-a12*b2)/det*h;
        dtheta2+=(a11*b2-a12*b1)/det*h;
    }
    theta1=wrapMinMax(theta1,-180,180);
    theta2=wrapMinMax(theta2,-180,180);
    dtheta1=wrapMinMax(dtheta1,-180,180);
    dtheta2=wrapMinMax(dtheta2,-180,180);
}

long double Pendulum::get_theta1(){
    return theta1;
}
long double Pendulum::get_theta2(){
    return theta2;
}
long double Pendulum::get_l1(){
    return l1;
}
long double Pendulum::get_l2(){
    return l2;
}

/* wrap x -> [0,max) */
long double Pendulum::wrapMax(long double x, long double max)
{
    /* integer math: `(max + x % max) % max` */
    return fmod(max + fmod(x, max), max);
}
/* wrap x -> [min,max) */
long double Pendulum::wrapMinMax(long double x, long double min, long double max)
{
    return min + wrapMax(x - min, max - min);
}