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
    Zmod(int a) : elem((a + p) % p){};
    
    Zmod& operator++(){
        ++elem;
        if (elem == p){
            elem = 0;
        }
        return *this;
    }
    
    Zmod operator++(int){
        Zmod copy = *this;
        operator++();
        return copy;
    }
    
    Zmod& operator--(){
        if (elem == 0){
            elem = p - 1;
        } else {
            --elem;
        }
        return *this;
    }
    
    Zmod operator--(int){
        Zmod copy = *this;
        operator--();
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
        *this += -other;
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
    
    Zmod inverse(){
        //Using the Extended Euclidean Algorithm
        int r = p;
        int r_next = elem;
        int t = 0;
        int t_next = 1;
        while (r_next != 0){
            int quotient = r / r_next;
            r = r_next;
            t = t_next;
            int t_next = t - quotient * t_next;
            int r_next = r - quotient * r_next;
        }
        return 0;
    }
    
    friend std::ostream& operator<<(std::ostream& out, const Zmod& val){
        out << val.elem;
        return out;
    }

};

#endif /* ZmodP_hpp */
