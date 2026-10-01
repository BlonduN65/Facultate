#include <iostream>
#include <math.h>
#include <algorithm>
#include <format>

double radical(double x){
    return std::sqrt(x);
}
double sinus_(double x){
    return std:: sin(x);
}
double exponential(double x){
    return std:: exp(x);
}
int main(){
    using FuncPtr = double(*)(double);
    FuncPtr functii[] = { radical, sinus_, exponential };
    std::cout << std::format("{:>8} | {:>12} | {:>12} | {:>12}\n","x", "sqrt(x)", "sin(x)", "exp(x)");

    for(int i=1;i<=10;i++){
        double x=1+i*0.5;

        double val_sqrt = functii[0](x);
        double val_sin  = functii[1](x);
        double val_exp  = functii[2](x);

        std::cout << std::format("{:>8.1f} | {:>12.4f} | {:>12.4f} | {:>12.4f}\n", x, val_sqrt, val_sin, val_exp);


    }
    return 0;

}