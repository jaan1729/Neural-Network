//Few matrix calculations, matrix to vector conversions and vecor to matrix conversions are implemented
//As all the members are static, they can be used without any object
//These methods are helpful during forward propagation and backward propagation
#ifndef _UTIL_HPP_
#define _UTIL_HPP_
#include<iostream>
#include "Matrix.hpp"

class util{
    public:
        static Matrix matrixMul(const Matrix &matrixA,const Matrix &matrixB);
        static Matrix matrixElementMul(const Matrix &matrixA,const Matrix &matrixB);
        static vector<double> matrixToVector(const Matrix& matrixA);
        static Matrix vectorToMatrix(const vector<double> &vectorA);
        static Matrix matrixSub(const Matrix& matrixA, const Matrix& matrixB);
};
#endif