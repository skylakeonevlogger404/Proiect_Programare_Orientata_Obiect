#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

class Jucarie{//clasa Jucarie contine atributele unei jucarii
private:
    string denumire;
    string culoare_ambalaj;
    int pret;
    int stoc;
public:
    Jucarie(){
        denumire = "";
        pret = 0;
        stoc = 0;
    }

    void set(string denumire, int pret, int stoc){//setter pentru denumire pret si stoc al jucariei
        this->denumire = denumire;
        this->culoare_ambalaj = culoare_ambalaj;
        this->pret = pret;
        this->stoc = stoc;
    }

    void set_culoare_ambalaj(string culoare_ambalaj){//setter culoare ambalaj
        this->culoare_ambalaj = culoare_ambalaj;
    }

    int get_pret(){//getter pentru pret
        return pret;
    }

    string get_denumire(){//getter denumire
        return denumire;
    }

    void adaugare_stoc(int val){//setare stock
        this->stoc += val;
    }

    void decr_stoc(){//getter decrementare stoc
        stoc --;
    }

    bool verificare_stoc(){//verificare stoc 1 este pe stoc 0 stoc insuficient
        if(stoc > 0){
            return true;
        }
        return false;
    }

    string get_culoare_ambalaj(){//setter ambalaj
        return this->culoare_ambalaj;
    }

    void print(){
        // cout << "=========Stocul ELFILOR=========" << endl; //stocul elfilor dupa adaugarea cadourilor in punga
        // cout << "denumire: " << denumire << endl;
        // cout << "pret: " << pret << endl;
        // cout << "stoc: " << stoc << endl;
    }
};

class Inventar{//clasa inventar contine si o jucarie cu atributele necesare
private:
    Jucarie jucarii[10];
    int nr_jucarii;
    int nr_carbuni;
public:
    Inventar(){
        nr_jucarii = 0;
    }

    void adaugare_jucarie(string denumire, int pret, int stoc, string culoare_ambalaj){//adaugam jucaria in inventar

        jucarii[nr_jucarii].set(denumire, pret, stoc);
        jucarii[nr_jucarii].set_culoare_ambalaj(culoare_ambalaj);
        nr_jucarii++;
        
    }

    void print(){
        for( int i=0; i < nr_jucarii; i++){//afisam jucariile existente
            jucarii[i].print();
        }
    }

    bool verificare_stoc(string denumire){//verificare stoc fiecare jucarie
        string den;
        for(int i=0; i < nr_jucarii; i++){
            den = jucarii[i].get_denumire();
            if(den == denumire){
                return jucarii[i].verificare_stoc();
            }
        }
        return false;
    }

    int get_pret_jucarie(string denumire){//pretul fiecarei jucarii
        string den;
        for(int i=0; i < nr_jucarii; i++){
            den = jucarii[i].get_denumire();
            if(den == denumire){
                return jucarii[i].get_pret();
            }
        }
        return 101;//returnez 101 pentru ca putem sa avem cazul in care jucaria depaseste bugetul alocat returnam 101 ca sa
        //ca sa nu poate fi jucaria alocata copilului
    }

    void decr_stoc(string denumire){//functie decrementare stoc, ori de cate ori este luata o masinuta scad din stocul total al masinutelor val X
        string den;
        for(int i=0; i < nr_jucarii; i++){
            den = jucarii[i].get_denumire();
            if(den == denumire){
                jucarii[i].decr_stoc();
            }
        }
    }

    void get_ambalaje(int& ambalaje_fete, int& ambalaje_baieti){//setarea categoriilor ambalajelor pentru fete si baieti
        string culoare_ambalaj;
        for(int i=1; i < nr_jucarii;i++){//incepe de la 1 ca sa nu numere cadoul cu acelasi nume de doua ori
            culoare_ambalaj = jucarii[i].get_culoare_ambalaj();
            if(culoare_ambalaj == "albastru"){
                ambalaje_baieti++;
            }
            if(culoare_ambalaj == "roz"){
                ambalaje_fete++;
            }
        }
    }

