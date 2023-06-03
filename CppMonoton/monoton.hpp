#ifndef C___MONOTON_HPP
#define C___MONOTON_HPP

template<typename ITERATOR, typename PREDIKATUM>
bool monoton(ITERATOR begin, ITERATOR end, PREDIKATUM pred){
    if (begin == end) {
        return true;
    }
    ITERATOR i = begin++;
    while (begin!=end){
        if(!pred(*begin, *i)){
            return false;
        }
        i = begin++;
    }
    return true;
}


#endif //C___MONOTON_HPP