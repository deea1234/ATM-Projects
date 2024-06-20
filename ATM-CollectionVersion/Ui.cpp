
#include "Atm.h"
#include "Colectie.h"
#include "Tranzactie.h"
#include "Ui.h"

void printMenu(){
    cout<<"1. stocare bancnote\n";
    cout<<"2. inregistrare tranzactii\n";
    cout<<"3. Afisare bancnote\n";
    cout<<"4. afisare tranzactii\n";
    cout<<"0. Iesire\n";
}

void creareColectie(Colectie &colectie){
    int n;
    cout<<"numarul de bancnote: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        int valoare, nr_exemplare;
        cout<<"valoare: ";
        cin>>valoare;
        cout<<"numar exemplare: ";
        cin>>nr_exemplare;
        colectie.add_bancnota(valoare, nr_exemplare);
    }
}

void print_bancnote(Atm &atm){
    int size = atm.get_Colectie().getSize();
    for(int poz = 0; poz < size - 1; poz++){
        cout<<atm.get_Colectie().get_val(poz)<<"*"<<atm.get_Colectie().get_occ(poz)<<"+"<<endl;
    }
    cout<<atm.get_Colectie().get_val(size-1)<<"*"<<atm.get_Colectie().get_occ(size-1);
}

void afisare_suma(Tranzactie t){
    int size = t.get_nr_bancnote();
    for(int poz = 0; poz < size; poz++){
        cout<<"valoare: "<<t.get_val(poz)<<"; frecventa: "<<t.get_occ(poz)<<endl;
    }
}

void afisare_tranzactii(Atm atm){
    Tranzactie *tranz = atm.getAllT();
    int size = atm.get_noTranzacti();
    for(int poz = 0; poz < size; poz++){
        cout<<"id: "<<tranz[poz].get_id()<<" ";
        afisare_suma(tranz[poz]);
        cout<<endl;
    }
}

void inregistrare_tranzactie(Atm &atm){
    int suma;
    cin>>suma;
    Tranzactie t = atm.verifica_suma_vector(suma);
    int size = t.get_nr_bancnote();
    if(size == 0)
        cout<<"nu exista bancnote pentru suma solicitata\n";
    else{
        afisare_suma(t);
        cout<<"apasati 1 pentru salvare si 0 in caz contrar";
        bool ok;
        cin>>ok;
        if(ok)
            atm.add_tranzactie(t);
    }
}

void Ui::consola() {
    int optiune = 1;
    Atm atm;
    Colectie colectie;
    while(optiune){
        printMenu();
        cout<<"optiunea dorita: ";
        cin>>optiune;
        switch(optiune){
            case 0:
                break;
            case 1:
                creareColectie(colectie);
                atm = Atm(colectie);
                cout<<endl;
                break;
            case 2:
                inregistrare_tranzactie(atm);
                break;
            case 3:
                print_bancnote(atm);
                cout<<endl;
                break;
            case 4:
                afisare_tranzactii(atm);
                break;
        }
    }
}
