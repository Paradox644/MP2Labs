#include <iostream>
#include "TList.h"
#include "TPolynomial.h"
#include "TMatrix.h"
#include <iostream>
#include<chrono>
int main() {

	TDynamicVector<TMonom> vec(2);
	TDynamicVector<TMonom> vec2(2);
	TMonom a(1, 2, 3, 4), b(2, 6, 7, 8), c(3, 2, 3, 4), d(5,3,1,1),x(7,2,3,4), y(9,6,7,8);
	vec[0] = a;
	vec[1] = b;
	vec2[0] = x;
	vec2[1] = d;
	TPolinom polinom(vec);
	TPolinom polinom2(vec2);
	cout << "Initial values: " << polinom.ToString()<< "\n" << polinom2.ToString();
	polinom.AddPolinom(polinom,polinom2);
	std::cout << "\nresult "<<polinom.ToString();
	//polinom.addmonom(c);
	//cout << "\nfirst monom added: "<<polinom.tostring();
	//polinom.addmonom(d);
	//cout << "\nSecond monom added: "<<polinom.ToString() << endl;
	

}