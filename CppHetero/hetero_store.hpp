/**
 * \file: hetero_store.hpp
 *
 */

#ifndef HETEROSTORE_HPP
#define HETEROSTORE_HPP

#include <iostream>
#include <stdexcept>

template<class T, size_t meret=100, class kivetel = std::out_of_range>

class HeteroStore{
    size_t db;
    T* tomb[meret];
public:
    HeteroStore(): db(0) {}
    ~HeteroStore() {clear();}
    size_t size() const {return db;}
    size_t capacity() const {return meret;}
    void add(T* p)
    {
        if (db == meret)
        {
            delete p;
            throw kivetel("Nincs hely");
        }
        tomb[db++] = p;
    }

    template<typename Z>
    void traverse(Z func) { for (size_t i = 0; i < db; i++) func(tomb[i]); }
    void clear() { for (size_t i = 0; i < db; i ++) delete tomb[i]; db = 0; }
};

#endif // HETEROSTORE_HPP
