#include <iostream>
#include "TList.h"
#include "TPolynomial.h"
#include "TMatrix.h"
#include <iostream>
#include<chrono>
int main() {

	TDynamicVector<TMonom> vec(2);
	TMonom a(1, 2, 3, 4), b(2, 6, 7, 8), c(3, 2, 3, 4), d(5, 1, 2, 1);
	vec[0] = a;
	vec[1] = b;
	TPolinom polinom(vec);

	cout << "Initial value: " << polinom.ToString();
	polinom.AddMonom(c);
	cout << "\nFirst monom added: "<<polinom.ToString();
	polinom.AddMonom(d);
	cout << "\nSecond monom added: "<<polinom.ToString() << endl;
	

}