#include "../include/Neuron.hpp"

//Constructor
Neuron::Neuron(double val, string activation){
    //Neuron initiation when activation function is defined
    this->val = val;
    this->activation = activation;
    activate();
    derive();
}
Neuron::Neuron(double val){
    this->val = val;
    activate();
    derive();
}
void Neuron::setVal(double val){
    this->val = val;
    activate();
    derive();
}
void Neuron::activate(){
        //Default function is sigmoid
       
    if (activation == "relu"){
        activatedVal = 0>val? 0:val;
    }
    else if (activation == "tanh"){
        activatedVal = tanh(val);
    }
    else { 
         //To perform well in limited resources, I am just implementing a Fast Sigmoid Function.
        //f(x) = x / (1+|x|)
        activatedVal = val/(1+abs(val));}
}
void Neuron::derive(){
    //f'(x) = f(x)*(1-f(x))
    if (activation == "relu"){
        derivedVal = 0>val? 0:1;
    }
    else if (activation == "tanh"){
        derivedVal = 1-(activatedVal*activatedVal);
    }
    else { 
        derivedVal = activatedVal*(1-activatedVal);}
}