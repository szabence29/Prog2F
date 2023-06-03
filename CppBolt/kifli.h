//
// Created by Szabó Bence on 2023. 04. 24..
//

#ifndef C___KIFLI_H
#define C___KIFLI_H

#include "aru.h"

class Kifli: public Aru {
    String spec;
public:
    Kifli(double ar, const char *spec = ""): Aru("Kifli", "db", ar), spec(spec) {}

    std::ostream& print(std::ostream& os) const {
        return os << megnevezes << " "
                  << spec << "; "
                  << ar << "Ft/" << egyseg;
    }
};

#endif //C___KIFLI_H