    int get_nr_carbuni(){//nr total de carbuni folositi
        string den;
        this->nr_carbuni = 0;
        for(int i = 0; i < nr_jucarii; i++){
            den = jucarii[i].get_denumire();
            if(den == "carbune"){
                this->nr_carbuni ++;
            }
        }
        return this->nr_carbuni;
    }

};

class Copil{
private:
    string Lastname;//prenume
    string Firstname;//nume
    string City;//oras
    int Age;//varsta
    string* wishlist;
    int wishlist_len;
    string gen;
public:
    Copil(){//constructor default copil
        this->Lastname = "";
        this->Firstname = "";
        this->City = "";
        this->Age = 0;
        this->wishlist_len = 0;
        this->wishlist = nullptr;
    }
    Copil (string Lastname, string Firstname, string City, int Age, string* wishlist, int wishlist_len){//constructor copil cu parametrii
        this->Lastname = Lastname;
        this->Firstname = Firstname;
        this->City = City;
        this->Age = Age;
        this->wishlist_len = wishlist_len;
        if(this->wishlist_len > 0){
            this->wishlist = new string[this->wishlist_len];
            for(int i =  0; i < this->wishlist_len; i++){
                this->wishlist[i] = wishlist[i];
            }
        }else{
            this->wishlist = nullptr;
        }
    }
    void set(string Lastname, string Firstname, string City, int Age, string* wishlist, int wishlist_len){//functie parametrii copil si wish
        this->Lastname = Lastname;
        this->Firstname = Firstname;
        this->City = City;
        this->Age = Age;
        this->wishlist_len = wishlist_len;

        if(this->wishlist != nullptr){//verificarea daca lista de dorinte este goala
            delete[] wishlist;
        }

        if(this->wishlist_len > 0){//daca nu este goala notam in ea dorintele
            this->wishlist = new string[this->wishlist_len];
            for(int i =  0; i < this->wishlist_len; i++){
                this->wishlist[i] = wishlist[i];
            }         
        }else{
            this->wishlist = nullptr;
        }
    }
    void set_gen(string gen){//setter pentru gen
        this->gen = gen;
    }
    void print(){//functie afisare caracteristici copil
        cout << "Nume: " << this->Lastname << endl;
        cout << "Prenume: " << this->Firstname << endl;
        cout << "Oras: " << this->City << endl;
        cout << "Varsta: " << this->Age << endl;
        cout << "wishlist: ";
        for(int i =  0; i < this->wishlist_len; i++){
               cout << this->wishlist[i] << " "; 
        }
        cout << endl;
    }

    string get_oras(){//getter oras
        return this->City;
    }

    int get_wishlist_len(){//getter dimensiunea wishlist
        return this->wishlist_len;
    }

    string get_wishlist_elem(int i){//getter elemente wishlist
        if( i < wishlist_len ){
            return wishlist[i];
        }
        return "";
    }
    
    string get_gen_copil(){//getter gen copil
        return this->gen;
    }

    ~Copil();//destructor copil
};

class Scrisoare{
private:
    Copil copil;
    string Colour;//culoare
public:
    Scrisoare(){

    }
    Scrisoare(Copil copil, string Colour){//setter culoare scrisoare a plicului
        this->copil = copil;
        this->Colour = Colour;
    }
    void set(Copil copil, string Colour){
        this->copil = copil;
        this->Colour = Colour;
    }
    void print(){
        // copil.print();
        cout << "Culoare: " << Colour << endl;
    }
    string get_gen(){//getter culoare in functie de sexul copilului
        if(Colour == "roz"){
            return "fata";
        }
        if(Colour == "albastru"){
            return "baiat";
        }
        return "";
    }
     ~Scrisoare();//destructor scrisoare
};

Scrisoare::~Scrisoare(){//definirea destructorului
    // cout << "Object SCRISOARE has been deleted!" << endl;
}

Copil::~Copil(){//definirea copilului
    // cout << "Object COPIL has been deleted!" << endl;
    // if(wishlist!=nullptr){
    //     delete[] wishlist;
    // }
}

class Buget{
    Copil copil;
    string jucarii_alocate[10];
    int nr_jucarii_alocate;
    bool Status;
    int suma;
public:
    void set(Copil copil, bool Status, string gen){//setter status jucarii alocate si buget
        this->copil = copil;
        this->copil.set_gen(gen);
        this->Status = Status;
        this->nr_jucarii_alocate = 0;
    }

