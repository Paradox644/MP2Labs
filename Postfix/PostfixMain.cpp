// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
// Тестирование матриц

#include<iostream>
#include<map>
#include<string>
#include "Postfix.h"
void main() {
    std::string express = "(a+b*c)*(d/e-f)";
    ArithmeticExpression ar(express);
    std::string post = ar.TranslateToPostfix();
    ar.setPost(post);
    std::cout <<"Initial expression: "<<express<<"\nPostfix form: "<<post << "\n";
    double arr[] = { 1.0,2.0,3.0,1.0,2.0,2.0};
    std::cout << "Variable values in order: ";
    for (double i : arr) std::cout << i << " ";
    std::cout <<"\nExpression calculated: "<< ar.CalculatePostfix(arr);
}

