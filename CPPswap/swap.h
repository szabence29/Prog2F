#ifndef _SWAP_H
#define _SWAP_H
/**
 * \file swap.h
 * (Latin-2 kodolasu fajl. Allitsa at a kodolast,
 *  ha a tovabbi kommentek nem olvashatok helyesen!)
 *
 * Feladat:
 * Val�s�tsa meg az al�bb deklar�lt f�ggv�nyeket a swap.cpp f�jlban �gy,
 * hogy a swap_teszt.cpp program hiba n�lk�l leforduljon, �s helyesen m�k�dj�n!
 *
 */

/**
 * A swap megval�s�t�s�hoz aligha kell din. mem�riakezel�s.
 * Ez�rt ellen�rizni sem lenne sz�ks�ges.
 */
#include "memtrace.h"

/**
 * swap
 * K�t bool adat felcser�l�se
 * @param a - egyik adat
 * @param b - m�sik adat
 */
void swap(bool& a, bool& b);

/**
 * swap
 * K�t int adat felcser�l�se
 * @param a - egyik adat
 * @param b - m�sik adat
 */
void swap(int& a, int& b);

/**
 * swap
 * K�t char adat felcser�l�se
 * @param a - egyik adat
 * @param b - m�sik adat
 */
void swap(char& a, char& b);

/**
 * swap
 * K�t double adat felcser�l�se
 * @param a - egyik adat
 * @param b - m�sik adat
 */
void swap(double& a, double& b);

/**
 * swap
 * K�t const char* adat (pointer) felcser�l�se
 * @param a - egyik pointer
 * @param b - m�sik pointer
 */
void swap(const char*& a, const char*& b);  /// Figyelje meg a ref. t�pus jel�l�s�t!

#endif  // _SWAP_H