    void set_suma(int suma){//setter buget alocat
        this->suma = suma;
    }

    void decr_suma(int value){//setter pentru suma cand cheltuie pe o jucarie
        this->suma = this->suma - value;
    }

    bool get_status(){//getter pentru status copil cuminte/rau
        return Status;
    }

    void print(){
        copil.print();
        cout << "Status: " << Status << endl;//status copil
        cout << "Suma: " << suma << endl;//buget actual
        cout << "jucarii alocate: ";//ce jucarii isi doreste
        for(int i=0; i < nr_jucarii_alocate; i++){
            cout << jucarii_alocate[i] << " ";
        }
        cout << endl << "------------------------------";
        cout << endl;
    }

    void alocare_jucarie(string denumire){//ii alocam o jucarie si memoram
        this->jucarii_alocate[nr_jucarii_alocate] = denumire;
        nr_jucarii_alocate++;
    }
    
    int get_suma(){//getter pentru suma ramasa
        return suma;
    }
    
    Copil get_copil(){
        return copil;
    }
};

class Elf{
    Buget bugete[5];
    Scrisoare scrisori[5];
    Inventar inv;
    int nr_bugete;
    int nr_acadele;
    string lista_jucarii[30];
    int nr_lista_jucarii;
    Inventar jucarii_alocate;

public:
    Elf(){//constructor default elf
        nr_bugete = 0;
        nr_lista_jucarii = 0;
        nr_acadele = 0;
    }

    void get_orase(string* &orase, int& nr_orase){//afisarea oraselor
        for(int i=0; i < nr_bugete; i++){
            orase[nr_orase] = bugete[i].get_copil().get_oras();
            nr_orase++;
        }
    }

    void set(Copil* copii, bool* status, Scrisoare* scrisori, int nr_copii){
        this->nr_bugete = nr_copii;
        for(int i=0; i < nr_copii; i++){
            bugete[i].set(copii[i], status[i], scrisori[i].get_gen());//alocare buget in functie de params
        }
    }

    void print(){//calcularea bugetului
        for(int i = 0; i < nr_bugete; i++){
            bugete[i].print();//afisare inv
        }
    }

    void print_inventar(){
        this->inv.print();//afisare inventar final alocat
    }

    void calculare_bugete(){//calcularea bugetului in functie de statusul copilului
        for(int i=0; i < nr_bugete; i++){
            if(bugete[i].get_status() == true){
                bugete[i].set_suma(100);
            }else{
                bugete[i].set_suma(10);
            }
        }
    }

    int get_nr_acadele(){//getter pentru nr de acadele
        return nr_acadele;
    }

    Inventar get_jucarii_alocate(){
        return this->jucarii_alocate;//getter pentru jucariile alocate copilului
    }

