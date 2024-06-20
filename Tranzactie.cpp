
#include "Tranzactie.h"

Tranzactie::Tranzactie() {
    bancnoteTranzactie.first = VectorDinamic();
    bancnoteTranzactie.second = VectorDinamic();
}

void Tranzactie::add_bani(int val, int occ) {
    bancnoteTranzactie.first.push_back(val);
    bancnoteTranzactie.second.push_back(occ);
}

int Tranzactie::get_val(int poz) const {
    return bancnoteTranzactie.first.getAt(poz);
}

int Tranzactie::get_occ(int poz) const {
    return bancnoteTranzactie.second.getAt(poz);
}

void Tranzactie::set_sum(int sum) {
    this->suma = sum;
}

void Tranzactie::set_id(int nr) {
    this->id = nr;
}

int Tranzactie::get_nr_bancnote() const {
    return this->bancnoteTranzactie.first.size();
}

int Tranzactie::get_id() const {
    return id;
}