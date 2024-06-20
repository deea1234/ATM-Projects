
#include "Colectie.h"

Colectie::Colectie() {
    this->bancnote.first = VectorDinamic(5);
    this->bancnote.second = VectorDinamic(5);
}

void Colectie::add_bancnota(TElem elem, TElem occ){
    this->bancnote.first.push_back(elem);
    this->bancnote.second.push_back(occ);
}

int Colectie::getSize() {
    return this->bancnote.first.size();
}

Colectie &Colectie::operator=(Colectie colectie) {
    int size = colectie.bancnote.first.size();
    this->bancnote.first = VectorDinamic();
    this->bancnote.second = VectorDinamic();

    for(int i = 0; i < size; i++){
        this->bancnote.first.push_back(colectie.bancnote.first.getAt(i));
        this->bancnote.second.push_back(colectie.bancnote.second.getAt(i));
    }

    return *this;
}

TElem Colectie::get_val(int poz) {
    return this->bancnote.first.getAt(poz);
}

TElem Colectie::get_occ(int poz) {
    return this->bancnote.second.getAt(poz);
}

void Colectie::set_occ(TElem val, TElem occ) {
    int poz = search_poz(val);
    if(poz != -1)
        this->bancnote.second.update(poz, occ);
}

int Colectie::search_poz(TElem val) {
    int size = this->bancnote.first.size();
    for(int i = 0; i < size; i++)
    {
        if(this->bancnote.first.getAt(i) == val)
            return i;
    }
    return -1;
}
