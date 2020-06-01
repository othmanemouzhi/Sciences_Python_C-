# LANCER LE PROGRAMME ET CHOISIR ENTRE 1,2,3,4,5,6,7
# L'ECOULEMENT QUE VOUS VOULEZ REGARDER (MODULE + PHASE)
# INTRODUIRE QUELQUE PARAMETRES POUR LE MODÈLE ET ADMIRER LE RÉSULTAT

import math
import matplotlib.pyplot as plt 
import numpy as np 
from pylab import *

from mpl_toolkits.mplot3d import Axes3D

# ECOULEMENT UNIFORME AVEC VITESSE UNIFORME U FAISANT UN ANGLE ALPHA
f1= lambda x,y,U,alpha: U*exp(-1j*alpha)*(x+1j*y)
# PUITS ET SOURCES SITUÉ EN ZO=XO+J*YO 
f2= lambda x,y,Q,x0,y0: Q/(2*math.pi)*log(x+1j*y-(x0+1j*y0))
# TOURBILLON
f3= lambda x,y,Gamma,x0,y0: -1j*Gamma/(2*math.pi)*log(x+1j*y-(x0+1j*y0))
# DIPOLE
f4= lambda x,y,Q,alpha,epsilon: Q/(2*math.pi)*(log(x+1j*y-epsilon*exp(1j*alpha))-log(x+1j*y+epsilon*exp(1j*alpha)))
# ECOULEMENT AUTOUR D'UN DISQUE
f5= lambda x,y,U,mu : U*(x+1j*y)+mu/(x+1j*y)
# TOURBILLON AUTOUR D'UN DISQUE
f6= lambda x,y,Gamma,a: -1j*Gamma/(2*math.pi)*log((x+1j*y)/a)


if __name__ =="__main__":
    X=np.linspace(-10,10,100)
    Y=np.linspace(-10,10,100)
    X,Y=np.meshgrid(X,Y)
    x=int(input("Choose the fluid flow (1,2,3,4,5,6)\n"))
    if(x==1):
        print("Good choice, ECOULEMENT UNIFORME AVEC VITESSE UNIFORME U FAISANT UN ANGLE ALPHA !")
        U=float(input('Velocity in oo\n'))
        alpha=float(input('Alpha rotation parameter\n'))
        Z=f1(X,Y,U,alpha)
    else:
        if(x==2):
            print("Good choice, PUITS ET SOURCES SITUÉ EN ZO=XO+J*YO  ")
            Q=float(input('Outflow of the source or the well\n'))
            x0=float(input('Position in x of the source\n'))
            y0=float(input('Position in y of the source\n'))
            Z=f2(X,Y,Q,x0,y0)
        else:
            if(x==3):
                print("Good choice, TOURBILLON")
                Gamma=float(input('Circulation of the tourbillon \n'))
                x0=float(input('Position in x of the source\n'))
                y0=float(input('Position in y of the source\n'))
                Z=f3(X,Y,Gamma,x0,y0)
            else:
                if(x==4):
                    print("Good choice, DIPOLE")
                    Q=float(input('Outflow of the source or the well\n'))
                    epsilon=float(input('Epsilon parameter\n'))
                    alpha=float(input('Alpha parameter\n'))
                    Z=f4(X,Y,Q,alpha,epsilon)
                else:
                    if(x==5):
                        print("Good choice, ECOULEMENT AUTOUR D'UN DISQUE ")
                        U=float(input('Velocity in oo\n'))
                        mu=float(input('Viscosity\n'))
                        Z=f5(X,Y,U,mu)
                    else:
                        print("Good choice, TOURBILLON AUTOUR D'UN DISQUE ")
                        Gamma=float(input('Circulation of the tourbillon\n'))
                        a=float(input('Diameter of the cylinder\n'))
                        Z=f6(X,Y,Gamma,alpha)

    # definition de l'image ____________PHASE DE L'ÉCOULEMENT______________________
    ax=plt.axes(projection='3d')

    ax.plot_surface(X,Y,np.angle(Z,deg=True),cmap='plasma')
    xlabel('Real')
    ylabel('Imaginaire')
    title('Phase ')
    plt.show()

    # définition de l'image_____________MODULE DE L'ÉCOULEMENT______________

    ax1=plt.axes(projection='3d')
    ax1.plot_surface(X,Y,np.abs(Z),cmap='plasma')
    xlabel('Real')
    ylabel('Imaginaire')
    title('Module')
    plt.show()



