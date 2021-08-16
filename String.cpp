#include "String.h"


istream& operator>>(istream& input,String& str)
{
	char *s = new char[100];
	//cin.ignore();
	cout<<"\nEnter String: ";
	input.getline(s, 100);
	
	int i;
	//find length of entered string
	for (i=0; s[i]!='\0'; i++);
	//cout<<"Length = "<<i<<endl;

	str.set_len(i);
	str.set_string(s); 
	
	return input;
}

ostream& operator<<(ostream& ouput,const String& str)
{
	if (str.get_len()>0)
	{
	cout<<"\nString Output: ";
	ouput<<str.get_string()<<endl;
	return ouput;
	}
}

void String::set_string(char *a)
{
	
	int i;
	for (i=0; a[i]!='\0'; i++);
		
	len = i;
	arr = new char[len+1];
	
	for (int i=0; i<len; i++)
	{
		arr[i] = a[i];
	}
	
	//arr[len] = '\0';
	
}

void String::set_len(int l)
{
	len = l;
	arr = new char[len];
}

char* String::get_string() const
{
	arr[len] = '\0';
	return arr;
}

int String::get_len() const
{
	return len;
}

String::String()
{
	len = 0;
	arr = NULL;
}

String::String(char* str)
{
	//finding length of the passed string
	int i;
	for (i=0; str[i]!='\0'; i++);
	
	len = i;
	arr = new char[len+1];
	
	//copying
	for (int a=0; a<len; a++)
	{
		arr[a] = str[a];
	}

	arr[len]='\0';
}

String::String(const String &str)
{
	len = str.len;
	arr = new char[len+1];
	
	//copying letter by letter
	for (int i=0; i<len; i++)
	arr[i] = str.arr[i];
	
	arr[len] = '\0';
}

String::String(int x)
{
	if (x > 0)
	{
		len = x;
		arr = new char[len];
		//make a default string
		for (int i=0; i<len; i++)
		{
			arr[i]='a';
		}
	}
	else
	{
		//elements of a default constructor
		len = 0;
		arr = NULL;
	}
}

char String::operator[](int i)
{
	//checking if in range
	if (i>=0 && i<len)
	return arr[i];
	
	else
	cout<<"\nGiven index is out of range!\n";
} 

String& String::operator+(String str)
{
	
	//length (of the appended version)
	int newlen = len + str.len;
	
	/*	String temp;
	temp.len = newlen; 
	temp.arr = new char[temp.len];
	
	for (int i=0; i<len; i++)
	temp.arr[i] = arr[i];	
	for (int i=len, j=0; i<newlen; i++, j++)
	temp.arr[i] = str.arr[j];
	
	temp.arr[newlen] = '\0'; 
	
	return temp; */
	
		
		//storing the appended string in a new char array
		char *ptr = new char[newlen];
		
		for (int i=0; i<len; i++)
		ptr[i] = arr[i];
		
		for (int i=len, j=0; i<newlen; i++, j++)
		ptr[i] = str.arr[j];
		
		//this array will now point to this new array (appended version)
		this->arr = ptr;
		this->len = newlen;
		
		return *this; 
} 

String& String::operator-(String substr)
{
	//finding length of the substr
	int i;
	for (i=0; substr.arr[i] != '\0'; i++);

	cout<<"Length of Substring: "<<i<<endl;
	
	//finding starting index of the substr
	int index = -1;
	int check = 0;
	if (i <= len) //length of substr must be less than or equal to the original string
	{
		//finding starting index of the substr
		for (int a=0; a<len; a++)
		{
			if (arr[a] == substr.arr[0])
			{
				check = 1;
				int x = a, y = 0;
				
				while (y<i)
				{
					if (arr[x] == substr.arr[y])
					{
						check = 1;
						x++;
						y++;	
					}	
					else
					{
						check = 0;
						break;
					}
				} 
				
				if (check == 1)
				{	index = a;
					break;
				}
			}
		}
		
		if (check == 0)
		{
		cout<<"\nSubtring Not Found!\n";
		return *this;
		}
	}
	
	//if (check ==1)
	//cout<<"Index : "<<index<<endl<<endl;
	
	
	//creating a new array (excluding elements of that substring)
	int newlen = len - i;
	char *ptr = new char[newlen+1];
	
	//cout<<newlen;
	for (int a=0,b=0; a<len; a++)
	{
		//we will skip indexes where substring lies
		if (a>=index && a<(index+i))
		{
			continue;
		}
		//copy elements of all other indexes
		else
		{
			ptr[b] = arr[a];
			b++;
		}
	}

	ptr[newlen] = '\0';
	this->arr = ptr;
	this->len = newlen;
	
	return *this;
}

bool String::operator!()
{
	//string is empty if first element is '\n' or length is 0
	
	if (len == 0 || arr[0] == '\0')
	return true;
	else
	return false;
}

String& String::operator=(const String& str)
{
	//length of string is same as that of new string to be copied
	len = str.len;
	arr = new char[len];
	
	for (int i=0; i<len; i++)
	{
		arr[i] = str.arr[i];
	}
	
	arr[len] = '\0';
	
	return *this;
}

bool String::operator==(const String &str)
{
	if (len != str.len)
	return false;
	
	else
	{
		for (int i=0; i<len; i++)
		{
			if (arr[i] != str.arr[i])
			{
				return false;
			}
		}
		
		return true;
	}
}

int String::operator()(char a)
{
	for(int i=0; i<len; i++)
	{
		if (arr[i] == a)
		return i;
	}
	return -1;
}

String String::operator*(int a)
{
	int newlen = len*a;
	char *ptr = new char[newlen];
	
	int x=0;
	//copy the same thing repeatedly 'a' times
	for (int i=0; i<a;i++)
	{
		for (int j=0; j<len; j++)
		{
			ptr[x] = arr[j];
			x++;
		}
	}
	
	len = newlen;
	arr = ptr;
	return *this;
	
}

int String::length()
{
	int size = 0;
	for (int i=0; arr[i]!='\0'; i++)
	{
		size++;
	}

	return size;
}

String::~String()
{
	//de-allocate the heap memory
	delete []arr;
}