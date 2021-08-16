#include "Array.h"


int main(int argc, char **argv) {

	cout<<"--------------------------------\n";
	cout<<"   Question 2 - Array Class"<<endl;
	cout<<"--------------------------------\n";
	
	int arr1[5] = {10,11,12,13,14};
	int arr2[5] = {20,21,22,23,24};
	
	Array a1(arr1,5);
	Array a2(arr2,5);
	
	cout<<"\nUsing Sample Arrays: "<<endl;
	cout<<a1<<a2;
	
	cout<<"\n> Equality Check: "<<(a1==a2)<<endl;
	cout<<"\n> Empty Check for Array 1: "<<(!a1)<<endl;
	cout<<"> Empty Check for Array 2: "<<(!a2)<<endl;
	cout<<"\n> Array 1 value at Index 3: "<<a1[3];
	cout<<"\n> Array 2 value at Index 3: "<<a2[3]<<endl;	
	
	cout<<"\n> Addition (a1 + a2): \n";
	Array a3 = a1 + a2;
	cout<<"Array 3: ";
	cout<<a3;
	
	cout<<"\n\n> Subtraction: (a3 - a1)\n";
	Array a4 = a3 - a1;
	cout<<"Array 4: ";
	cout<<a4;
	
	
	cout<<"\n\n> Array 1 Incremented: \n";
	++a1;
	cout<<a1;
	
	cout<<"\n\n> Array 2 Incremented: \n";
	a2--;
	cout<<a2;
	
	cout<<"\n\n> Array 1 Elements Added to Array 2 Elements: \n";
	a2 += a1;
	cout<<a2;
	
	cout<<"\n\n> Removing 0th Index of Array 1: ";
	a1(0,11);
	cout<<a1;


	return 0;
} 
