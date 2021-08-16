#include <iostream>
#include <cstdlib>
using namespace std;

class Array{

	int len;
	int *ptr;

	public:

		Array();
		Array(int size);
		Array(int *arr, int size);
		Array(const Array&);
		~Array();

		void set_len(int size);
		int get_len() const;
		void set_value(int idx, int num);

		int operator[](int i);
		void operator=(const Array);

		Array operator+(const Array);
		Array operator-(const Array);
		void operator++();
		Array& operator--(int);
		bool operator==(const Array);
		bool operator!();

		void operator+=(const Array&);
		void operator-=(const Array&);
		int operator() (int idx, int val);
};

istream& operator>>(istream&, Array&);
ostream& operator<<(ostream&, Array&);

