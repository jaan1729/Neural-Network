//Layer is implemented using vector of Neurons
//Values of layers are returned in Matrix data structure which is implemented in Matrix.hpp
//Matrix data structure is helpful to perform matrix operations over the values.
//All the matrix related methods are implemented in matrix.hpp or util.hpp
//The decla=erations are implemented in ../src/Layer.cpp
#ifndef __LAYER_HPP_
#define _LAYER_HPP_

#include<iostream>
#include "Neuron.hpp"
#include<vector>
#include "Matrix.hpp"
#include "util.hpp"

using namespace std;
class Layer{
    public:
        Layer(int size, string activation);
        Layer(int size);
        void printToConsole(bool activated);
        //This method prints all the Neuron values of the layer. This is helpful for analyzing the network performance.
        //With boolean argument 'activated' we can specify to print wheather activated or normal values
        void setLayerVal(const vector<double>& values);
        //By passing values vector to setLayerVal, it is easy to set all neuron values of the neurons.
        //It helps to set given input values to first layer and setting other layer values after multiplying previous layer values with weight matrix during forward propagation.
        Matrix getLayerVal();
        //It returns Matrix of layer values. This is used to get input layer values to calculate values of second layer. 
        double getLayerSize(){return this->size;}
        Matrix getActivatedLayerVal();
        //It returns Matrix of activated Neuron values of the layer. It helps during forward propagation  
        Matrix getDerivedLayerVal();
        //It helps during backward propagation.
    private:
        double size;
        vector<Neuron> neurons;
        string activation;
};
#endif