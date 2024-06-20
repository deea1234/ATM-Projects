//
// Created by Raluca on 4/20/2023.
//
#ifndef LAB3_COLECTIE_H
#define LAB3_COLECTIE_H
#include <iostream>
#include <utility>
#include "VectorDinamic.h"
using namespace std;
typedef int TElem;

class Colectie {
private:
    pair<VectorDinamic, VectorDinamic> bancnote;
public:
    /// constructor fara parametrii
    Colectie();

    /// .first - array de elemente
    /// .second - array de frecvente
    /// \param elem - elementul adaugat
    /// \param occ - frecventa elementului adaugat
    void add_bancnota(TElem elem, TElem occ);

    /// \return nr de elemente memorate
    int getSize();

    /// \param colectie - obiect abstract
    /// \return "=" operator overloading
    Colectie& operator=(Colectie colectie);

    /// \param poz - nr nat intre 0 si size()
    /// \return elementul de pe pozitia data
    TElem get_val(int poz);

    /// \param poz - nr nat. intre 0 si size()
    /// \return frecventa elementului de pe pozitia poz
    TElem get_occ(int poz);

    /// modifica frecventa unei bancnote date
    /// \param val - valoarea bancnotei, nr natural
    /// \param occ - noua frecventa a bancnotei, nar. natural
    void set_occ(TElem val, TElem occ);

    /// cauta pozitia unui element dat sau -1 in caz contrar
    /// \param val - elementul cautat
    int search_poz(TElem val);
};

#endif //LAB3_COLECTIE_H