    void alocare_jucarii(Inventar inv, int nr_jucarii){//functie alocare jucarii
        this->calculare_bugete();
        this->inv = inv;
        string jucarie_dorita;
        int pret_jucarie_dorita;
        string jucarie_default_10 = "Cadou_10";//cadou default de 10 dolari
        string jucarie_default_100 = "Cadou_100";//cadou default de 100 dolari
        bool ok = false;
        string culoare_ambalaj = "";

        //am parcurs toate bugetele alocate copiilor
        for(int i=0; i < nr_bugete; i++){
            ok = false;

            if(bugete[i].get_copil().get_gen_copil() == "baiat"){
                culoare_ambalaj = "albastru";
            }else{
                culoare_ambalaj = "roz";
            }

            if(bugete[i].get_status() == false){
                this->jucarii_alocate.adaugare_jucarie("carbune", 0, 1, culoare_ambalaj);
            }

            //pentru fiecare copil am luat fiecare jucarie din wishlist
            for(int j=0; j<bugete[i].get_copil().get_wishlist_len(); j++)
            {
                //denumirea jucariei curente am pus-o in jucarie_dorita
                jucarie_dorita = bugete[i].get_copil().get_wishlist_elem(j);
                //verificarea inventarului
                if( this->inv.verificare_stoc(jucarie_dorita) == true ){
                    //daca jucaria este in stoc atunci ii luam pretul
                    pret_jucarie_dorita = this->inv.get_pret_jucarie(jucarie_dorita);
                    //verificam daca pretul jucariei este mai mic decat bugetul
                    if(bugete[i].get_suma() > pret_jucarie_dorita){
                        ok = true;
                        //daca pretul jucariei este mai mic decat bugetul si ea este in stoc atunci 
                        //ii alocam copilului jucaria si scadem pretul jucariei din suma bugetului
                        bugete[i].alocare_jucarie(jucarie_dorita);
                        bugete[i].decr_suma(pret_jucarie_dorita);
                        this->inv.decr_stoc(jucarie_dorita);
                        this->jucarii_alocate.adaugare_jucarie(jucarie_dorita, pret_jucarie_dorita, 1, culoare_ambalaj);
                    }
                }
            }
            if(ok == false){
                if(bugete[i].get_status()){
                    bugete[i].alocare_jucarie(jucarie_default_100);
                    bugete[i].decr_suma(100);
                    this->jucarii_alocate.adaugare_jucarie(jucarie_default_100, 100, 1, culoare_ambalaj);
                }else{
                    bugete[i].alocare_jucarie(jucarie_default_10);
                    bugete[i].decr_suma(10);//practic ramane pe zero pentru ca i se atribuie 10$ ca a fost rau dupa care el ii da pe cadou si ramane cu 0
                    this->jucarii_alocate.adaugare_jucarie(jucarie_default_10, 10, 1, culoare_ambalaj);
                }
            }
            this->nr_acadele = this->nr_acadele + bugete[i].get_suma();
        }
    } 
};

class Trol{
private:
    Inventar inventar;
    int nr_ambalaje_fete;
    int nr_ambalaje_baieti;
public:
    Trol(){//constructor trol si inainte de impachetare are 0 ambalaje fete 0 baieti
        this->nr_ambalaje_baieti = 0;
        this->nr_ambalaje_fete = 0;
    }
    void adaugare_cadou(string denumire_cadou){
        this->inventar.adaugare_jucarie(denumire_cadou, 0, 1, ""); //adaugam jucarie in inv trolului 
    }
    void set_inventar(Inventar inventar){
        this->inventar = inventar;//seetter inventar trol
    }
    void print(){
        inventar.print();
        cout << "ambalaje fete: " << nr_ambalaje_fete << endl;//nr de ambalaje fete
        cout << "ambalaje baieti: " << nr_ambalaje_baieti << endl;//nr de ambalaje baieti
    }
    void ambalare_jucarii(){
        inventar.get_ambalaje(nr_ambalaje_fete, nr_ambalaje_baieti);
    }
    int get_nr_carbuni(){
        return inventar.get_nr_carbuni();
    }
};

class DoamnaCraciun{
private:
    int numar_acadele;
    int numar_carbuni;
public:
    DoamnaCraciun(){
        numar_acadele = 0;//inainte de alocare nr acadele este 0
        numar_carbuni = 0;//inainte de alocare nr carbuni este 0
    }
    void adaugare_acadele(int numar_acadele){
        this->numar_acadele = this->numar_acadele + numar_acadele;//calcularea acadelelor in functie de bugetul ramas
    }
    void adaugare_carbuni(int nr_carbuni){//calcularea carbunilor in functie de bugetul ramas
        this->numar_carbuni = this->numar_carbuni + nr_carbuni;
    }
    void print(){
        cout <<"Acadele: " << numar_acadele << endl;//cate acadele
        cout <<"Carbuni: " << numar_carbuni << endl;//cati carbuni
    }
    float total_cost(){
        cout << "Total carbuni + acadele: ";//afisarea nr total acadele+carbuni
        return (float)(numar_acadele + (float)numar_carbuni/2);
    }
};

