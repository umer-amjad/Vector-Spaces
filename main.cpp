//
//  main.cpp
//  VectorSpaces
//
//  Copyright © 2018 Umer. All rights reserved.
//

#include <iostream>
#include "Vector.hpp"
#include "Matrix.hpp"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    typedef Vector<double, 3> R3;
    Matrix<double, 3, 3> M({
        1, 2, -4.3,
        11.2, 1, -3.5,
        -1, -13, 1
    });
    //std::cout << "det(M) is: " << det(M) << std::endl; //561.88
    std::cout << "2. det(M) is: " << M.det() << std::endl;

    Matrix<double, 2, 3> A1({
       3, 7, 0,
       0.5, 4, 2
    });
    //std::cout << "det(A1) is: " << det(A1) << std::endl; //error
    Matrix<double, 3, 1> A2({
        2,
        5,
        0.5
    });
    Matrix<double, 3, 2> A3({
        2, 7,
        5, -5,
        0.5, -3
    });
    std::cout << A1 << '\n'<< A2 << '\n' << (A1*A2) << '\n' << (A1*M) << '\n' << (A1 * A3) << '\n';
    std::cout << "M:\n" << M << std::endl;
    R3 v1({1,0,1.2});
    std::cout << "A1(v1): \n"<< (A1*v1) << '\n';
    R3 v2({0.5, 7, 12});
    R3 v3 = v1 + v2;
    R3 negv1 = -v1;
    R3 v4 = 7.5*v1 - 2*v2;
    R3 v5 = -2.5 * v3;
    R3 v6 = M*v2;
    R3 v7(v2);
    v7 = 2*v7;
    R3 zeroVec{};
    Matrix<double, 2, 4> zeroMatrix{};
    double dotProduct = v1 * v2;
    std::cout << "v1: \n" << v1 << std::endl;
    std::cout << "v2: \n" << v2 << std::endl;
    std::cout << "v3 = v1 + v2: \n" << v3 << std::endl;
    std::cout << "negv1: \n" << negv1 << std::endl;
    std::cout << "v4 = 7.5*v1 - 2*v2: \n" << v4 << std::endl;
    std::cout << "v5 = -2.5 * v3: \n" << v5 << std::endl;
    std::cout << "dotProd v1*v2 : \n" << dotProduct << std::endl;
    std::cout << "M(v2) : \n" << v6 << std::endl;
    std::cout << "zero vector : \n" << zeroVec << std::endl;
    std::cout << "v7 = 2*v2 : \n" << v7 << std::endl;
    std::cout << "v2: \n" << v2 << std::endl;
    v7 = v3;
    v7 = 0.5*v3;
    std::cout << "v7 = 0.5*v3 : \n" << v7 << std::endl;
    std::cout << "v3: \n" << v3 << std::endl;
    std::cout << "Zero matrix (2 x 4): \n" << zeroMatrix << std::endl;
}

