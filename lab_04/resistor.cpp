/**
 * \file resistor.cpp
 *   (UTF-8 kodolasu fajl. Allitsa at a megjenetes kodolasat,
 *    ha a tovabbi kommentek nem olvashatok helyesen!)
 *
 * Ohmikus ellenállást modellező osztály megvalósítása
 */

/**
 * Itt kell megvalósítani a resistor.h-ban deklarált nem inline függvényeket.
 * A Jportára ezt a fájlt kell feltölteni.
 */

#include "resistor.h"

double Resistor::defR = 21;

void Resistor::setDef(double r) {
    defR = r;
}

Resistor::Resistor() {
    this->R = defR;
    Pr("ctr0");
}

Resistor::Resistor(double r) {
    this->R = r;
    Pr("ctr1");
}

Resistor Resistor::operator+(const Resistor &r) const {
    return Resistor(this->R+r.getR());
}

Resistor Resistor::operator%(const Resistor &r) const {
    return Resistor(1/((1/this->R)+(1/r.getR())));
}

Resistor operator*(int i, const Resistor& r){
    if(i <= 0){
        throw "LV08C9";
    }
    return Resistor(i*r.getR());
}


Resistor::Resistor(const Resistor &rhs) :R (rhs.R) {
    Pr("Copy");
}


Resistor::~Resistor() {
    Pr("dtor");
}

Resistor& Resistor::operator=(const Resistor& rhs){
    Pr("assign");
    this->R = rhs.getR();
    return (*this);
}

double Resistor::getI(double u) const{
    return u/R;
}

double Resistor::getU(double i) const{
    return i*R;
}
