#include <iostream>

class Pendulum{

    public:

    Pendulum(long double theta1,long double theta2,long double dtheta1,long double dtheta2,long double l1,long double l2,long double m1,long double m2,
long double J1, long double J2);
    ~Pendulum();
    void pas_euler(long double h);
    long double get_theta1();
    long double get_theta2();
    long double get_l1();
    long double get_l2();
    long double wrapMax(long double x, long double max);
    long double wrapMinMax(long double x, long double min, long double max);
    
    private:

    long double theta1;
    long double theta2;
    long double dtheta1;
    long double dtheta2;
    long double l1;
    long double l2;
    long double m1;
    long double m2;
    long double J1;
    long double J2;
    double d,u,v,w,a11,a22;

};