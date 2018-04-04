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
    
    bool operator==(const Zmod& other) const{
        return elem == other.elem;
    }
    
    bool operator!=(const Zmod& other) const{
        return !(operator==(other));
    }
    
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
    
    Zmod inverse() const{
        //Using the Extended Euclidean Algorithm
        if (elem == 0){
            throw std::invalid_argument("Error: Division by zero");
        }
        int r = p;
        int r_next = elem;
        int t = 0;
        int t_next = 1;
        while (r_next != 0){
            int quotient = r / r_next;
            int old_r_next = r_next;
            int old_t_next = t_next;
            t_next = t - quotient * t_next;
            r_next = r - quotient * r_next;
            r = old_r_next;
            t = old_t_next;
        }
        return Zmod(t);
    }
    
    Zmod& operator/=(const Zmod& other){
        (*this) *= other.inverse();
        return *this;
    }
    
    Zmod operator/(const Zmod& other) const{
        Zmod copy = *this;
        copy /= other;
        return copy;
    }
    
    friend std::ostream& operator<<(std::ostream& out, const Zmod& val){
        out << val.elem;
        return out;
    }

};

#endif /* ZmodP_hpp */
