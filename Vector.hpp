//
//  Vector.hpp
//  VectorSpaces
//
//  Copyright © 2018 Umer. All rights reserved.
//

#ifndef Vector_hpp
#define Vector_hpp

#include <array>
#include <ostream>
#include <string>
#include <sstream>
#include <iomanip>

template <class Field, int dim>
class Vector {
    std::array<Field, dim> components;
    
    const Field& operator[](int index) const { 
        return components[index];
    }
    
    Field& operator[](int index) {
        return components[index];
    }
    
public:
    
    //zero initialize:
    Vector(){
        components = std::array<Field, dim>{};
    }
    
    Vector(std::array<Field, dim> components) : components(components) {};
    
    std::array<Field, dim> getComponents() const{
        return components;
    }
    
    //vector additions, subtractions, negatives:
    Vector& operator+=(const Vector& other) {
        for (int i = 0; i < dim; ++i){
            (*this)[i] += other[i];
        }
        return *this;
    };
    
    Vector operator+() const {
        return *this;
    }
    
    Vector operator+(const Vector& other) const {
        Vector copy = *this;
        copy += other;
        return copy;
    };
    
    Vector& operator-=(const Vector& other) {
        for (int i = 0; i < dim; ++i){
            (*this)[i] -= other[i];
        }
        return *this;
    };
    
    Vector operator-() const {
        std::array<Field, dim> negative;
        for (int i = 0; i < dim; ++i){
            negative[i] = -(*this)[i];
        }
        return negative;
    };
    
    Vector operator-(const Vector& other) const {
        Vector copy = *this;
        copy -= other;
        return copy;
    };
    
    //dot product:
    Field operator*(const Vector& other) const {
        Field dotProduct{};
        for (int i = 0; i < dim; ++i){
            dotProduct += (*this)[i] * other[i];
        }
        return dotProduct;
    };
    
    //scalar product:
    friend Vector<Field, dim> operator*(const Field& scalar, const Vector<Field, dim>& v){
        std::array<Field, dim> scaled;
        for (int i = 0; i < dim; ++i){
            scaled[i] = scalar * v[i];
        }
        return Vector<Field, dim>(scaled);
    };
    
    friend std::ostream& operator<<(std::ostream& out, const Vector<Field, dim>& v){
        std::array<std::string, dim> elems;
        int maxLength = 0;
        for (int i = 0; i < dim; ++i){
            std::stringstream ss;
            ss << v[i];
            elems[i] = ss.str();
            if (elems[i].length() > maxLength){
                maxLength =(int) elems[i].length();
            }
        }
        for (std::string& component : elems){
            out << std::setw(1) << '|';
            out << std::setw(maxLength) << component;
            out << std::setw(1) << "|\n";
        }
        return out;
    };
};

#endif /* Vector_hpp */
