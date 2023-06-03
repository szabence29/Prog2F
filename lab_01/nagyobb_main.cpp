// Fájl: nagyobb_main.cpp
// Egyszerű demo program.
// Bekér két egész számot és kiírja a nagyobbat.

#include <iostream>
#include <iomanip>
#include "fuggvenyeim.h"
using namespace std;

int main() {
    double an[] = { 3, 2, 1 }; // együtthatók: a0=3, a1=2, a3=1
    double res[] = { 3, 6, 11, 18, 27, 38, 51 };
    int hibak = 0;
    for (int i = 0; i < 7; i++) {
        const double Z = 3.141e2;
        double x = i / Z - 1;
        x++;
        x = x * Z;
        double fx = polinom(x, an, 2);
        if (res[i] != fx) {    // Helyes ez így?
            cout << "Hibas: " << setprecision(20) << res[i] << "!=" << fx << endl;
            hibak++;
        }
    }
    if (hibak == 0)
        cout << "Nem volt elteres" << endl;

    cout << "12. feladat" << endl;

    int hiba = 0;
    for (int i = 0; i < 7; ++i) {
        double x2 = i;
        if(!almostEQ(res[i], polinom(x2, an, 2))){
            cout << "Hibas: " << setprecision(20) << res[i] << endl;
            hiba++;
        }
    }
    if (hiba == 0){
        cout << "Nem volt elteres" << endl;
    }
}