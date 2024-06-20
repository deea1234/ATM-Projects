//
// Created by Raluca on 4/20/2023.
//
#ifndef CURS6_VECTORDINAMIC_H
#define CURS6_VECTORDINAMIC_H

#include <utility>
typedef int TElem;

class VectorDinamic{
private:
    int capacity;
    int nrElems;
    TElem* elems;

    void resize();
public:
    VectorDinamic();

    /// Constructor cu parametri
    /// \param capacitate - se aloca memorie pentru un vector de capacitate elemente
    /// \raise invalid input exception, daca capacitate <= 0
    VectorDinamic (int capacitate);

    ///
    /// \return numarul de elemente din vectorul dinamic
    int size() const;

    ///
    /// \param i, 0 <= i < numarul de elemente din vector
    /// \return elementul de pe pozitia i din vector
    /// \raise invalid input exception, daca i nu este o pozitie valida
    TElem getAt(int i) const;

    /// actualizeaza elementul de pe pozitia i cu valoarea e
    /// \param i, 0 <= i < numarul de elemente din vector
    /// \param e, element de tip TElem
    /// \return elementul de pe pozitia i care a fost inlocuit cu e
    /// \raise invalid input exception, daca i nu este o pozitie valida
    TElem update(int i, TElem e);

    /// adauga un element la sfarsitul vectorului
    /// \param e, element de tip TElem, elem adaugat la final
    void push_back(TElem e);

    /// adauga un element pe pozitia i
    /// \param i, 0 <= i < numarul de elemente din vector
    /// \param e, element de tip TElem
    /// \raise invalid input exception, daca i nu este o pozitie valida
    void addAt(int i, TElem e);

    /// stergem elementul de pe pozitia i
    /// \param i, 0 <= i < numarul de elemente din vector
    /// \return elementul de pe pozitia i
    TElem sterge(int i);

    /// destructor - dealoca memoria
    ~VectorDinamic();

};

#endif //CURS6_VECTORDINAMIC_H