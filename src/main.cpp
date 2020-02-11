#include<iostream>
#include "../include/NeuralNetwork.hpp"

using namespace std;

int main(int argc, char **argv){
    //vector<double> topology = {3,2,3,3,3};
    NeuralNetwork nn(true);
    nn.add(3,"relu");
    nn.add(4,"relu");
    nn.add(3,"sigmoid");
    nn.printToConsole();
    vector<double> input = {1,10,100};
    vector<double> output = {0.9,0.5,0.2};
    nn.fit(input, output);
    nn.train(200);
    Matrix predicted = nn.predict(input);
    predicted.printToConsole();
}