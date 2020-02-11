//Matrix is a data structure with which most of the operations are implemented easily.
//It has 2-D vector of values of shape numRows*numCols
//The calculations which are done on Matrix itself are also implemented in this data structure.
//I have used another abstract class util.hpp to perform operation on two matrixes and result another matrix
//By modifying only Matrix.hpp and util.hpp, most of the NeuralNetwork code can be parellalized for implimenting this on GPUs.
//All these operations are used during forward propagation or backward propagation implementations in NeuralNetwork.hpp, ../src/Neural Network/ NeuralNetwork1 and ../src/Neural Network/ NeuralNetwork2
#ifndef _MATRIX_HPP_
#define _MATRIX_HPP_

#include<iostream>
#include<vector>
#include<random>
#include<cassert>
using namespace std;

class Matrix{
    public:
        Matrix();
        //A default matrix constructor.
        Matrix(double numRows, double numCols, bool isRandom);
        //'isRandom' argument is used to specify whether to initiate the values to random numbers or to zero. 
        Matrix transpose() const;
        void setVal(double r, double c, double val){values[r][c] = val;}
        //'setVal' helps to set a user defined value in matrix at row 'r' and column 'c'
        Matrix addBias();
        //This method concatinates one at the end of the matrix. It works only with matrixes whih 'numCols' = 1.
        Matrix popColumn();
        //Removes last column of the matrix
        void concatHorizontal(const Matrix& matrixA);
        void mulWithScalar(double scalar);
        double generateRandomNumber();
        double getVal (double r, double c) const {double value = values[r][c]; return value;}
        double getNumRows () const {return this->numRows;}
        double getNumCols () const {return this->numCols;}
        void updateCol(double index, const Matrix& updatedWeights);
        void printToConsole();
    
        vector<vector<double>> values;
    private:
        double numRows;
        double numCols;
        bool isRandom;
};
#endif