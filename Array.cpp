#include "Array.h"

istream& operator>>(istream& input, Array& a)
{
	int len;
	cout<<"Enter Size of Array: ";
	input>>len;
	a.set_len(len);

	int n=0;
	for (int i=0; i<len; i++)
	{
		cout<<"Value at Index ("<<i+1<<") : ";
		input>>n;
		a.set_value(i,n);
	}
	return input;
}

ostream& operator<<(ostream &ouput, Array& a)
{
	cout<<"\nArray Elements: ";

	for (int i=0; i<a.get_len(); i++)
	{
		ouput<<(a[i])<<"\t";
	}
	cout<<endl;
	return ouput;
}

Array::Array()
{
	len = 0;
	ptr = NULL;
}

Array::	Array(int size)
{
	len = size;
	ptr = new int[len];

	for(int i=0;i<len; i++)
	ptr[i] = 0;
}

Array::Array(int *arr, int size)
{
	//deep copy

	len = size;
	ptr = new int[len];

	//copying elements

	for (int i=0; i<len; i++)
	{
		ptr[i] = arr[i];
	}
}

Array::Array(const Array& arr)
{
	len = arr.len;
	ptr = new int[len];

	//copying elements
	for (int i=0; i<len; i++)
	{
		ptr[i] = arr.ptr[i];
	}
}

void Array::set_len(int size)
{
	len = size;
	ptr = new int[len];
}

int Array::get_len() const
{
	return len;
}

void Array::set_value(int idx, int num)
{
	if (idx >=0 && idx<len)
	ptr[idx] = num;
}

int Array::operator[](int i)
{
	//if within range
	if (i>=0 || i<len)
	{
		return ptr[i];
	}
	else
	{
		cout<<"Index out of range\n";
		return -99999;
	}
}

void Array::operator=(const Array a)
{
	len = a.len;
	ptr = new int[len];

	for (int i=0; i<len; i++)
	{
		ptr[i] = a.ptr[i];
	}

	return;
}

Array Array::operator+(const Array a)
{
	Array temp;

	//will add if lengths are equal
	if (len == a.len)
	{
		temp.len = len;
		temp.ptr = new int[temp.len];

		for (int i=0; i<temp.len; i++)
		{
			temp.ptr[i] = ptr[i] + a.ptr[i];
		}

		return temp;
	}
	else
	{
		cout<<"\nLengths are not equal! Cannot Add\n";
	}

}


Array Array::operator-(const Array a)
{
	Array temp;

	//will add if lengths are equal
	if (len == a.len)
	{
		temp.len = len;
		temp.ptr = new int[temp.len];

		for (int i=0; i<temp.len; i++)
		{
			temp.ptr[i] = ptr[i] - a.ptr[i];
		}

		return temp;
	}
	else
	{
		cout<<"\nLengths are not equal! Cannot Subtract\n";
	}

}

void Array::operator++()
{
	for (int i=0; i<len; i++)
	++ptr[i];
}


Array& Array::operator--(int)
{
	Array temp;
	temp.set_len(len);

	for (int i=0; i<len; i++)
	{
		temp.ptr[i] = ptr[i]--;
	}

	return temp;
}


bool Array::operator==(const Array a)
{
	//checking if length is equal

	bool check = false;
	if (len == a.len)
	{
		check = true;
		for (int i=0; i<len; i++)
		{
			if(ptr[i] != a.ptr[i])
			{
				check = false;
				break;
			}
		}
	}

	return check;
}


bool Array::operator!()
{
	if (len == 0)
	return true;
	else
	return false;
}

void Array::operator+=(const Array& a)
{
	//checks for plus operator are already made

	Array temp = (*this);
	temp = temp + a; //this object added with passed object

	(*this) = temp; //assigned added version back to this object
}

void Array::operator-=(const Array& a)
{
	//checks for minus operator are already made
	Array temp;
	temp = (*this) - a;

	(*this) = temp; //assigned subtracted version back to this object
}


int Array::operator() (int idx, int val)
{
	//if within range
	if (idx>=0 || idx<len)
	{
		if (ptr[idx] == val)
		{
			//storing elements first in a backup array
			int *arr = new int[len-1]; //one less element

			for (int i=0; i<(len-1); i++)
			arr[i] = 0;

			//copy the elements except that one
			for (int i=0, j=0; i<len; i++)
			{
				if (idx == i)
				continue;
				else
				{
					arr[j] = ptr[i];
					//cout<<arr[j]<<"\t";
					j++;
				}
			}

			len = len-1;
			ptr = new int[len-1];
			//copy elements of backup into ptr
			for (int i=0;i<len;i++)
			ptr[i] = arr[i];

			delete [] arr;

			return 1;
		}
		else
		{
			cout<<"Value doesnt match\n";
			return -1;
		}
	}
	else
	{
		cout<<"Index out of range\n";
		return -1;
	}
}


Array::~Array()
{
	delete [] ptr;
}
