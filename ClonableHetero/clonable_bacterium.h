/**
 * \file: clonable_bacterium.h
 *
 */

#ifndef CLONABLE_BACTERIUM_H
#define CLONABLE_BACTERIUM_H

#include "bacterium.h"
#include "clonable.h"
#include "iostream"

class ClonableBacterium : public Bacterium,Clonable{
public:
    ClonableBacterium(const char *n = "") : Bacterium(n){}

    ClonableBacterium* clone() const {
        return new ClonableBacterium(*this);
    }

    virtual ~ClonableBacterium() {};

};


class ClonableSalmonella : public ClonableBacterium{

    std::string species;     // faj neve
public:
    explicit ClonableSalmonella(const char *sp) :ClonableBacterium("Salmonella"), species(sp) {}

    void show(std::ostream& os) const {
        Bacterium::show(os);
        os << " Fajta: " << species;
    }


    ClonableSalmonella* clone() const {
        return new ClonableSalmonella(*this);
    }

    virtual ~ClonableSalmonella() {};
};

class ClonableStreptococcus : public ClonableBacterium{
    char group;     // csoport neve
public:
    ClonableStreptococcus(char grp) :ClonableBacterium("Streptococcus"), group(grp) {}

    void show(std::ostream& os) const {
        Bacterium::show(os);
        os << " Csoport: " << group;
    }
    ClonableStreptococcus* clone() const {
        return new ClonableStreptococcus(*this);
    }

    virtual ~ClonableStreptococcus() {};
};


#endif // CLONABLE_BACTERIUM_H
