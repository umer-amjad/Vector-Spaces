//
//  main.cpp
//  VectorSpaces
//
//  Copyright © 2018 Umer. All rights reserved.
//

#include <iostream>
#include "Vector.hpp"
#include "Matrix.hpp"
#include "ZmodP.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <exception>

int testModInverse(){
    int success = 0;
    if (Zmod<13>(5).inverse() != Zmod<13>(8)){
        throw std::runtime_error("Failed test " + std::to_string(success));
    }
    ++success;
    if (Zmod<13>(2).inverse() != Zmod<13>(7)){
        throw std::runtime_error("Failed test " + std::to_string(success));
    }
    ++success;
    if (Zmod<13>(4).inverse() != Zmod<13>(10)){
        throw std::runtime_error("Failed test " + std::to_string(success));
    }
    ++success;
    Zmod<3697> unit(1);
    for (int i = 0; i < 100; ++i){
        int z = rand();
        if (z == 0){
            continue;
        }
        Zmod<3697> elem(z);
        Zmod<3697> inverse = elem.inverse();
        if (elem * inverse != unit){
            throw std::runtime_error("Failed test: inverse of " + std::to_string(z));
        }
        //std::cout << "Inverse of " << elem << " is " << inverse << " in Z mod 3697\n";
        ++success;
    }
    return success;
}

