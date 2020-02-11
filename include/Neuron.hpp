//This is the basic block of the Neural Network
//Definations of all method declerations are implimented in ../src/Neuron.cpp
//I am implimenting it just the way it is represented
//It has a value stored in variable 'val'. 
//We have 'activate()' method to impliment activation function during forward propagation.
//There is also another method 'derive()' to give derivative values of activation function which will help us during backpropagation.
//When a neuron is created with a value, both activated activated and derived values are also created at the same time which will help later. One can modify this functionality in its constructor.
#ifndef _NEURON_HPP_
#define _NEURON_HPP_

#include<bits/stdc++.h>
using namespace std;

class Neuron{
    public:

        Neuron(double val); 
        Neuron(double val, string activation); 
        void setVal(double val);
        void activate();
        void derive();
        double getVal(){return this->val;}
        double getActivatedVal(){return this->activatedVal;}
        double getDerivedVal(){return this->derivedVal;}

    private:
        double val;
        double activatedVal;
        double derivedVal;
        string activation = "sigmoid";
        
};
#endif