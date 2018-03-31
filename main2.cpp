#include <iostream>
#include <iomanip>
//  This method provides easy solution for inverse.
//  Inverse matrix is the transpose of the adjoint matrix of A divided by determinant if
//     determinant is not equal to zero.
// A^-1=adjoint(A)/determinant(A)
//adjoint(A)= (cofactor matrix(A))^T
using namespace std;

int det(int [][3]);
int cofactor(int [][3],int ,int);
int GCD(int, int);
void  writesqMatrix(int [][3]);

	int main()
{
    int numerator, denominator, gcd, determ,i, j;
    int matrix[3][3];
	cout<<"We will find inverse of a 3x3 matrix!"<<endl<<endl;

	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			cout<<"Enter element ("<<i<<","<<j<<"): ";
			cin>>matrix[i][j];
        }
	}
		cout<<endl<<"Matrix A: "<<endl<<endl;
	writesqMatrix(matrix);
	determ=det(matrix);
    if(determ==0){
        cout<< "Matrix does not have inverse as determinant is zero."<<endl<<endl;
        return 0;
    }
    cout<<"Matrix A^-1: "<<endl<<endl;
    for (i=0; i<3; i++)
    {

        for (j=0; j<3; j++)
        {
            numerator=cofactor(matrix, j, i);
            denominator=determ;
            //reducing fraction by dividing by greatest common factor
            gcd=GCD(numerator, denominator);
            numerator/=gcd;
            denominator/=gcd;

            //making negative sign appear before fraction instead of accompanying denominator
            if(denominator<0)
            {
                numerator*=-1;
                denominator*=-1;
            }
            cout<<setw(20)<<numerator<<"/"<<denominator;
        }
        cout<<endl;
    }


    return 0;
}

    //returning cofactor
    int cofactor(int data[][3],int x,int y)
    {
        int cofactor_v;

        cofactor_v = data[(x + 1) % 3][(y + 1) % 3]
            * data[(x + 2) % 3][(y + 2) % 3]
            - data[(x + 1) % 3][(y + 2) % 3]
            * data[(x + 2) % 3][(y + 1) % 3];
        return cofactor_v;
    }

    //returns determinant for a 3x3 matrix
    int det(int data[][3])
    {
        int determinant;
        int x,y,z;
        x=data[0][0]*cofactor(data,0,0);
        y=data[0][1]*cofactor(data,0,1);
        z=data[0][2]*cofactor(data,0,2);
        determinant=x+y+z;
        return determinant;
    }

    // returns greatest common denominator
    int GCD(int a, int b)
    {
        while(true)
        {
            a = a % b;
            if( a == 0 )
                return b;
            b = b % a;

            if( b == 0 )
                return a;
        }
    }

    //outputs 3x3 square matrix
    void  writesqMatrix(int matrix[][3])
    {
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
                cout<<setw(20)<<matrix[i][j];
            cout<<endl<<endl;
        }
    }





