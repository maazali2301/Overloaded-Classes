#include "Matrix.h"

istream& operator>>(istream& input,Matrix& m)
{
	//check if dimensions are not already initialized
	if (m.get_row()==0 && m.get_col()==0)
	{
	int rows, cols;
	cout<<"Enter Number of Rows and Columns: ";
	cin>>rows>>cols;
	
	m.set_dim(rows, cols); 
	}

	cout<<"This Matrix has:\n";
	cout<<"Rows: "<<m.get_row();
	cout<<"Columns: "<<m.get_col();
	cout<<endl;
	
	float num;
	for (int i=0; i<m.get_row(); i++)
	{
		for (int j=0; j<m.get_col(); j++)
		{
			cout<<"Enter Value at ["<<i+1<<"]["<<j+1<<"]: ";
			input>>num;
			m.set_value(i, j, num);
		}
	}

	return input;
}

ostream& operator<<(ostream& ouput,Matrix& m)
{
	cout<<"\nMatrix Output: \n";
	
	for (int i=0; i<m.get_row(); i++)
	{
		for (int j=0;j<m.get_col(); j++)
		ouput<<m.get_value(i,j)<<"\t";
		
		ouput<<endl;
	}

	return ouput; 
}

void Matrix::set_row(int i)
{
	row = i;
}
void Matrix::set_col(int j)
{
	col = j; 
}

void Matrix::set_dim(int i, int j)
{
	row = i; col =j;
	allocate(); 
}

void Matrix::allocate()
{
	ptr = new float*[row];
	for(int i=0; i<row; i++)
	ptr[i] = new float[col];
}

float Matrix::get_value(int r, int c)
{
	return ptr[r][c];
}

void Matrix::set_value(int i, int j, float num)
{
	ptr[i][j] = num; 
}
int Matrix::get_row()
{
	return row;
}

int Matrix::get_col()
{
	return col; 
}
		
Matrix::Matrix()
{
	row = col = 0; 
	ptr= NULL;
}

Matrix::Matrix(int r, int c)
{
	row = r; 
	col = c; 
	
	//Dynamic allocation
	ptr = new float*[row];
	for (int i=0; i<row; i++)
	ptr[i] = new float[col];
	
	srand(time(NULL));
	for (int i=0; i<row; i++)
	{
		for (int j=0; j<col; j++)
		{
			ptr[i][j] = 0;
		}
	}
}

Matrix::Matrix(int r, int c, int x)
{
	row = r; 
	col = c; 
	
	//Dynamic allocation
	ptr = new float*[row];
	for (int i=0; i<row; i++)
	ptr[i] = new float[col];
	
	srand(time(NULL));
	for (int i=0; i<row; i++)
	{
		for (int j=0; j<col; j++)
		{
			ptr[i][j] = (rand() % 10) + 1;
		}
	}
}

Matrix::Matrix(const Matrix &m)
{
	row = m.row; 
	col = m.col; 
	
	ptr = new float*[row];
	for (int i=0; i<row; i++)
	ptr[i] = new float[col];
	
	//copy elements
	for (int i=0; i<row; i++)
	{
		for (int j=0; j<col; j++)
		ptr[i][j] = m.ptr[i][j];
	}
}

void Matrix::operator() (int i, int j , float val)
{
	ptr[i][j] = val;
}

Matrix& Matrix::operator=(const Matrix& m)
{
	row = m.row;
	col = m.col;
	
	ptr = new float*[row];
	for (int i=0; i<row; i++)
	ptr[i] = new float[col];
	
	//copy elements
	for (int i=0; i<row; i++)
	{
		for (int j=0; j<col; j++)
		ptr[i][j] = m.ptr[i][j];
	}
	
	return *this;
}

