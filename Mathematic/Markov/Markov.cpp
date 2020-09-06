#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <random>

using namespace std;


struct enfant_with_occ{

    string name;
    int occurence;

};

struct parents{

    string name;
    vector <enfant_with_occ> enfants;

};

// declaration de la chaîne de Markov

vector <parents> markov;
enfant_with_occ enfant;
parents parent;

// Learning list

int learn(string &name_file);
void add_item(string name_parent, string name_enfant);
string pick_one(string parent);
int find_parent(string name);
void reset();
void affiche();

// Writer 
void write(int lenght, string name_result);

// function writing the text
void write(int lenght,string name_result){
    string text="";
    string prv="";
    for(int i=0;i<lenght;i++){
        string word=pick_one(prv);
        text += word + " ";
        prv=word;


    }

    ofstream Result(name_result);
    if(Result){
        Result << text;
    }
    else{
        cout << "ERROR:COULDN'T OPEN THE FILE" << endl;
    }
}

void reset(){
    markov.clear();
}

// function returning a string choose randomly 
string pick_one(string parent){

    int k=find_parent(parent);

    if( k!=-1){

        int compteur=0;
        for(int i=0;i<markov[k].enfants.size();i++){
            compteur = compteur + markov[k].enfants[i].occurence;
        }
        int number= rand()%compteur+1;
        int toNumber=0;

        for(int i=0;i<markov[k].enfants.size();i++){
            toNumber = toNumber + markov[k].enfants[i].occurence;
            if(toNumber>=number){
                return markov[k].enfants[i].name;
            }
        }
        

    }
    else{
        return "";
    }


}

// function returning the position of the parent in the markov chain 
int find_parent(string name){
    for(int i=0;i<markov.size();i++){
        if(name==markov[i].name){
            return i;
        }
    }
    return -1;
}

// function printing the markov chain in order to check the function learn()
void affiche(){
    cout <<"\n";
    cout << "\n" << "Chaîne de Markov" << endl;

    for(int i=0;i<markov.size();i++){
        cout << "new -> "  << markov[i].name << endl;
        for(int j=0;j<markov[i].enfants.size();j++){
            cout << markov[i].enfants[j].name << ",";
        }
        cout << endl;
    }
    cout <<"\n";
}

// function learning and fulling the markob chain 
int learn(string &name_file){

    int lenght=0;
    ifstream monFichier(name_file);
    vector <string> list_mot;

    if(monFichier)  //On teste si tout est OK
    {
        //Tout est OK, on peut utiliser le fichier
        string word;
        while(monFichier >> word){
            lenght++;
            list_mot.push_back(word);
        }
    }
    else
    {
    cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }

    monFichier.close();

    // ______________TEST______________

    /*
    for(int i=0;i<list_mot.size();i++){
        cout << list_mot[i] << "\n";
    }
    */

    // _____________AJOUT______________

    
    string prv="";
    for(int i=0;i<list_mot.size();i++){
        add_item(prv, list_mot[i]);
        prv=list_mot[i];
    }

    //affiche();

    return lenght;

}

// function adding in the markov chain the fact that name_enfant is after name_parent
void add_item(string name_parent, string name_enfant){

    int k=find_parent(name_parent);
    bool oui=false;
    if(k!=-1){
        for(int i=0;i<markov[k].enfants.size();i++){
            if(markov[k].enfants[i].name==name_enfant){
                markov[k].enfants[i].occurence += 1;
                oui=true;
            }
        }
        if(oui==false){
            enfant.name=name_enfant;
            enfant.occurence=1;
            markov[k].enfants.push_back(enfant);
        }
    }
    else{
        enfant.occurence=1;
        enfant.name=name_enfant;
        (parent.enfants).push_back(enfant);
        parent.name=name_parent;
        markov.push_back(parent);
        parent.enfants.clear();
    }

    //affiche();
}

int main(){


    string name_file,name_result; 

    cout <<  "(Give me a name of text file to learn how to mix words commonly ) Donner un texte avec lequel apprendre " << endl;

    cin >> name_file;

    cout <<  "(Give me a name of text file to write it the result of the execution of the program ) Donner un nom de fichier texte pour y écrire le résultat " << endl;

    cin >> name_result;
    
    srand(time(0));

    int n=learn(name_file);
    //affiche();

    write(n, name_result);

    //affiche();

    reset();

    return 0;
}