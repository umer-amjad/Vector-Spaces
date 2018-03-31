//
//  ZmodP.hpp
//  Vector-Spaces-and-Matrices
//
//  Copyright © 2018 Umer. All rights reserved.
//

#ifndef ZmodP_hpp
#define ZmodP_hpp


template<int p>
class Zmod {
    int elem;
public:
    
    //zero initialize:
    Zmod() : elem(0){};
    Zmod(int a) : elem(a % p){};
    
    Zmod& operator++() const{
        ++elem();
        if (elem == p){
            elem = 0;
        }
        return *this;
    }
    
    Zmod operator++(int) const{
        Zmod copy = *this;
        operator++();
        return copy;
    }
    
    Zmod& operator+=(const Zmod& other){
        this->elem += other.elem;
        this->elem %= p;
        return *this;
    }
    
    Zmod operator+() const{
        return *this;
    }
    
    Zmod operator+(const Zmod& other) const{
        Zmod copy = *this;
        copy += other;
        return copy;
    }
    
    Zmod operator-() const{
        return p - elem;
    }
    
    Zmod& operator-=(const Zmod& other){
        this->elem += -other.elem;
        this->elem %= p;
        return *this;
    }
    
    Zmod operator-(const Zmod& other) const{
        Zmod copy = *this;
        copy -= other;
        return copy;
    }
    
    Zmod& operator*=(const Zmod& other){
        this->elem *= other.elem;
        this->elem %= p;
        return *this;
    }
    
    Zmod operator*(const Zmod& other) const{
        Zmod copy = *this;
        copy *= other;
        return copy;
    }

};

#endif /* ZmodP_hpp */
