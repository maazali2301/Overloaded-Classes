#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;
class Polynomial{

	int h_pow;
	int *coeff;
	//size of coeff array will always be one greater than the highest power value
	//highest power: 4   hence.....4x^4 + 2x^3 + 5x^2 + 0x^1 + 5x^0

	public:

		Polynomial();
		Polynomial(int);
		Polynomial(int, char); //random assignment operator, hence passing an extra parameter
		Polynomial(const Polynomial &);
		Polynomial& operator=(const Polynomial &);//assigns (copies) a Polynomial. Returns

		int get_pow() const;
		int get_coeff(int) const;
		void set_val(int, int);
		void set_pow(int);


		bool operator==(const Polynomial &);//Compare and return true if equal
 		Polynomial operator+(const Polynomial &);//adds two Polynomial
		Polynomial operator-(const Polynomial &);//subtracts two Polynomial
		Polynomial operator*(const Polynomial &);//multiplies two Polynomial
		void operator+=(const Polynomial&);//adds two polynomials
		void operator-=(const Polynomial&);
		~Polynomial();

		operator string();

		friend istream& operator>>(istream&,Polynomial &);
		friend ostream& operator<<(ostream&,const Polynomial &);

};



