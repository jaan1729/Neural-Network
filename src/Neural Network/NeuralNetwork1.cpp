#include "../../include/NeuralNetwork.hpp"
using namespace std;

NeuralNetwork::NeuralNetwork(bool randomInit) {
    this->randomInit = randomInit;
}
void NeuralNetwork::add(int layerSize, string activation = "sigmoid"){
    Layer l(layerSize, activation);
    layers.push_back(l);
    int layerNo = layers.size();
    if (layerNo>1){
        Matrix m(layers[layerNo-1].getLayerSize(), layers[layerNo-2].getLayerSize()+1, randomInit);
        weightMatrices.push_back(m);
    }
    topologySize++;
    topology.push_back(layerSize);
}
void NeuralNetwork::fit(vector<double> input, vector<double> output){
    this->layers[0].setLayerVal(input);
    this->input = util::vectorToMatrix(input);
    this->output = util::vectorToMatrix(output);
}

void NeuralNetwork::printToConsole(){
    cout<<endl<<"weights";
    for(int i=0; i<topologySize-1;i++){
        this->weightMatrices[i].printToConsole();
        
    }
    cout<<endl;
    
    cout<<endl<<"Layers"<<endl;
    for(int i=0;i<topologySize;i++){
        if(i==0||i==topologySize-1) layers[i].getLayerVal().printToConsole();
        else layers[i].getActivatedLayerVal().printToConsole();
        cout<<endl;
    }
}
