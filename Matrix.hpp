//
//  Matrix.hpp
//  VectorSpaces
//
//  Copyright © 2018 Umer. All rights reserved.
//

#ifndef Matrix_hpp
#define Matrix_hpp

#include <array>
#include "Vector.hpp"

struct MatrixIndex {
    int rowIndex;
    int colIndex;
} typedef MatrixIndex;

template<typename Field, int row, int col>
class Matrix {
    template<typename Field2, int row2, int col2>
    friend class Matrix; //all matrices over the same Field are friends of each other
    //can't partially specialize, so all matrices friends of each other
    
    std::array<Field, row * col> entries;
    
    const Field& operator[](MatrixIndex i) const {
        return entries[col*i.rowIndex+i.colIndex];
    };
    
    //length of each row is "col"
    const Vector<Field, col> getRow(int r) const {
        std::array<Field, col> rowR;
        for (int i = 0; i < col; i++){
            rowR[i] = (*this)[{r,i}];
        }
        return Vector<Field, col>(rowR);
    };
    
    //length of each col is "row"
    const Vector<Field, row> getCol(int c) const {
        std::array<Field, row> colC;
        for (int i = 0; i < row; i++){
            colC[i] = (*this)[{i,c}];
        }
        return Vector<Field, row>(colC);
    };
    
    Matrix<Field, row, col-1> removeCol(int i) const {
        std::array<Field, row*(col-1)> colRemoved;
        for (int r = 0; r < row; r++){
            for (int c = 0; c < (col - 1); c++){
                if (c < i) {
                    colRemoved[r*(col-1) + c] = (*this)[{r, c}];
                } else {
                    colRemoved[r*(col-1) + c] =(*this)[{r, c+1}];
                }
            }
        }
        return Matrix<Field, row, col-1>(colRemoved);
    }
    
public:
    
    //zero-initialize
    Matrix() {
        entries = std::array<Field, row*col>{};
    }
    
    Matrix(std::array<Field, row*col> entries) : entries(entries){};
    
    //matrix additions, subtractions, negatives:
    Matrix& operator+=(const Matrix& other) {
        for (int i = 0; i < row * col; i++){
            this->entries[i] += other.entries[i];
        }
        return *this;
    };
    
    Matrix operator+() const {
        return *this;
    }
    
    Matrix operator+(const Matrix& other) const {
        Matrix copy = *this;
        copy += other;
        return copy;
    };
    
    Matrix& operator-=(const Matrix& other) {
        for (int i = 0; i < row * col; i++){
            this->entries[i] -= other.entries[i];
        }
        return (*this);
    };
    
    Matrix operator-() const {
        std::array<Field, row * col> negative;
        for (int i = 0; i < row * col; i++){
            negative[i] = -this->entries[i];
        }
        return negative;
    };
    
    Matrix operator-(const Matrix& other) const {
        Matrix copy = *this;
        copy -= other;
        return copy;
    };
    
    //scalar product:
    friend Matrix<Field, row, col> operator*(const Field& scalar, const Matrix<Field, row, col>& m){
        std::array<Field, row * col> scaled;
        for (int i = 0; i < row * col ; i++){
            scaled[i] = scalar * m.entries[i];
        }
        return Matrix<Field, row, col>(scaled);
    };
    
    template<int p> //m x n matrix multiplied by n x p matrix, over field F
    Matrix<Field, row, p> operator*(const Matrix<Field, col, p>& m) const{
        std::array<Field, row*p> product;
        for (int r = 0; r < row; r++ ){
            for (int c = 0; c < p; c++){
//                std::cout <<"Multiplying: \n" << m1.getRow(r) << "\nwith \n" << m2.getCol(c) << std::endl;
                product[p*r+c] = (*this).getRow(r) * m.getCol(c); // dot product
            }
        }
        return Matrix<Field, row, p>(product);
    };
    
    //Apply matrix as linear transformation
    Vector<Field, row> operator*(const Vector<Field, col>& vector) const {
        Matrix<Field, col, 1> columnVector = Matrix<Field, col, 1>(vector.getComponents());
        Matrix<Field, row, 1> product = (*this) * columnVector;
        return Vector<Field, row>(product.entries);
    };
    
    
    Field det(){
        static_assert((row == col), "Determinant can only be taken for square matrices");
        constexpr int n = row;
        std::array<Field, (n-1)*n> removedFirstRow;
        for (int r = 0; r < (n-1); r++){
            for (int c = 0; c < n; c++){
                removedFirstRow[r*n + c] = (*this)[{r+1, c}];
            }
        }
        Field determinant{};
        Matrix<Field, n-1, n> subM(removedFirstRow);
        for (int c = 0; c < n; c++){
            Field cofactor = (*this)[{0, c}] * (subM.removeCol(c)).det();
            //std::cout << "Cofactor " << c << " is: " << cofactor << std::endl;
            if (c % 2 == 0)
                determinant = determinant + cofactor;
            else
                determinant = determinant - cofactor;
        }
        return determinant;
    };

    friend std::ostream& operator<<(std::ostream& out, const Matrix<Field, row, col>& m){
        std::array<std::array<std::string, col>, row> elems;
        std::array<int, col>  maxLengths{0};
        for (int r = 0; r < row; r++){
            for (int c = 0; c < col; c++){
                std::stringstream ss;
                ss << m[{r, c}];
                elems[r][c] = ss.str();
                if (elems[r][c].length() > maxLengths[c]){
                    maxLengths[c] =(int) elems[r][c].length();
                }
            }
        }
        for (std::array<std::string, col> thisRow : elems){
            out << std::setw(1) << '|';
            for (int c = 0; c < col; c++){
                if (c != 0){
                    out << " ";
                }
                out << std::setw(maxLengths[c]) << thisRow[c];
            }
            out << std::setw(1) << "|\n";
        }
        return out;
    };
};

//partially specialize class for 0 x 0 trivial matrices
template<typename Field>
class Matrix<Field, 0, 0>{
public:
    Matrix(std::array<Field, 0> entries){};
    Field det(){
        Field zero{};
        return ++zero; //return one
    };
};

#endif /* Matrix_hpp */
