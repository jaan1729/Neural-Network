#include "../include/Layer.hpp"
using namespace std;
Layer::Layer(int size){
    this->size = size;
    //For a layer with a given number size, this creates vector of Neurons with zero values.
    for(int i=0; i<size; i++){
        Neuron n(0);
        neurons.push_back(n);
    }
}
Layer::Layer(int size, string activation){
    this->size = size;
    //For a layer with a given number size, this creates vector of Neurons with zero values.
    for(int i=0; i<size; i++){
        Neuron n(0, activation);
        neurons.push_back(n);
    }
}
void Layer::setLayerVal(const vector<double>& values){
    for(int i=0; i<this->size; i++){
        this->neurons[i].setVal(values[i]);
    }
}
Matrix Layer::getLayerVal(){
    vector<double> val;
    for(int i=0;i<this->size;i++){
        val.push_back(this->neurons[i].getVal());
    }
    Matrix m =  util::vectorToMatrix(val);
    return m;
}
Matrix Layer::getActivatedLayerVal(){
    vector<double> val;
    for(int i=0;i<this->size;i++){
        val.push_back(this->neurons[i].getActivatedVal());
    }
    Matrix m =  util::vectorToMatrix(val);
    return m;
}


void Layer::printToConsole(bool activated){
    for(int i=0;i<this->size;i++){
        if(activated == false) cout<<neurons[i].getVal()<<endl;
        else cout<<neurons[i].getActivatedVal()<<endl;
    }
}
Matrix Layer::getDerivedLayerVal(){
    vector<double> val;
    for(int i=0;i<this->size;i++){
        val.push_back(this->neurons[i].getDerivedVal());
    }
    Matrix m =  util::vectorToMatrix(val);
    return m;
}