bool Matrix::operator==(const Matrix &m)
{
	//checking if dimensions are the same
	if (m.row == row && m.col == col)
	{
		for (int i=0; i<row; i++)
		{
			for (int j=0; j<col; j++)
			{
				//return false as soon as an unequal value comes
				if (ptr[i][j] != m.ptr[i][j])
				{
					return false; 
				}
			}
		}
		
		return true; 
	}
	else
	{
		return false; 
	}
}

Matrix Matrix::operator+(const Matrix &m)
{
	//make a matrix of size same as the matrix that calls this optr
	Matrix temp(row, col);
	
	if (m.row == row && m.col == col)
	{
		for (int i=0; i<row; i++)
		{
			for (int j=0; j<col; j++)
			{
				temp.ptr[i][j] = ptr[i][j] + m.ptr[i][j];
			}
		}
	}
	else
	{
		cout<<"Cannot Add These Matrices (Dimensions Do Not Match)!\n";
		return *this; 
	}
	
	return temp; 
}



Matrix Matrix::operator-(const Matrix &m)
{
	//make a matrix of size same as the matrix that calls this optr
	Matrix temp(row, col);
	
	if (m.row == row && m.col == col)
	{
		for (int i=0; i<row; i++)
		{
			for (int j=0; j<col; j++)
			{
				temp.ptr[i][j] = ptr[i][j] - m.ptr[i][j];
			}
		}
	}
	else
	{
		cout<<"Cannot Subtract These Matrices (Dimensions Do Not Match)!\n";
		return *this; 
	}
	
	return temp; 
}


/* element Wise
Matrix Matrix::operator*(const Matrix &m)
{
	//make a matrix of size same as the matrix that calls this optr
	Matrix temp(row, col);
	
	if (m.row == row && m.col == col)
	{
		for (int i=0; i<row; i++)
		{
			for (int j=0; j<col; j++)
			{
				temp.ptr[i][j] = ptr[i][j] * m.ptr[i][j];
			}
		}
	}
	else
	{
		cout<<"Cannot Multiply These Matrices (Dimensions Do Not Match)!\n";
		return *this; 
	}
	
	return temp; 
} */



//Mathematical Way
Matrix Matrix::operator*(const Matrix &m)
{
	//Product Matrix: (Row1 * Col2)
	Matrix prod(row, m.col);
	
	//check if C1 size equals R2 size
	if (col == m.row)
	{
		//set to 0 to avoid garbage
		for (int i=0; i<prod.row; i++)
		{
			for (int j=0; j<prod.col; j++)
			prod.ptr[i][j] = 0;
		}
		
		//multiplying
		
		for (int i=0; i<row; i++)
		{
			for (int j=0; j<m.col; j++)
			{
				for (int k=0; k<col; k++)
				prod.ptr[i][j] += (ptr[i][k] * m.ptr[k][j]); 
			}
		}
	}
	else
	{
		cout<<"\nDimensions Do Not Comply with Math Rules!\n\n";
		return *this;
	}
	
	return prod;
} 

	
Matrix& Matrix::operator++(int)
{
	for (int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		ptr[i][j]++;
	}
	
	return *this; 
}

void Matrix::operator+=(const Matrix& m)
{
	for (int i=0; i<row; i++)
	{
		for (int j=0; j<col; j++)
		ptr[i][j] += m.ptr[i][j]; 
	}
}

void Matrix::operator-=(const Matrix& m)
{
	for (int i=0; i<row; i++)
	{
		for (int j=0; j<col; j++)
		ptr[i][j] -= m.ptr[i][j]; 
	}
}

Matrix::operator string()
{
	string s="";
	s+=to_string(row);
	s+="X";
	s+=to_string(col);
	s+='\n';
	for (int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			string temp = to_string(int(ptr[i][j]));
			s=s+temp;
			if(j<col-1)
			s+='-';
		}
		
		if (i<row-1)
		s+='\n';
	}
	
	return s;
}

Matrix::~Matrix()
{
	for (int i=0; i<row; i++)
	delete [] ptr[i];
	
	delete [] ptr;
}