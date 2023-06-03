#include "pstring.h"

PString::PString() : String() {}

PString::PString(const String& str) : String(str) {}

PString::~PString() {}

void PString::write(std::ostream& ostr) const {
    ostr << size() << c_str();
}

void PString::read(std::istream& istr) {
    size_t sizebuf = 0;
    istr >> sizebuf >> std::noskipws;
    char* charbuf = new char[sizebuf+1];
    for (size_t i = 0; i < sizebuf; i++)
        istr  >> charbuf[i];
    istr >> std::skipws;
    charbuf[sizebuf] = 0;
    *this = String(charbuf);
    delete[] charbuf;
}