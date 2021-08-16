#include "Polynomial.h"

istream& operator>>(istream& input,Polynomial &poly)
{
	int p;
	if (poly.get_pow()==0)
	{
		cout<<"Enter Highest Power: ";
		input>>p;
		poly.set_pow(p);
	}
	
	int num;
	
	//input in opposite sequence
	for (int i=poly.get_pow(); i>=0; i--)
	{
		cout<<"Enter Co-Efficient of x^"<<i<<" : ";
		input>>num;
		
		poly.set_val(i, num);
	}
	
	return input;
}

Polynomial::operator string()
{
	string s="";

	int checkzero=1;
	for (int i=0; i<=get_pow(); i++)
	{
		if (get_coeff(i)!=0)
		{
			checkzero = 0;
			break;
		}
	}

	if (checkzero==1)
	{
		s=s+"0";
		return s; 
	}

	for (int i=get_pow(); i>0; i--)
	{
		/* if (i!=get_pow() && get_coeff(i+1)==0)
		{
			s+=" + ";
		} */

		if (i!=get_pow() && get_coeff(i+1)==0 && get_coeff(i)>0 && (i+1 != get_pow()))
		{
			s+=" + ";
		}
		
		if (get_coeff(i)==0)
		continue; 
		
		if (get_coeff(i)==1)
		{
			if (i>1)
			s=s+"x^"+to_string(i);
			else
			s+="x";
		}
		
		if (get_coeff(i)>1)
		{
			if (i>1)
			s=s+to_string(get_coeff(i))+"x^"+to_string(i);
			else
			s=s+to_string(get_coeff(i))+"x";
		}
		
		if (get_coeff(i)<0)
		{
			s+=" - ";
			if (i>1)
			s=s+to_string(-1*get_coeff(i))+"x^"+to_string(i);
			else
			s=s+to_string(-1*get_coeff(i))+"x";
		}
		
		if (get_coeff(i-1)>0)
		{
			s+=" + ";
		}
		
	}
	
	if (get_coeff(0) == 0)
	{
		return s;
	}
	else if (get_coeff(0)>0)
	{
		s=s+ to_string(get_coeff(0));
	}
	
	else if (get_coeff(0)<0)
	{
		s= s+ " - "+to_string(-1*get_coeff(0));
	}
	
	return s;


}

ostream& operator<<(ostream& ouput,const Polynomial &poly)
{
	//cout<<"Pow: "<<poly.get_pow()<<endl;
	cout<<"Polynomial: ";

	//check if all are zeros
	int checkzero=1;
	for (int i=0; i<=poly.get_pow(); i++)
	{
		if (poly.get_coeff(i)!=0)
		{
			checkzero = 0;
			break;
		}
	}

	if (checkzero==1)
	{
		cout<<"0";
		return ouput; 
	}
	
	for (int i=poly.get_pow(); i>0; i--)
	{
		if (i!=poly.get_pow() && poly.get_coeff(i+1)==0 && poly.get_coeff(i)>0 && (i+1 != poly.get_pow()))
		{
			cout<<" + ";
		}
		
		if (poly.get_coeff(i)==0)
		continue; 
		
		if (poly.get_coeff(i)==1)
		{
			if (i>1)
			ouput<<"x^"<<i;
			else
			ouput<<"x";
		}
		
		if (poly.get_coeff(i)>1)
		{
			if (i>1)
			ouput<<poly.get_coeff(i)<<"x^"<<i;
			else
			ouput<<poly.get_coeff(i)<<"x";
		}
		
		if (poly.get_coeff(i)<0)
		{
			ouput<<" - ";
			if (i>1)
			ouput<<-1*poly.get_coeff(i)<<"x^"<<i;
			else
			ouput<<-1*poly.get_coeff(i)<<"x";
		}
		
		if (poly.get_coeff(i-1)>0)
		{
			cout<<" + ";
		}
		
	}
	
	if (poly.get_coeff(0) == 0)
	{
		return ouput;
	}
	else if (poly.get_coeff(0)>0)
	{
		cout<<poly.get_coeff(0);
	}
	
	else if (poly.get_coeff(0)<0)
	{
		cout<<" - "<<1*poly.get_coeff(0);
	}
	
	return ouput;
}


Polynomial::Polynomial()
{
	h_pow = 0; 
	coeff = NULL;
}

Polynomial::Polynomial(int p)
{
	h_pow = p;
	coeff = new int[h_pow+1];	
	
	for (int i=0; i<=h_pow; i++)
	coeff[i] = 0;	
}

Polynomial::Polynomial(int p, char a)
{
	h_pow = p;
	coeff = new int[h_pow+1];	
	
	srand(time(NULL));
	for (int i=0; i<=h_pow; i++)
	coeff[i] = rand() % 5;	
}

Polynomial::Polynomial(const Polynomial &poly)
{
	//delete [] coeff;
	
	h_pow = poly.h_pow;
	coeff = new int[h_pow+1];
	
	//copying elements
	for (int i=0; i<=h_pow; i++)
	{
		coeff[i] = poly.coeff[i];
	}	
}

Polynomial& Polynomial::operator=(const Polynomial &poly)
{
	//delete [] coeff;
	
	h_pow = poly.h_pow;
	coeff = new int[h_pow+1];
	
	//copying elements
	for (int i=0; i<=h_pow; i++)
	{
		coeff[i] = poly.coeff[i];
	}
	
	return *this;
}

