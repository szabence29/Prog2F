//
// Created by Szabó Bence on 2023. 04. 12..
//

#ifndef C___EMBER_H
#define C___EMBER_H

#include "cstring"

class Ember{
    protected:
        int szulEv;
        char* nev;
    public:
        Ember() : szulEv(2003) {
            szulEv = 2003;
            nev = new char[7];
            strcpy(nev, "LV08C9");
        }

        Ember(const char* n, int ev);

        Ember(const Ember& e);

        virtual Ember& operator=(const Ember& e);

        virtual const char* getNev() const;

        virtual int getKor(int ev) const;

        virtual const char* foglalkozas() const;

        virtual ~Ember();

};

#endif //C___EMBER_H
