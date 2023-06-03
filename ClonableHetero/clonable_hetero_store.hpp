/**
 * \file: clonable_hetero_store.hpp
 *
 */

#ifndef CLONABLE_HETERO_STORE_HPP
#define CLONABLE_HETERO_STORE_HPP

#include "iostream"

template <class Base, class Container = std::vector<Base *>, class Exception = std::out_of_range>
class ClonableHeteroStore{

    Container container;

public:

    typedef Base value_type;

    typedef typename Container::const_iterator const_iterator;
    typedef typename Container::iterator iterator;

    ClonableHeteroStore() : container(Container()){}

    void copy(ClonableHeteroStore const& rhs){
        container.clear();

        for (const_iterator existingchs = rhs.container.begin() ; existingchs != rhs.container.end(); existingchs++) {

            this->container.push_back((*existingchs)->clone());
        }
    }

    ClonableHeteroStore(ClonableHeteroStore const& rhs) : container(rhs.container){
        copy(rhs);
    }

    ClonableHeteroStore& operator=(ClonableHeteroStore const& rhs){
        if(this == &rhs){
            return *this;
        }
        this->container = rhs.container;

        copy(rhs);
        return *this;

    }

    const_iterator begin() {
        return container.begin();
    }

    const_iterator end() {
        return container.end();
    }

    void add(Base * data){
        try{
            container.push_back(data);
        }catch (...){
            delete data;
            throw Exception("nemjo");
        }

    }

    void clear() {
        container.clear();
    }

    size_t size() const {
        return container.size();
    }

    ~ClonableHeteroStore(){
        for (iterator it = container.begin(); it != container.end(); it++){
            delete *it;
        }
    }

};


#endif // CLONABLE_HETERO_STORE_HPP