int Polynomial::get_pow() const
{
	return h_pow;
}

int Polynomial::get_coeff(int i) const
{
	if (i>=0 && i<=h_pow)
	{
		return coeff[i];
	}
	else
	{
		cout<<"\nIndex Out of Range!\n";
		return -9999;
	}
}

void Polynomial::set_pow(int p)
{
	h_pow = p; 
	coeff = new int[h_pow+1];
	
	//initialize all elements by zero
	for (int i=0; i<=h_pow; i++)
	coeff[i] = 0;
}

void Polynomial::set_val(int i, int val)
{
	if (i>=0 && i<=h_pow)
	{
		coeff[i] = val;
	}
	else
	{
		cout<<"\nIndex Out of Range!\n";
		return;
	}
}

bool Polynomial::operator==(const Polynomial &poly)
{
	//will check all elements only if highest powers are the same (meaning same number of elements)
	if (h_pow == poly.h_pow)
	{
		for (int i=0; i<h_pow+1; i++)
		{
			//if any value doesnot match
			if (coeff[i] != poly.coeff[i])
			{
				return false; 
			}
		}
		
		return true; 
	}
	else
	{
		return false; 
	}
}


Polynomial Polynomial::operator+(const Polynomial &poly)
{
	Polynomial temp;
	if (h_pow >= poly.h_pow)
	{
		temp.set_pow(h_pow);
	}
	else
	{
		temp.set_pow(poly.h_pow);
	}
	
	//whichever occurs first, add common elements till then
	for (int i=0; (i<h_pow+1 && i<poly.h_pow+1); i++)
	{
		temp.coeff[i] = coeff[i] + poly.coeff[i];
	}
	
	//rest of the array
	if (h_pow > poly.h_pow)
	{
		for (int i=poly.h_pow+1; i<=temp.h_pow; i++)
		temp.coeff[i] = coeff[i];
	}
	else
	{
		for (int i=h_pow+1; i<=temp.h_pow; i++)
		temp.coeff[i] = poly.coeff[i];
	}
	
	return temp;
}


Polynomial Polynomial::operator-(const Polynomial &poly)
{
	Polynomial temp;
	if (h_pow >= poly.h_pow)
	{
		temp.set_pow(h_pow);
	}
	else
	{
		temp.set_pow(poly.h_pow);
	}
	
	//whichever occurs first, subtract common elements till then
	for (int i=0; (i<h_pow+1 && i<poly.h_pow+1); i++)
	{
		temp.coeff[i] = coeff[i] - poly.coeff[i];
	}
	
	//rest of the array
	if (h_pow > poly.h_pow)
	{
		for (int i=poly.h_pow+1; i<=temp.h_pow; i++)
		temp.coeff[i] = coeff[i];
	}
	else
	{
		for (int i=h_pow+1; i<=temp.h_pow; i++)
		temp.coeff[i] = temp.coeff[i] - poly.coeff[i];
	}
	
	return temp;
}

Polynomial Polynomial::operator*(const Polynomial &poly) 
{
	//if passing obj has highest power 4, and passed obj has highest 2
	//Product's highest will be 6 (7 sized array)
	int total_highest = h_pow + poly.h_pow;
	cout<<"\nHighest Power of Product Will Be: "<<total_highest<<endl;
	
	Polynomial temp;
	temp.set_pow(total_highest);
	
	//finding which polynomial has greater power
	int which;
	
	if (h_pow >= poly.h_pow)
	which = 1;
	else
	which = 2;
	
	if (which == 1) //keeping bigger polynomial set in the inner loop
	{
		//multiplying each element of smaller obj with all elements of bigger obj
		for (int i=0;i<=poly.h_pow; i++)
		{
			int product;
			for (int j=0; j<=h_pow;j++)
			{
				//storing product of the co-efficients
				product = poly.coeff[i]*coeff[j];
				
				//powers will be added (indexes in this case), and current product added to that index
				//index may already have a value from previous iterations
				temp.coeff[i+j] = temp.coeff[i+j] + product;
			}
		}
	}
	else
	{
		for (int i=0;i<=h_pow; i++)
		{
			int product;
			for (int j=0; j<=poly.h_pow;j++)
			{
				//storing product of the co-efficients
				product = coeff[i]*poly.coeff[j];
				
				//powers will be added (indexes in this case), and current product added to that index
				//index may already have a value from previous iterations
				temp.coeff[i+j] = temp.coeff[i+j] + product;
			}
		}
	}
	
	return temp;
}

void Polynomial::operator+=(const Polynomial &poly)
{
	//reusing the above + operator code
	
	Polynomial temp;  //make a temporary obj
	temp = (*this);   //give it the value of current object
	temp = temp+poly; //add it with the passed object
	(*this) = temp;   //assign the updated value back to this object
}

void Polynomial::operator-=(const Polynomial &poly)
{
	//reusing the above - operator code
	
	Polynomial temp;  //make a temporary obj
	temp = (*this);   //give it the value of current object
	temp = temp-poly; //subtract it with the passed object
	(*this) = temp;   //assign the updated value back to this object
}


Polynomial::~Polynomial()
{
	delete [] coeff;
}