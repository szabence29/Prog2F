/**
 *  \file haromszog.h
 *  Haromszog osztály deklarációja
 */
#ifndef HAROMSZOG_H
#define HAROMSZOG_H

#include "alakzat.h"

/// Ügyeljen arra, hogy a csúcspontokat az alaposztály orgiójához relatívan tárolja!

class Haromszog: public Alakzat{
    Pont p1;
    Pont p2;
public:
    Haromszog(const Pont& p0, const Pont& p1, const Pont& p2, Szin sz): Alakzat(p0, sz), p1(p1-p0), p2(p2-p0) {}

    Pont getpont1() const {return p1+getp0();}

    Pont getpont2() const {return  p2+getp0();}

    void rajzol() const;
};

std::ostream& operator<<(std::ostream& os, const Haromszog& t);

#endif // KOR_H

