# Vector-Spaces-and-Matrices
This project written in C++ provides template classes to represent vectors and matrices. 

Existing features include vector addition, scalar multiplication, matrix multiplication, matrix determinants, and matrix transformations of vectors.

### Motivation: ###
- Learn to implement templates in C++
- Extend and apply knowledge of linear algebra 
- Test on and improve ability to abstract commonalities

### How to use: ###

The template classes provided are as a `Vector<typename Field, int dim>` and `Matrix<typename Field, int row, int col>` where:
- *Field* means the mathematical field that the vector space is over (e.g. in main, "double" is the type used to represent the Real numbers)
- *dim* is the dimension of the vector 
- *row* and *col* are the number of rows and columns of the Matrix, respectively. 

The operators *+* and * are overloaded and examples are included in main.cpp. Examples using other Fields (e.g. complex numbers, Z mod p, etc.) are on plan.

### Future: ###

Plan to include:
- Implementing the set of finite fields of prime order, i.e. &#8484; &#8725; &#119901;&#8484; (i.e. the integers modulo p) with p prime, as another templated class
- Reducing row echelon form for matrices
- Using row echeclon form for faster determinant calculations
