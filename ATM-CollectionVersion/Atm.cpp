
#include "Atm.h"

Atm::Atm() {
    this->bancnote = Colectie();
    this->array_t = new Tranzactie[10];
    this->capacitate = 10;
    this->noTranzacti = 0;
}

Atm::Atm(const Colectie& colectie) {
    this->array_t = new Tranzactie[10];
    this->capacitate = 10;
    this->noTranzacti = 0;
    this->bancnote = colectie;
}

void Atm::resize() {
    capacitate *= 2;
    auto *tmp = new Tranzactie[this -> capacitate];
    for(int i = 0 ; i < this -> noTranzacti; i++){
        tmp[i] = this -> array_t[i];
    }
    delete [] this -> array_t;
    this -> array_t = tmp;
}

void Atm::add_tranzactie(Tranzactie t) {
    if(this->noTranzacti == this->capacitate)
        resize();
    t.set_id(noTranzacti);
    int size = t.get_nr_bancnote();

    //sterge nr. de bancnote utilizate in tranzactia data
    for(int i = 0; i < size; i++){
        int val = t.get_val(i);
        int occ = t.get_occ(i);
        this->array_t[i].add_bani(val, occ);

        int occ_bank = bancnote.get_occ(bancnote.search_poz(val));
        this->bancnote.set_occ(val, occ_bank - occ);
    }

    this->array_t[noTranzacti] = t;
    this->noTranzacti++;
}

Tranzactie *Atm::getAllT() {
    return array_t;
}

int Atm::get_noTranzacti() {
    return noTranzacti;
}

Colectie Atm::get_Colectie() {
    return bancnote;
}

Tranzactie Atm::verifica_suma_vector(int suma) {
    int size_bank = bancnote.getSize();
    int copy = suma;
    int val, occ;
    int index_bank = 0;

    Tranzactie t;
    t.set_sum(copy);

    while(index_bank < size_bank && copy){
        val = bancnote.get_val(index_bank);
        if(copy >= val){
            occ = copy / val;

            if(occ > bancnote.get_occ(index_bank) && occ!=0)
                occ = bancnote.get_occ(index_bank);
            t.add_bani(val, occ);
            copy -= occ*val;
        }
        index_bank++;
    }
    if (copy){
        t=Tranzactie();
        return t;
    }
    return t;
}
