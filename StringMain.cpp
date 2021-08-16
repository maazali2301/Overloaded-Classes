#include "String.h"


int main(int argc, char **argv) {

	cout<<"--------------------------------\n";
	cout<<"   Question 1 - String Class"<<endl;
	cout<<"--------------------------------\n";
	
	String s1("FAST NUCES");
	String s2("Islamabad");
	
	cout<<"\nSample Strings....\n";
	cout<<s1<<s2;
	
	cout<<"\n > Position of ''N' in String s1:"<<s1('N')<<endl;
	cout<<"\n > Equality Check: "<<(s1==s2)<<endl<<endl;
	cout<<" > Lengths (s1,s2): "<<s1.length()<<" , "<<s2.length()<<endl;
	
	String s3=s1+s2;
	cout<<"\n\n > Appended String (s3): \n";
	cout<<s3;
	
	cout<<"\n\n > Removing Substring: \n";
	String a("ababacc");
	String b("aba");
	cout<<a<<" - "<<b;
	b=a-b;
	cout<<"\n Final Output....."<<b;
	
	cout<<"\n\n > String S2 Multiplied 5 Times: \n";
	cout<<s2*5;
	
	return 0;	
} 
