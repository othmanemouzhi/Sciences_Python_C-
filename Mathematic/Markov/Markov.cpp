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


void write(int lenght,string name_result){
    string text="";
    string prv="";
    for(int i=0;i<lenght;i++){
        string word=pick_one(prv);
        text += word + " ";

        //cout << prv << " -> " << word << endl;

        prv=word;


    }

    ofstream Result(name_result);
    if(Result){
        Result << text;
    }
    else{
        cout << "ERROR:COULDN'T OPEN THE FILE" << endl;
    }


    //cout << text << endl;

}

void reset(){
    markov.clear();
}

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

int find_parent(string name){
    for(int i=0;i<markov.size();i++){
        if(name==markov[i].name){
            return i;
        }
    }
    return -1;
}

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
        //cout << "oui" << endl;
        add_item(prv, list_mot[i]);
        //cout << "oui1" << endl;
        //cout << " " << prv << "  " << list_mot[i] << endl;
        prv=list_mot[i];
    }
    

    //affiche();

    return lenght;

}

void add_item(string name_parent, string name_enfant){

    int k=find_parent(name_parent);
    bool oui=false;
    //cout << "oui2" << endl;
    if(k!=-1){
        //cout << "1";
        //cout << "oui2.0" << endl;
        for(int i=0;i<markov[k].enfants.size();i++){
            //cout << "oui2.1" << endl;
            if(markov[k].enfants[i].name==name_enfant){
                markov[k].enfants[i].occurence += 1;
                oui=true;
            }
        }
        //cout << "oui2.2" << endl;
        if(oui==false){
            enfant.name=name_enfant;
            enfant.occurence=1;
            markov[k].enfants.push_back(enfant);
        }
    }
    else{
        //cout << "2";
        //cout << "oui2.3" << endl;
        enfant.occurence=1;
        //cout << "oui2.35" << endl;
        enfant.name=name_enfant;
        //cout << "oui2.4" << endl;
        (parent.enfants).push_back(enfant);
        parent.name=name_parent;
        markov.push_back(parent);
        parent.enfants.clear();
    }
    //cout << "oui3" << endl;

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