class MosCraciun{
private:
    string orase[5];
    int nr_orase;
public:
    MosCraciun(){
        nr_orase = 0;
    }
    void adaugare_oras(string oras){//adaugarea oraselor in lista
        this->orase[this->nr_orase] = oras;
        this->nr_orase++;
    }
    void set_orase(string* orase, int nr_orase){//adaugarea oraselor in lista lui mos craciun
        for(int i=0; i<nr_orase; i++){
            this->orase[i] = orase[i];
        }
        this->nr_orase = nr_orase;
    }
    void print(){//afisarea oraselor din lista mosului
        cout <<"Orasele lui Mos Craciun: ";
        for(int i=0; i < nr_orase; i++){
            cout << orase[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    string wishlist[] = {"masinuta", "robot", "excavator"}; //wishilit primit ca parametru pentru fiecare copil
    string wishlist1[] = {"masinuta", "papusa"};
    string wishlist2[] = {"masinuta", "robot", "papusa"};

    bool status[] = {true, false, true}; // lista cu statusul fiecarui copil pe care elfi il au deja

    Copil copii[5]; //instantierea obiectelor copii maxim 5 cum este specificat in cerinta
    Scrisoare scrisori[5]; //instantierea obiectelor tip scrisoare
    Elf elf; //instantiere elf
    Inventar inv; // adaugare inventar
    MosCraciun mos_craciun; 
    DoamnaCraciun doamna_craciun;
    Trol trol;
    string* orase; //lista orase
    orase = new string[5]; //total nr orase existente
    int nr_orase;
    Inventar jucarii_alocate; //jucarii alocate

    copii[0].set("Marius", "Andrei", "Bucuresti", 9, wishlist, 3);//definierea parametrilor fiecarui copil
    copii[1].set("Radu", "Popescu", "Iasi", 17, wishlist1, 2);
    copii[2].set("Mihaela", "Andreea", "Timisoara", 11, wishlist2, 3);

    scrisori[0].set(copii[0], "albastru");//lista cu culorile plicului al copiilor ce trimit scrisori
    scrisori[1].set(copii[1], "albastru");
    scrisori[2].set(copii[2], "roz");

    cout << "----Culorile scrisorilor-----" << endl;
    scrisori[0].print();//culoare scrisoare copil 1
    scrisori[1].print();
    scrisori[2].print();
    elf.set(copii, status, scrisori, 3);
    cout << "-----------------------------" << endl;

    elf.print(); //verificare stoc jucarii
    inv.adaugare_jucarie("masinuta", 30, 1, "");//aici adaugam in inventar doar jucariile folosite
    inv.adaugare_jucarie("robot", 20, 4, "");   //sigur ca acest lucru il fac elfi
    inv.adaugare_jucarie("excavator", 80, 0, "");
    inv.adaugare_jucarie("papusa", 5, 0, "");

    // inv.print();
    elf.alocare_jucarii(inv, 4);

    //trimitere jucarii la troli
    jucarii_alocate = elf.get_jucarii_alocate();
    trol.set_inventar(jucarii_alocate);
    trol.ambalare_jucarii();

    //creare liste orase si trimitere lui Mos Craciun
    elf.get_orase(orase, nr_orase);
    mos_craciun.set_orase(orase, nr_orase);

    //trimitere acadele doamne craciun
    doamna_craciun.adaugare_acadele(elf.get_nr_acadele());
    doamna_craciun.adaugare_carbuni(trol.get_nr_carbuni());

    //trimitere inventar jucarii alocate de la elf la trol
    jucarii_alocate = elf.get_jucarii_alocate();
    jucarii_alocate.print();
    
    cout << "Dupa verificarea jucariilor in stoc si alocarea acestora copiilor" << endl;
    elf.print();//inventarul elfilor
    elf.print_inventar();//afisarea stocului elfilor dupa ce am verificat fiecare jucarie si au pus-o in punga

    //Acadele+carbuni+ambalaje_fete/baieti
    doamna_craciun.print();
    trol.print();

    //Total acadele + carbuni
    cout << doamna_craciun.total_cost() << endl; //am presupus ca o acadea costa 1$

    //orasele lui mos craciun
    mos_craciun.print();

    // string* orase;
    // orase = new string[5];
    // int nr_orase = 0;
    // elf.get_orase(orase, nr_orase); //afisare orase mos craciun
    // for(int i=0; i < nr_orase; i++){
    //     cout<<orase[i] <<endl;
    // }

    return 0;
}