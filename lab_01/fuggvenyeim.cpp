// Fájl: fuggvenyeim.cpp
// Ebben valósítom meg a gyakran használt függvényeket.

#include <cmath>
#include <limits>
#include <iostream>
#include "fuggvenyeim.h"

// Két int adat felcserélése
void csere(int& a, int& b) {
   int tmp = a;
   a =  b;
   b = tmp;
}

/// Segédfüggvény double pontosságú számok összehasonlításához
/// Nem bombabiztos, de nekünk most jó lesz
/// Elméleti hátér:
/// http://www.cygnus-software.com/papers/comparingfloats/comparingfloats.htm
bool almostEQ(double a, double  b) {
    // eps: ha a relatív, vagy abszolút hiba ettől kisebb, akkor elfogadjuk
    double eps = 50 * std::numeric_limits<double>::epsilon(); // 50-szer a legkisebb absz. (!=0) érték: ~1e-14
    if (a == b) return true;
    if (fabs(a - b) < eps)
       return true;
    double aa = fabs(a);
    double ba = fabs(b);
    if (aa < ba) {
        aa = ba;
        ba = fabs(a);
    }
    return (aa - ba) < aa * eps;
}

double polinom(double ertek, double* tomb, int fokszam){
    double eredmeny = tomb[fokszam];
    for (int i = fokszam-1; i >= 0; i--) {
        eredmeny=eredmeny*ertek+tomb[i];
    }
    return eredmeny;
}