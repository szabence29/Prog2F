//
// Created by Szabó Bence on 2023. 04. 13..
//

#ifndef C___BICIKLI_H
#define C___BICIKLI_H

#include "stdio.h"
#include "iostream"

class Jarmu {
    double vMax;
public:
    Jarmu(double v) :vMax(v) {std::cout <<"\tJarmu ctor vMax=" <<vMax << std::endl;}

    virtual ~Jarmu() {std::cout << "\tJarmu dtor vMax=" <<vMax<<std::endl;}

    Jarmu(const Jarmu &j) :vMax(j.vMax) { std::cout << "\tJarmu copy vMax=" << j.vMax << std::endl;}
};

class Szan : public Jarmu {
    int kutyakSzama;
public:
    Szan(double v = 0, int n = 0) :Jarmu(v), kutyakSzama(n) {std::cout << "\tSzan ctor kutyakSzama=" <<kutyakSzama<<std::endl;}

    ~Szan() {std::cout << "\tSzan dtor kutyakSzama =" <<kutyakSzama<<std::endl;}

    Szan(const Szan &v): Jarmu(v), kutyakSzama(v.kutyakSzama) { std::cout << "\tSzan copy kutyakSzama=" << v.kutyakSzama << std::endl;}
};

class Kerek {
    int atmero;
public:
    Kerek(int d) :atmero(d) { std::cout << "\tKerek ctor\n"; }

    Kerek(const Kerek& k) :atmero(k.atmero) { std::cout << "\tKerek copy\n"; }

    void kiir()         { std::cout << "atmero=" << atmero << std::endl; }

    virtual ~Kerek()            { std::cout << "\tKerek dtor\n"; }
};

class Bicikli : public Jarmu{
    Kerek elso;
    Kerek hatso;
public:
    Bicikli(double v = 0, int d = 0) : Jarmu(v), elso(d), hatso(d) {std::cout << "\tBicikli ctor "; elso.kiir();}

    Bicikli(const Bicikli &b) : Jarmu(b), elso(b.elso), hatso(b.hatso) {std::cout << "\tBicikli copy "; elso.kiir();}

    ~Bicikli() {std::cout << "\tBicikli dtor "; elso.kiir();}
};

#endif //C___BICIKLI_H
