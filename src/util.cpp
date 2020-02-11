#include "../include/util.hpp"
#include <cassert>
Matrix util::matrixMul(const Matrix& matrixA,const Matrix& matrixB){
    double aRows = matrixA.getNumRows();
    double aCols = matrixA.getNumCols();
    double bRows = matrixB.getNumRows();
    double bCols = matrixB.getNumCols();
    
    if(aCols!=bRows) assert(false);
    Matrix result (aRows,bCols,false);
    for(int i=0;i<aRows;i++){
        for(int j=0;j<bCols;j++){
            for(int k=0;k<aCols;k++){
                result.setVal(i,j, matrixA.getVal(i,k)*matrixB.getVal(k,j)+result.getVal(i,j));
            }
        }
    }
    return result;
}
Matrix util::matrixElementMul(const Matrix& matrixA,const Matrix& matrixB){
    double aRows = matrixA.getNumRows();
    double aCols = matrixA.getNumCols();
    double bRows = matrixB.getNumRows();
    double bCols = matrixB.getNumCols();
    
    if(aCols!=bCols || aRows!=bRows) assert(false);
    Matrix result (aRows,bCols,false);
    for(int i=0;i<aRows;i++){
        for(int j=0;j<aCols;j++){
            
            result.setVal(i,j, matrixA.getVal(i,j)*matrixB.getVal(i,j));
            
        }
    }
    return result;
}
vector<double> util::matrixToVector(const Matrix &matrixA){
    vector<double> result;
    if(matrixA.getNumCols()!=1) assert(false);
    for(int i=0;i<matrixA.getNumRows();i++){
            result.push_back(matrixA.getVal(i,0));
        }
    
    return result;
}
Matrix util::vectorToMatrix(const vector<double> &vectorA){
    double rows = vectorA.size();
    Matrix m(rows,1,false);
    for(int i=0;i<vectorA.size();i++){
        m.setVal(i,0,vectorA[i]);
    }
    return m;
}
Matrix util::matrixSub(const Matrix& matrixA, const Matrix& matrixB){
    double rowsA = matrixA.getNumRows();
    double rowsB = matrixB.getNumRows();
    double colsA = matrixA.getNumCols();
    double colsB = matrixB.getNumCols();
    Matrix result(rowsA,colsA,false);
    if(rowsA!=rowsB || colsA!=colsB){
        cout<<"Wrong matrix subtraction dimensions";
        assert(false);
    }
    for(int i=0;i<rowsA;i++){
        for(int j=0;j<colsB;j++){
            double sub = matrixA.getVal(i,j)-matrixB.getVal(i,j);
            result.setVal(i,j,sub);
        }
    }
    return result;
}
