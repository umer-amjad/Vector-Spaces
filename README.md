# Vector-Spaces-and-Matrices
Class templates to represent linear algebra over a field, written in C++. 

The classes provide vector addition, scalar multiplication, matrix multiplication, matrix determinants, and matrix transformations of vectors. Additionally, a class template for &#8484; &#8725; &#119901;&#8484;, the finite field of integers modulo a prime *p*, has been implemented and used as an example of a Field for which the Matrix and Vector classes will work. 

### Motivation: ###
- Learning to implement templates in C++
- Testing and improving ability to generalize abstract ideas correctly
- Applying and extending knowledge of linear algebra 

### How to use: ###

The code can be compiled using C++14 without the need for any external libraries or frameworks. 

The class templates provided are as a `Vector<typename Field, int dim>` and `Matrix<typename Field, int row, int col>` where:
- `Field` is the mathematical field that the vector space is over (e.g. in `main`, `double` is used to represent the Real numbers, `Zmod<13>` is used to represent &#8484;<sub>13</sub>, and so on)
- `dim` is the dimension of the vector 
- `row` and `col` are the number of rows and columns of the Matrix, respectively. 

Note that the field must satisfy all the properties of a Mathematical field, i.e. it should have addition, subtraction, multiplication, and division defined. Thus, in the C++ code representing the field, along with the arithmetic operations, the assignment operators such as `+=`, `-=`, `/=`, and `*=` should also be defined. Finally, the default constructor for the Field class should return the *zero* element of the field (akin to zero initialization for non-class types like `int` and `double`). Increment and decrement operations should add and subtract the *one* element of the field respectively. Finally, for outputting purposes, the operator `<<` should be overloaded appropriately. 

To show an example of matrices over finite fields, the class template `Zmod<int p>` is provided. This represents the field of integers modulo *p*, &#8484; &#8725; &#119901;&#8484;, with *p* prime. 

There are two determinant calculations available: the ordinary one calculates the determinant according to the recursive definition (i.e. Laplace's formula), while `fastDet` calculates the determinant by first putting the matrix into row echelon form, and then finding the determinant. Laplace's formula is O(n!) - extremely undesirable - which is why the row echelon form method is provided: it is O(n<sup>3</sup>), a vast improvement over the first method. 

Examples for how these classes and their methods are to be used can be found in the `main.cpp` file. 
