#include "Matrix.h"


int main(int argc, char **argv) {

	cout<<"--------------------------------\n";
	cout<<"   Question 3 - Matrix Class"<<endl;
	cout<<"--------------------------------\n";
	Matrix m1(3,3,0);
	Matrix m2;
	m2 = m1;
	
	cout<<"Sample Matrices: ";
	cout<<m1;
	cout<<m2;
	
	cout<<"\n\n> Equality Check: "<<(m1==m2)<<endl;
	
	cout<<"\n\n> Sum of Matrices (m1 + m2): \n";
	Matrix m3 = m1 + m2;
	cout<<m3;
	
	cout<<"\n\n> Subtraction of Matrices (m1 - m2): \n";
	Matrix m4 = m1 - m2;
	cout<<m4;
	
	cout<<"\n\n> Multiplication of Matrices [element-wise] (m1 * m2): \n";
	Matrix m5 = m1 * m2;
	cout<<m5;
	
	cout<<"\n\n> Matrix 1 Incremented:\n";
	m1++;
	cout<<m1;	
	
	cout<<"\n\n> Matrix 2 Added to Matrix 1:\n";
	m1+=m2;
	cout<<m1;	
	
	Matrix m18(2,2);
	cout<<"MATRIX STRING TYPE CAST\n\n";
	cout<<string(m18);
	

	return 0;
}
