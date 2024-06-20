//
// Created by Raluca on 4/20/2023.
//
#include <iostream>
#include "VectorDinamic.h"

VectorDinamic::VectorDinamic(int capacitate) {
    if(capacitate <= 0)
        throw std::invalid_argument("capacitatea trebuie sa fie un numar pozitiv");
    this->capacity = capacitate;
    this->elems = new TElem [capacitate];
    this->nrElems = 0;
}

VectorDinamic::VectorDinamic() {
    this->capacity = 10;
    this->elems = new TElem [10];
    this->nrElems = 0;
}

int VectorDinamic::size() const {
    return this->nrElems;
}

TElem VectorDinamic::getAt(int i) const {
    if(i < 0 || i >= nrElems)
        throw std::invalid_argument("pozitie invalida");
    return this->elems[i];
}

TElem VectorDinamic::update(int i, TElem e) {
    //TODO - IMPLEMENT METHOD
    if(i < 0 || i >= nrElems)
        throw std::invalid_argument("pozitie invalida");
    TElem elem = elems[i];
    elems[i] = e;
    return elem;
}

void VectorDinamic::push_back(TElem e) {
    if (nrElems == capacity)
        resize();
    this->elems[nrElems] = e;
    this->nrElems ++;
}

void VectorDinamic::addAt(int i, TElem e) {
    if (nrElems == capacity)
        resize();
    for(int index = nrElems; index >= i; index--){
        elems[index] = elems[index-1];
    }
    elems[i] = e;
    nrElems++;
}

TElem VectorDinamic::sterge(int i) {
    TElem elem = elems[i];
    for(int index = i; index < nrElems; index--){
        elems[index] = elems[index+1];
    }
    nrElems--;
    return elem;
}

VectorDinamic::~VectorDinamic() {
    //TODO - IMPLEMENT METHOD
}

void VectorDinamic::resize() {
    auto* copy = new TElem [capacity*2];
    for(int i = 0; i < nrElems; i++)
        copy[i] = elems[i];
    capacity *= 2;
    delete[] elems;
    elems = copy;
}
