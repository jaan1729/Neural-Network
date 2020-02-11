#include "../../include/NeuralNetwork.hpp"

using namespace std;

void NeuralNetwork::forwardPropogation(){
    for(int i=1;i<topologySize;i++){
        Layer presentLayer = this->layers[i];
        Matrix updatedLayerValues = i==1?util::matrixMul(weightMatrices[i-1], this->layers[i-1].getLayerVal().addBias()): util::matrixMul(weightMatrices[i-1], this->layers[i-1].getActivatedLayerVal().addBias()); 
        this->layers[i].setLayerVal(util::matrixToVector(updatedLayerValues));
    }
}
void NeuralNetwork::train(double epochs){
    for(int i=0;i<epochs;i++){
        forwardPropogation();
        getErrors();
        backPropogation();
        cout<<"MSW at "<<i<<" iteration is:"<<MSW<<endl;
    }
}
Matrix NeuralNetwork::predict(vector<double> sample){
    layers[0].setLayerVal(sample);
    for(int i=1;i<topologySize;i++){
        Layer presentLayer = this->layers[i];
        Matrix updatedLayerValues = i==1?util::matrixMul(weightMatrices[i-1], this->layers[i-1].getLayerVal().addBias()): util::matrixMul(weightMatrices[i-1], this->layers[i-1].getActivatedLayerVal().addBias()); 
        this->layers[i].setLayerVal(util::matrixToVector(updatedLayerValues));
    }
    return layers[topologySize-1].getActivatedLayerVal();
}
double NeuralNetwork::getErrors(){
    double MSW=0;
    for(int i=0;i<this->topology[topologySize-1];i++){
        double error= (layers[topologySize-1].getActivatedLayerVal().getVal(i,0)-output.getVal(i,0));
        MSW+=error*error;
    }
    this->MSW = MSW;
    return MSW;

}
void NeuralNetwork::backPropogation(){
    Matrix dzi = util::matrixSub(layers[topologySize-1].getActivatedLayerVal(),output);
    Matrix dyi_1;
    Matrix dwi;
    Matrix dbi;
    for(int i=topologySize-1;i>0;i--){
        if(i!=topologySize-1) dzi = util::matrixElementMul(dyi_1,layers[i].getDerivedLayerVal());
        if(i==1) dwi = util::matrixMul(dzi,layers[i-1].getLayerVal().transpose());
        else dwi = util::matrixMul(dzi,layers[i-1].getActivatedLayerVal().transpose());
        Matrix dbi = dzi;
        Matrix weights = weightMatrices[i-1].popColumn();
        dyi_1 = util::matrixMul(weights.transpose(),dzi);
        dwi.concatHorizontal(dbi);
        dwi.mulWithScalar(learningRate);
        Matrix updatedWeights = util::matrixSub(weightMatrices[i-1],dwi);
        this->weightMatrices[i-1] = updatedWeights;
    }
}