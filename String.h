#include <iostream>
#include <string>
using namespace std;

class String{

	int len;
	char *arr;

	public:
		String();
		String(int x);
		String(char *str);
		String(const String &);
		~String();

		char* get_string() const;
		int get_len() const;
		void set_string(char *);
		void set_len(int);

		char operator[](int i);
		String & operator+(String str);
		String & operator-(String substr);
		bool operator !();
		String & operator=(const String&);
		bool operator ==(const String &);
		int operator() (char);
		String operator*(int a);
		int length();

		//friend ostream& operator<<(ostream&,const String&);
		//friend istream& operator>>(istream&,String&);

};

ostream& operator<<(ostream&,const String&);
istream& operator>>(istream&,String&);
