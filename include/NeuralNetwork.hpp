#ifndef _NEURAL_NETWORK_
#define _NEURAL_NETWORK_
#include<iostream>
#include "Neuron.hpp"
#include "Layer.hpp"
#include "Matrix.hpp"
#include "util.hpp"

using namespace std;

class NeuralNetwork{
    public:
        NeuralNetwork(bool randomInit);
        void add(int layerSize , string activation);
        //The neural network is created with the structure according to topology.
        //For example, topology vector {3,2,3} creates a neural network with 3 neurons at input layer, 2 neurons at hidden layer and 3 neurons at output lahyer.
        //This constructor also creates weight matrices. As the weight matrices should not be initialized with zero values,
        //we can use randomInit flag to initiate with random integers
        void fit(vector<double> input, vector<double> output);
        void forwardPropogation();
        void backPropogation();
        double getErrors();
        void printToConsole();
        void train(double epochs);
        Matrix predict(vector<double> sample);
    private:
        vector<double> topology;
        
        double topologySize=0;
        vector<Layer> layers;
        vector<Matrix> weightMatrices;
        Matrix errors;
        Matrix gradients;
        Matrix deltas;
        Matrix input;
        Matrix output; 
        double MSW;
        double learningRate=0.1;
        bool randomInit;

};

#endif