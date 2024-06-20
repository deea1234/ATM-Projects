

#ifndef LAB3_TRANZACTIE_H
#define LAB3_TRANZACTIE_H
#include "VectorDinamic.h"
#include <utility>

class Tranzactie {
private:
    int id;
    int suma;
    std::pair<VectorDinamic, VectorDinamic> bancnoteTranzactie;

public:
    ///constructor fara parametrii
    Tranzactie();

    /// adauga un set de bancnote = (tip; frecventa) in tranzactie
    /// \param val - tipul de banc.
    /// \param occ - frecventa banc.
    void add_bani(int val, int occ);

    /// actualizeaza suma din tranzactie
    /// \param suma - nr nat. pozitiv
    void set_sum(int sum);

    /// seteaza id ul tranzactiei
    /// \param nr - int natural.
    void set_id(int nr);

    int get_id() const;

    /// \param poz - nr nat intre 0 si size()
    /// \return tipul banc din tranzactie
    int get_val(int poz) const;

    /// \param poz - nr nat intre 0 si size()
    /// \return frecventa banc din tranzactie
    int get_occ(int poz) const;

    /// \return - cate bancnote diferite sunt in tranzactie
    int get_nr_bancnote() const;
};

#endif //LAB3_TRANZACTIE_H
