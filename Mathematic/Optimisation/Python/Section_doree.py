from math import sqrt

from math import exp,cos,sin

# condition est la decroissance puis la croissance de la fonction f!
# Trouve la minimum de la fonction f 

f = lambda x: x**2+5*x+2;
g = lambda y: cos(y)+sin(y);

def section_doree(f, a, b, epsilon, Niter):

    alpha=(sqrt(5)-1)/2;
    an,bn,cn,dn=a,b,a*alpha+(1-alpha)*b, b*alpha+(1-alpha)*a;

    Fan,Fbn,Fcn,Fdn=f(an),f(bn),f(cn),f(dn);
    print(Fan,' ', Fbn,' ',Fcn,' ' ,Fdn)
    #assert (Fcn < Fan and Fcn < Fbn)or(Fdn < Fan and Fdn < Fbn)
    L=[];
    i=0;
    while(i<Niter):
        if((bn-an)<epsilon):
            print("L'alogrithme donne ",(bn+an)/2," et ça donne" ,f((bn+an)/2),"\n");
            '''
            for i in range(len(L)):
                print(L[i],' , ');
            '''
            break;
        L.append((an+bn)/2);
        if(Fcn<Fan and Fcn<Fdn):
            an,bn,cn,dn=an, dn, alpha*an + (1-alpha)*dn , cn;
            Fan,Fbn,Fcn,Fdn=Fan,Fdn, f(cn), Fcn;
        
        else:
            an , bn , cn ,dn = cn , bn , dn , (1-alpha)*cn + alpha*bn;
            Fan,Fbn,Fcn,Fdn=Fcn,Fbn,Fdn, f(dn);
        i=i+1;
        if(i==Niter):
            print("l’algorithme n’a pas convergé après", Niter ,"itérations")

section_doree(f,-100,10,1e-9,100)