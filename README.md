# Vector-Spaces-and-Matrices
Template classes to represent vectors and matrices written in C++. 

Currently offers vector addition, scalar multiplication, matrix multiplication, matrix determinants, and matrix transformations of vectors.

### Motivation: ###
- Learning to implement templates in C++
- Test and improve ability to abstract commonalities correctly
- Apply and extend knowledge of linear algebra 

### How to use: ###

The templated classes provided are as a `Vector<typename Field, int dim>` and `Matrix<typename Field, int row, int col>` where:
- Field is the mathematical field that the vector space is over (e.g. in main, "double" is the type used here to represent the Real numbers)
- dim is the dimension of the vector 
- row and col are the number of rows and columns of the Matrix, respectively. 

The operators + and * are overloaded appropriately and examples are included in main.cpp. Examples using other Fields (e.g. complex numbers, Z mod p, etc.) are planned.

### Future: ###

Plans include:
- Implementing the set of finite fields of prime order, i.e. &#8484; &#8725; &#119901;&#8484; (i.e. the integers modulo p) with p prime, as another templated class
- Reduced row echelon form for matrices 
- Using row echeclon form for faster determinant calculations