int main(int argc, const char * argv[]) {
    srand(time(0));
    try {
        testModInverse();
    } catch (const std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    std::cout << "3 / 8 mod 13 = " << Zmod<13>(3) / 8 << std::endl;
    std::cout << "3 / 5 mod 13 = " << Zmod<13>(3) / 5 << std::endl;
    std::cout << "4 / 8 mod 13 = " << Zmod<13>(4) / 8 << std::endl;
    //std::cout << "4 / 8 mod 13 = " << Zmod<13>(4) / 0 << std::endl; //error
    typedef Vector<double, 3> R3;
    Matrix<double, 3, 3> M({
        1, 2, -4.3,
        11.2, 1, -3.5,
        -1, -13, 1
    });
    std::cout << "M: \n" << M << std::endl;
    std::cout << "-2M: \n" << -2*M << std::endl;
    std::cout << "det(M) is : " << M.fastDet() << std::endl;

    std::cout << "determinant(M) is: " << M.determinant() << std::endl;  //561.88
    std::cout << "trace(M) is: " << M.trace() << std::endl;
    std::cout << "(product of diagonal entries) multiplicativeTrace(M) is: " << M.multiplicativeTrace() << std::endl;
    
    Matrix<double, 3, 3> M2({
        1, 2, -4.3,
        11.2, 22.4, -3.5,
        -1, -13, 1
    });
    std::cout << "M2: \n" << M2 << std::endl;
    std::cout << "-2*M2: \n" << -2*M2 << std::endl;
    std::cout << "det(M2) is : " << M2.fastDet() << std::endl;
    
    std::cout << "determinant(M2) is: " << M2.determinant() << std::endl;  //491.26
    std::cout << "trace(M2) is: " << M2.trace() << std::endl;
    std::cout << "(product of diagonal entries) multiplicativeTrace(M2) is: " << M2.multiplicativeTrace() << std::endl;
    
    Matrix<double, 4, 4> BigM({
        1, 2, -4.3, -2.9,
        11.2, 1, -3.5, 0.3,
        -1, -13, 1, -0.1,
        2.5, 1.5, -0.4, 0.7
    });
    
    std::cout << "BigM: \n" << BigM << std::endl;
    std::cout << "-2BigM: \n" << -2*BigM << std::endl;
    std::cout << "det(BigM) is : " << BigM.fastDet() << std::endl;
    
    std::cout << "determinant(BigM) is: " << BigM.determinant() << std::endl;  //160.793
    
    Matrix<double, 4, 4> BigM2({
        0, 2, -4.3, -2.9,
        11.2, 1, -3.5, 0.3,
        -1, -13, 1, -0.1,
        2.5, 1.5, -0.4, 0.7
    });
    
    std::cout << "BigM2: \n" << BigM2 << std::endl;
    std::cout << "-2BigM2: \n" << -2*BigM2 << std::endl;
    std::cout << "det(BigM2) is : " << BigM2.fastDet() << std::endl;
    
    std::cout << "determinant(BigM2) is: " << BigM2.determinant() << std::endl;  //190.349
    
    Matrix<double, 4, 4> BigM3({
        0, 2, -4.3, -2.9,
        11.2, 0, -3.5, 0.3,
        -1, -13, 0, -0.1,
        2.5, 1.5, -0.4, 0
    });
    
    std::cout << "BigM3: \n" << BigM3 << std::endl;
    std::cout << "-2BigM3: \n" << -2*BigM3 << std::endl;
    std::cout << "det(BigM3) is : " << BigM3.fastDet() << std::endl;
    
    std::cout << "determinant(BigM3) is: " << BigM3.determinant() << std::endl;  //-194.064
    
    
    Matrix<double, 4, 4> BigM4({
        1, 2, 2, 1,
        0, 2, 0, 0,
        -1, -4, -2, -1,
        1, 4, 4, 1
    });
    
    std::cout << "BigM4: \n" << BigM4 << std::endl;
    std::cout << "-2BigM4: \n" << -2*BigM4 << std::endl;
    std::cout << "det(BigM4) is : " << BigM4.fastDet() << std::endl;
    
    std::cout << "determinant(BigM4) is: " << BigM4.determinant() << std::endl;  //0
    
    Matrix<double, 4, 4> BigM5({
        1, 2, 2, 1,
        0, 2, 2, 0,
        -1, -4, -4, -1,
        1, 4, 4, 1
    });
    
    std::cout << "BigM5: \n" << BigM5 << std::endl;
    std::cout << "-2BigM5: \n" << -2*BigM5 << std::endl;
    std::cout << "det(BigM5) is : " << BigM5.fastDet() << std::endl;
    
    std::cout << "determinant(BigM5) is: " << BigM5.determinant() << std::endl;  //0
    

    Matrix<Zmod<13>, 2, 2> modExample({
        3, 7,
        -2, 4
    });
    std::cout << "modExample: \n" << modExample << std::endl;
    std::cout << "determinant(modExample) is: " << modExample.determinant() << std::endl;
    std::cout << "det(modExample) is : " << modExample.fastDet() << std::endl;
    std::cout << "trace(modExample) is: " << modExample.trace() << std::endl;
    std::cout << "multiplicativeTrace(modExample) is: " << modExample.multiplicativeTrace() << std::endl;
    
    Matrix<Zmod<13>, 2, 2> modExample2({
        3, 7,
        -2, 5
    });
    std::cout << "modExample2: \n" << modExample2 << std::endl;
    std::cout << "det(modExample2) is : " << modExample2.fastDet() << std::endl;
    std::cout << "determinant(modExample2) is: " << modExample2.determinant() << std::endl;
    std::cout << "trace(modExample2) is: " << modExample2.trace() << std::endl;
    std::cout << "multiplicativeTrace(modExample2) is: " << modExample2.multiplicativeTrace() << std::endl;
    
    Matrix<Zmod<7>, 2, 2> modExample3({
        3, 7,
        -2, 9
    });
    std::cout << "modExample3: \n" << modExample3 << std::endl;
    std::cout << "det(modExample3) is : " << modExample3.fastDet() << std::endl;
    std::cout << "determinant(modExample3) is: " << modExample3.determinant() << std::endl;
    std::cout << "trace(modExample3) is: " << modExample3.trace() << std::endl;
    std::cout << "multiplicativeTrace(modExample3) is: " << modExample3.multiplicativeTrace() << std::endl;

    
    Matrix<double, 2, 3> A1({
        3, 7, 0,
        0.5, 4, 2
    });
    //std::cout << "determinant(A1) is: " << determinant(A1) << std::endl; //error
    
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
    std::cout << "A1: \n" << A1 << "\nA2:\n"<< A2 << "\nA3:\n"<< A3 << "\nA1 * A2:\n" << (A1*A2);
    std::cout << "\nA1 * M:\n" << (A1*M) << "\nA1 * A3:\n" << (A1 * A3);
    //std::cout << "\nA1 + A2:\n" << (A1+A2); error
    std::cout << "\nA1 transpose:\n" << A1.transpose();
    std::cout << "\nA1 transpose + A3:\n" << (A1.transpose() + A3) << '\n';
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
    std::cout << "dotProd v1*v2: \n" << dotProduct << std::endl;
    std::cout << "M(v2): \n" << v6 << std::endl;
    std::cout << "zero vector: \n" << zeroVec << std::endl;
    std::cout << "v7 = 2*v2: \n" << v7 << std::endl;
    std::cout << "v2: \n" << v2 << std::endl;
    v7 = v3;
    v7 = 0.5*v3;
    std::cout << "v7 = 0.5*v3: \n" << v7 << std::endl;
    std::cout << "v3: \n" << v3 << std::endl;
    std::cout << "Zero matrix (2 x 4): \n" << zeroMatrix << std::endl;
}

