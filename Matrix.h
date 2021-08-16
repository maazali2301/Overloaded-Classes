#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;

class Matrix{
	
	int row, col;
	float **ptr; 
	
	public:
		Matrix();
		Matrix(int, int);  //initialization with zero
		Matrix(int, int, int); //for random initialization, i pass an extra, unused argument
		Matrix(const Matrix &);
		~Matrix();
		
		float get_value(int, int);
		void set_value(int, int, float);
		int get_row();
		int get_col();
		void set_row(int);
		void set_col(int);
		void set_dim(int, int); //setting dimensions
		void allocate(); //for new allocation after setting rows and columns
		
		
		void operator() (int, int, float);
		Matrix& operator=(const Matrix &);
		bool operator==(const Matrix &);
		Matrix operator+(const Matrix &);
		Matrix operator-(const Matrix &); 
		Matrix operator*(const Matrix &);
		Matrix& operator++(int);
		void operator+=(const Matrix&);
		void operator-=(const Matrix&);
		
		operator string();
};

istream& operator>>(istream&,Matrix&);
ostream& operator<<(ostream&,Matrix&);

