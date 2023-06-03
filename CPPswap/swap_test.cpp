/**
 * \file swap.h
 * (Latin-2 kodolasu fajl. Allitsa at a kodolast,
 *  ha a tovabbi kommentek nem olvashatok helyesen!)
 *
 * Feladat:
 * Val�s�tsa meg a swap.h f�jlban deklar�lt f�ggv�nyeket a swap.cpp f�jlban �gy,
 * hogy ez a program hiba n�lk�l leforduljon, �s helyesen m�k�dj�n!
 *
 * A program bemutatja a gtest_lite makr�inak haszn�lat�t.
 * A makr�k m�k�d�st nem kell meg�rtenie, mivel sz�mos m�g nem tanult megold�st
 * tartalmaznak.
 *
 */

#include <iostream>
#include "gtest_lite.h"
#include "swap.h"

int main() {

    GTINIT(std::cin);       // Csak C(J)PORTA m�k�d�s�hez kell

    TEST(Swap, int) {       // Teszt eset kezdete. A param�terekb�l csak ki�r�s lesz
        int a = 1, b = 100;
        int a0 = a, b0 = b;
        swap(a, b);
        EXPECT_EQ(b0, a);   // a k�t param�ter azonoss�g�t v�rjuk
        EXPECT_EQ(a0, b);   // a k�t param�ter azonoss�g�t v�rjuk
    } END

    TEST(Swap, char) {      // Teszt eset kezdete.
        char a = 'A', b = 'Z';
        char a0 = a, b0 = b;
        swap(a, b);
        EXPECT_EQ(b0, a);   // k�t param�ter azonoss�g�t v�rjuk
        EXPECT_EQ(a0, b);
    } END

    TEST(Swap, bool) {      // Teszt eset kezdete.
        bool a = true, b = false;
        bool a0 = a, b0 = b;
        swap(a, b);
        EXPECT_EQ(b0, a);   // k�t param�ter azonoss�g�t v�rjuk
        EXPECT_EQ(a0, b);
    } END

    TEST(Swap, double) {    // Teszt eset kezdete
        double a = 123.56, b = 8.954;
        double a0 = a, b0 = b;
        swap(a, b);
        EXPECT_EQ(b0, a);   // a swap nem sz�m�tott eredm�ny, ez�rt lehet EQ
        EXPECT_EQ(a0, b);   // egy�bk�nt EXPECT_DOUBLE_EQ kellene
    } END

    TEST(Swap, char*) {     // Teszt eset kezdete
        const char *a = "Hello", *b = "C++";
        const char *a0 = a, *b0 = b;
        swap(a, b);
        EXPECT_EQ(b0, a); // k�t param�ter azonoss�g�t v�rja
        EXPECT_EQ(a0, b);
    } END

    GTEND(std::cerr);   // Csak C(J)PORTA m�k�d�s�hez kell

    return 0;
}
