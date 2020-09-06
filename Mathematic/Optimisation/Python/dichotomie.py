
from math import exp,cos,sin

f = lambda x: exp(x)+x**3;
g = lambda y: cos(y)+sin(y);

def dichotomie(f, a, b, epsilon, Niter):
    m=(a+b)/2;
    i=0;
        
    while(i<Niter):
        if(epsilon>abs(f(m))):
            print(" L'algorithme de dichotomie donne ", m, "et i vaut", i, ".\n");
            break;
        if(f(m)<0):
            a=m;
        else:
            b=m;
        m=(a+b)/2
        i=i+1;
    if(i==Niter):
        print("L'algorithme n'a pas convergé au bout de ", Niter,"itérations \n");


dichotomie(f, -10,10,1e-15,1000);
dichotomie(g, -10,10,1e-15,1000);

'''
global Compte;
global Non_coverger;
def dicho(f, a, b, epsilon, Niter):
    Compte=0;
    Non_coverger=0;
    m=(a+b)/2;
    i=0;
    while(i<Niter):
        if(epsilon>abs(f(m))):
            Compte=Compte+1;
            dicho(f, m+epsilon, b, epsilon, Niter);
            dicho(f, a, m-epsilon, epsilon, Niter);
        if(f(m)<0):
            a=m;
        else:
            b=m;
        m=(a+b)/2
        i=i+1;
    if(i==Niter):
        Non_coverger=Non_coverger+1;


dicho(f, -1, 1, 1e-15,100);
print(" Compte ", Compte," Non_converger ", Non_coverger);
'''