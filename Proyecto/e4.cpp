//finding A, B, C by Cramer's rule

#include<iostream>
#include<cmath>
using namespace std;
double determinantofmatrix(double mat[3][3]);
void solution(double coeff[3][4]);

main() {
		//enter the number of pairs
    int n;
    cout<<"\nEnter the no. of data pairs to be entered:\n";        //To find the size of arrays
    cin>>n;
    //create and fill the vectors x & y
    double x[n],y[n];
    cout<<"\nEnter the x-axis values:\n";
    for (int i=0;i<n;i++)
        cin>>x[i];
    cout<<"\nEnter the y-axis values:\n";
    for (int i=0;i<n;i++)
        cin>>y[i];
    //create variables for the sums
    double xsum=0,x2sum=0,ysum=0,x3sum=0,xysum=0,x4sum=0,x2ysum=0;                //variables for sums/sigma of xi,yi,xi^2,xiyi etc
    for (int i=0;i<n;i++)
    {
        xsum=xsum+x[i];
        x2sum=x2sum+pow(x[i],2);
				ysum=ysum+y[i];
				x3sum=x3sum+pow(x[i],3);
        xysum=xysum+x[i]*y[i];
    		x3sum=x3sum+pow(x[i],3);
				x2ysum=x2ysum+pow(x[i],2)*y[i];  
		}
    // create the matrix for cramer's method
    double cramermatriz[3][4]={{n,xsum,x2sum,ysum},
																{xsum,x2sum,x3sum,xysum},
																{x2sum,x3sum,x4sum,x2ysum}};
    
    cout<<"----------"<<endl;
   	solution(cramermatriz);
}   

//cramer's method says it's necessary the determinant of the matrix
double determinantofmatrix(double mat[3][3]) { 
    double ans; 
    ans = mat[0][0] * (mat[1][1] * mat[2][2] - mat[2][1] * mat[1][2]) 
          - mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]) 
          + mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]); 
    return ans; 
} 

void solution(double coeff[3][4]) {  
		// Matrix d using coeff as given in cramer's rule 
    double d[3][3] = { 
        { coeff[0][0], coeff[0][1], coeff[0][2] }, 
        { coeff[1][0], coeff[1][1], coeff[1][2] }, 
        { coeff[2][0], coeff[2][1], coeff[2][2] }, 
    }; 
    // Matrix d1 using coeff as given in cramer's rule 
    double d1[3][3] = { 
        { coeff[0][3], coeff[0][1], coeff[0][2] }, 
        { coeff[1][3], coeff[1][1], coeff[1][2] }, 
        { coeff[2][3], coeff[2][1], coeff[2][2] }, 
    }; 
    // Matrix d2 using coeff as given in cramer's rule 
    double d2[3][3] = { 
        { coeff[0][0], coeff[0][3], coeff[0][2] }, 
        { coeff[1][0], coeff[1][3], coeff[1][2] }, 
        { coeff[2][0], coeff[2][3], coeff[2][2] }, 
    }; 
    // Matrix d3 using coeff as given in cramer's rule 
    double d3[3][3] = { 
        { coeff[0][0], coeff[0][1], coeff[0][3] }, 
        { coeff[1][0], coeff[1][1], coeff[1][3] }, 
        { coeff[2][0], coeff[2][1], coeff[2][3] }, 
    }; 
  
    // Calculating Determinant of Matrices d, d1, d2, d3 
		double D  = determinantofmatrix(d); 
		double D1 = determinantofmatrix(d1); 
		double D2 = determinantofmatrix(d2); 	
		double D3 = determinantofmatrix(d3); 
		
		
		double A = D1 / D; 
		double B = D2 / D; 
		double C = D3 / D; 
		
		cout << "the equation of the least-squares parabola: "<<endl<<"y="<<
						A<<"+"<<B<<"x +"<<C<<"x²"; 

    
} 
