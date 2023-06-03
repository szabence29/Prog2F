//
// Created by Szabó Bence on 2023. 04. 28..
//

#ifndef C___ALAPTIPUS_HPP
#define C___ALAPTIPUS_HPP

template<class T>
class Alaptipus {
    T adat;
public:
    Alaptipus(T adat = 0) : adat(adat) {} /// konstruktor és egyben konverziós operátor
    operator T &() { return adat; } /// cast
    operator T() const { return adat; } /// const cast
    T *operator&() { return &adat; }  /// T*-ra konvertálás
    const T *operator&() const { return &adat; } /// - "" -
    virtual ~Alaptipus() {}
};

#endif //C___ALAPTIPUS_HPP
