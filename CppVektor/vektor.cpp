#include "iostream"
#include "vektor.h"

size_t Vektor::defSize = 11;

double Vektor::defValue = 21;

/// Másoló konstruktor. Készítse el a vektor.cpp fájlban!
Vektor::Vektor(const Vektor& v) :nElements(v.size()){
    pVec = new double[nElements];
    for (size_t i = 0; i < nElements; i++)
        pVec[i] = v.pVec[i];
}

/// Destruktor. Készítse el a vektor.cpp fájlban!
Vektor::~Vektor(){
    delete[] pVec;
}

/// Értékadó operátor. Készítse el a vektor.cpp fájlban!
Vektor& Vektor::operator=(const Vektor& rhs){
    if (this != &rhs)
    {
        delete[] (*this). pVec;
        (*this).nElements = rhs.nElements;
        (*this).pVec = new double[(*this).nElements];
        for (size_t i = 0; i < nElements; i++)
            pVec[i] = rhs.pVec[i];
    }
    return (*this);
}

/// Indexoperátorok. Készítse el a vektor.cpp fájlban!
/// Túlcímzés esetén az Ön Neptun-kódját tartalmazó const char* típusú kivételt dob!
/// @param idx - index értéke
/// @return    - referencia az adott elemre
double& Vektor::operator[](size_t idx){
    if (idx >= (*this).nElements){
        throw "LV08C9";
    }
    return (*this).pVec[idx];
}
const double& Vektor::operator[](size_t idx) const{
    if (idx >= (*this).nElements)
        throw "LV08C9";
    return (*this).pVec[idx];
}

/// Szorzás: Valós * Vektor. Készítse el a vektor.cpp fájlban!
/// @param val - valós érték (bal oldali operandus)
/// @param vec - vektor, aminek minden elemét megszorozzuk (jobb oldali operandus)
Vektor operator*(double val, const Vektor& vec){
    Vektor v = vec;
    for (size_t i = 0; i < vec.size(); i++)
        v[i] = vec[i] * val;
    return v;

}