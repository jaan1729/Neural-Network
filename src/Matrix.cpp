#include "../include/Matrix.hpp"
 Matrix::Matrix(){
    numRows = 0;
    numCols = 0;
    
 }
Matrix::Matrix(double numRows, double numCols, bool isRandom){
    this->numRows = numRows;
    this->numCols = numCols;
    
    for(int i=0;i<numRows;i++){
        vector<double> colValues;
        for(int j=0;j<numCols;j++){
            double r = isRandom == 0 ? 0:generateRandomNumber();
            colValues.push_back(r);
        }
        values.push_back(colValues);
    }
}

double Matrix::generateRandomNumber(){
    std::random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0,1);
    return dis(gen);
}
void Matrix::printToConsole(){
    cout<<"\n";
    for(int i=0;i<numRows;i++){
        for(int j=0;j<numCols;j++){
            cout<<values[i][j]<<"\t";
        }
        cout<<endl;
    }
}
void Matrix::updateCol(double index, const Matrix& updatedWeights){
    for(double i=0;i<numCols;i++){
        values[index][i] = updatedWeights.getVal(i,0);
        }
}
Matrix Matrix::addBias(){
    if(this->numCols !=1 ){
        cout<<"addBias() is not compatible for this matrix. It can only work with MAtrix of order (numRows,1)";
        assert(false);
    }
    Matrix newMatrix;
    newMatrix.values = this->values;
    newMatrix.values.push_back({1});
    newMatrix.numRows = this->numRows+1;
    newMatrix.numCols = 1;
    return newMatrix;
}
Matrix Matrix::popColumn(){
    Matrix newMatrix(numRows,numCols-1,false);
    newMatrix.values = this->values;
    
    for(int i=0;i<numRows;i++){
        newMatrix.values[i].pop_back();
    }
    return newMatrix;
}

void Matrix::concatHorizontal(const Matrix& matrixA){
    if(this->getNumRows()!=matrixA.getNumRows()){
        cout<<"unsupported dimensions for concating";
        assert(false);
    }
    for(int i=0;i<this->getNumRows();i++){
        this->values[i].push_back(matrixA.getVal(i,0));
    }
    this->numCols+=matrixA.getNumCols();
}
void Matrix::mulWithScalar(double scalar){
    for(int i=0;i<numRows;i++){
        for(int j=0;j<numCols;j++){
            values[i][j] *= scalar;
        }
    }
}
Matrix Matrix::transpose() const{
    Matrix transposeMatrix (this->numCols,this->numRows, false);
    
    for(int i = 0;i<this->numCols;i++){
        for(int j=0;j<this->numRows;j++){
            transposeMatrix.values[i][j] = this->values[j][i];  
        }
    }
    return transposeMatrix;
}