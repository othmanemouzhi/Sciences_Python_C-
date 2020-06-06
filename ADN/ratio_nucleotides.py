
# CODE IMPLEMENTER EN SUIVANT LE COURS EN BIO-INFORMATIQUE DE L'INRIA PAR François Rechenmann & Thierry Parmentelat SUR FUN-MOOC
# LE COURS EST INTITULÉ « Bioinformatique : algorithmes et génomes » 

# TELECHARGER LE FICHIER ADN DONT VOUS VOULEZ EXTRAIRE DES INFORMATIONS !!!

import matplotlib.pyplot as plt  

def pourcentage(fichier_name):
    f=open(fichier_name,"r")
    f1=f.readlines()
    A=0
    T=0
    C=0
    G=0
    total=0
    k=0
    for x in f1:
        if(x[0]!=';'):
            for k in range(len(x)):
                if(x[k]=='A'):
                    A+=1
                if(x[k]=='T'):
                    T+=1
                if(x[k]=='C'):
                    C+=1
                if(x[k]=='G'):
                    G+=1
                total=total+1
        if(total!=0 and x[0]==';'):
            break

    print("nombre total de nucléotides : {}".format(total))
    print("%A:{}, %T:{}, %C:{} , %G:{}".format(A/total*100,T/total*100,C/total*100,G/total*100))

def draw_ADN(fichier_name):
    # This function draws a promenade of the ADN

    # UP IS THE NUCLEOIDES A
    # DOWN IS THE NUCLEOTIDE T
    # RIGHT IS THE NUCLEOTIDE C
    # LEFT IS THE NUCLEOTIDE G

    position_x=[0]
    position_y=[0]
    f=open(fichier_name,"r")
    f1=f.readlines()
    total=0
    for x in f1:
        if(x[0]!=';'):
            for k in range(len(x)):
                if(x[k]=='A'):
                    position_x.append(position_x[len(position_x)-1]+1)
                    position_y.append(position_y[len(position_y)-1])
                if(x[k]=='T'):
                    position_x.append(position_x[len(position_x)-1]-1)
                    position_y.append(position_y[len(position_y)-1])
                if(x[k]=='C'):
                    position_y.append(position_y[len(position_y)-1]+1)
                    position_x.append(position_x[len(position_x)-1])
                if(x[k]=='G'):
                    position_y.append(position_y[len(position_y)-1]-1)
                    position_x.append(position_x[len(position_x)-1])
                total=total+1
        if(total!=0 and x[0]==';'):
            break
    plt.plot(position_x,position_y, lw=3)
    plt.title("Promenade sur l'ADN de {}".format(fichier_name))
    plt.xlabel("Direction des Adénines-Thymine")
    plt.ylabel("Direction des Cytosine-Guanine")
    plt.savefig("Promenade_sur_l'ADN_de_{}.png".format(fichier_name))
    plt.show()

# T,C,A,G
# List represents proteins depending on the triple sequences of nucleotides

Proteins_table=[[['F','F','L','L'],['S','S','S','S'],['Y','Y','STOP','STOP'],['C','C','STOP','W']]
,[['L','L','L','L'],['P','P','P','P'],['H','H','Q','Q'],['R','R','R','R']],
[['I','I','I','M'],['T','T','T','T'],['N','N','K','K'],['S','S','R','R']],
[['V','V','V','V'],['A','A','A','A'],['D','D','E','E'],['G','G','G','G']]]

def look_for(a):
    x=[0,0,0]
    if(a[0]=='C'):
        x[0]=1
    
    if(a[1]=='C'):
        x[1]=1

    if(a[2]=='C'):
        x[2]=1
    if(a[0]=='A'):
        x[0]=2
    
    if(a[1]=='A'):
        x[1]=2

    if(a[2]=='A'):
        x[2]=2

    if(a[0]=='G'):
        x[0]=3
    
    if(a[1]=='G'):
        x[1]=3
    if(a[2]=='G'):
        x[2]=3
    
    return Proteins_table[x[0]][x[1]][x[2]]

def proteins_list(fichier_name):
    # algorithm that translate the sequences ADN of nucleotides into sequences of proteins
    position_x=[0]
    position_y=[0]
    f=open(fichier_name,"r")
    f1=f.readlines()
    total=0
    proteins=[]

    donnee=''
    for x in f1:
        if(x[0]!=';'):
            x=x.replace('\n','')
            donnee=donnee+x
            total=total+1

        if(total!=0 and x[0]==';'):
            break
    
    for k in range(0,len(donnee),3):
        if(k+2<=len(donnee)-1):
            proteins.append(look_for(donnee[k:k+3]))

    return proteins

def histo(fichier_name):
    plt.hist(proteins_list(fichier_name),bins = 40, color = 'blue',
            edgecolor = 'black')
    plt.title("Proteins letter proportion in {}".format(fichier_name))
    plt.savefig("Proteins_letter_proportion_ADN.png")
    plt.show()


if __name__=="__main__":
    fichier_ADN_name=input("Donner en paramètre un fichier texte d'ADN (Voir BankADN ou autre...) ")
    pourcentage(fichier_ADN_name)
    draw_ADN(fichier_ADN_name)
    histo(fichier_ADN_name)


