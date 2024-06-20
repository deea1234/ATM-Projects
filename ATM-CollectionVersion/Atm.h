//
// Created by Raluca on 4/24/2023.
//

#ifndef LAB3_ATM_H
#define LAB3_ATM_H
#include "Colectie.h"
#include "Tranzactie.h"

class Atm {
private:
    Colectie bancnote;
    int capacitate;
    int noTranzacti;
    Tranzactie *array_t;
public:
    ///constructor fara parametrii
    Atm();

    /// colectie cu parametrul colectie
    /// \param colectie  - obiect abstract de tip Colectie
    explicit Atm(const Colectie& colectie);

    void resize();

    /// adauga o tranzactie in atm
    /// \param t - obiect abstract de tip Tranzactie
    void add_tranzactie(Tranzactie t);

    /// \param suma - suma solicitata, nr intreg pozitiv
    /// \return tranzactie cu suma data
    Tranzactie verifica_suma_vector(int suma);

    ///returneaza array de tranzactii memorate de atm
    Tranzactie *getAllT();

    ///\return nr de tranzactii
    int get_noTranzacti();

    ///\return colectia de bancnote salvata in atm
    Colectie get_Colectie();
};


#endif //LAB3_ATM_H
