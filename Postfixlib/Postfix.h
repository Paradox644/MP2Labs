#include<iostream>
#include<map>
#include<string>
#include "TStack.h"
class ArithmeticExpression {
    protected: 
        std::string expression;
        std::string postfixForm;
        const std::map<char,int> operatorPriority{{'(',1},{')',1},{'+',2},{'-',2},{'*',3},{'/',3}};
        const std::map<char,int> alphabet {{'a',0},{'b',1},{'c',2},{'d',3},{'e',4},{'f',5},{'g',6},{'h',7},{'i',8},{'j',9},{'k',10},{'l',11},{'m',12},{'n',13},{'o',14},{'p',15},{'q',16},{'r',17},{'s',18},{'t',19},{'u',20},{'v',21},{'w',22},{'x',23},{'y',24},{'z',25}};
        bool  CheckPriority(TStack<char> &stack,char &ch) {
            if (operatorPriority.at(ch)>=operatorPriority.at(stack.TopView()))
                return true;
            return false;
        }


    public:
        ArithmeticExpression(const std::string &expr){
            expression = expr;
        }
        void setPost(std::string &pos){
            postfixForm = pos;
        }
        void OverrideExpression(){
            std::cout<<"Please enter your arithmetic expression\n";
            std::string expr;
            std::cin>>expr;
            expression = expr;
        }
        std::string TranslateToPostfix(){
            std::string resultingString;
            TStack<char> charStack(expression.length());
            for (char c:expression) {
                if (operatorPriority.count(c)==0){
                    resultingString.push_back(c);
                }
                else if (charStack.IsEmpty()) {
                    charStack.Push(c);
                }
                else if (c=='('){
                    charStack.Push(c);
                }
                else if (c == ')'){
                    while (charStack.TopView()!='(') {
                        resultingString.push_back(charStack.Get());
                    }
                    charStack.Get();
                }
                else {
                    while(!CheckPriority(charStack,c)){
                        resultingString.push_back(charStack.Get());
                    }
                    charStack.Push(c);
                }
            }
            while(!charStack.IsEmpty()){
                resultingString.push_back(charStack.Get());
            }
            postfixForm = resultingString;
            return resultingString;
        }
        double CalculatePostfix(double a[] ){
            TStack<double> resultStack(postfixForm.length()); 
            for (char c:postfixForm) {
                if (operatorPriority.count(c)==0){
                    resultStack.Push(a[alphabet.at(c)]);
                }
                else {
                   double rightOperand = resultStack.Get();
                   double leftOperand = resultStack.Get();
                   switch (c) {
                       case '+':
                           resultStack.Push(leftOperand+rightOperand);
                           break;
                       case '-':
                           resultStack.Push(leftOperand-rightOperand);
                           break;
                       case '/':
                           resultStack.Push(leftOperand/rightOperand);
                           break;
                       case '*':
                           resultStack.Push(leftOperand*rightOperand);
                           break;
                   }
                }
            }
            return resultStack.Get();
        }
};
