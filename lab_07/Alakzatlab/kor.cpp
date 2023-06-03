/**
 *  \file kor.cpp
 *  Kor oszt�ly tagf�ggv�nyeinek megval�s�t�sa
 */
#include "kor.h"

/// K�rt rajzol� rajzol fv.
void Kor::rajzol() const {
    std::cout << "Rajzol: " << *this << std::endl;
}

/// Glob�lis << oper�tor a Kor adatainak ki�r�s�hoz
std::ostream& operator<<(std::ostream& os, const Kor& k) {
    return os << "Kor " << (Alakzat&)k << ",r=" << k.getr();
}
