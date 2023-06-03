#ifndef C___PSTRING_H
#define C___PSTRING_H

#include <iostream>
#include "string5.h"
#include "serializable.h"

class PString : public String, public Serializable
{
public:
    // ctr / cctr / dtr
    PString();
    PString(const String& str);
    ~PString();
    // write/read
    void write(std::ostream& ostr) const;
    void read(std::istream& istr);
};

#endif //C___PSTRING_H
