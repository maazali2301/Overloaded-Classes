#include "Polynomial.h"

int main(int argc, char **argv) {

	cout<<"--------------------------------\n";
	cout<<" Question 4 - Polynomial Class\n";
	cout<<"--------------------------------\n";

	cout<<"\n";

	Polynomial p1(3,'a');
	Polynomial p2 = p1;

	cout<<"Sample Polynomials: \n";
	cout<<p1;
	cout<<endl;
	cout<<p2;


	cout<<"\n\n> Equality Check: "<<(p1==p2)<<endl;

	cout<<"\n\n> Sum of Polynomials: ";

	Polynomial sum = (p1+p2);

	cout<<sum;


	cout<<"\n\n> Subtraction of Polynomials:\n";

	Polynomial sub = (p2-p1);

	cout<<sub;

	cout<<"\n\n> Mulitplication of Polynomials:\n";

	Polynomial mul = (p1*p2);

	cout<<mul;

	cout<<"\n\nPolynomial P1 added to Product: \n";
	mul += p1;

	cout<<mul;

	cout<<endl<<endl;
	
	return 0;
}
