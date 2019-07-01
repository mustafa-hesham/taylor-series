//This code is written by Mustafa Hesham Mohamed to evaluate a function using Tyler series expansion.
#include <iostream>
#include <cmath>
using namespace std;
int main(){
	double result;
	double total = 0;
	double subtotal[20];
	double subtotal2[20];
	double final;
	double fact = 1; //Factorial variable.
	double apperror; //Relative approximate error.
	double accerror; //Accepted error percentage.
	double x0; 
	double x1;
	double xdiff; //x1-xo
	int n; //Number of terms.
	int f;
	int iterations;
	cout <<"Please enter number of terms: "<<endl;
	cin>>n;
	double coeff[n]; //An array for storing the coefficients of the functions.
	double power[n]; //An array for storing the powers of x in each polynomial.
	cout <<"Please enter x0: "<<endl;
	cin>>x0;
	cout <<"Please enter x1: "<<endl;
	cin>>x1;
	cout <<"Please enter accepted relative error (percent): "<<endl;
	cin>>accerror;
	xdiff = x1 - x0;
	
	for (int i = 0; i<=n-1; i++){
		cout<<"Please enter the coefficient number "<<i+1<<endl;
		cin>>coeff[i];
		cout<<"Please enter the power number "<<i+1<<endl;
		cin>>power[i];
		}
	   for (f=0; f<=100; ++f){ //Maximum number of iteration is 100.
	   total = 0;
	   result = 0;
	   for (int i=0; i<n; i++){
	   	result = coeff[i] * pow(x0, power[i]); //Calculating each polynomial result.
		total += result; //Sum of all polynomials
	    }
	   fact = 1;
	   if (f==0 || f == 1) fact =1; //Factorials of zero and one are equal to one.
	   else{
	   for (int s=1; s<=f; s++){
	   	fact *=s; //Calculating factorials of numbers greater than 1.
	   }}
	   subtotal[f] = total * pow(xdiff, f)/fact; //Multiplying the resulting f(x) derviative n by (x1-x0) power n and divide by the factorial of n.
	   subtotal2[f] = subtotal[f]; //Storing each term result in an array for comparison and error calculation.
	   if(f==0){
	   
	   cout<<"The f(x1)"<<f<<"= "<<subtotal[f]<<endl;
	   cout <<"Relative error isn't defined yet!"<<endl; //First iteration doesn't have a precedent to compare with.
	   cout <<"-----------------------------"<<endl;
}
	   if (f>0){
	   	
	   	subtotal2[f] = subtotal2[f-1] + subtotal[f];
	   
	   cout<<"The f(x1)"<<f<<"= "<<subtotal2[f]<<endl;
	   	apperror = (subtotal2[f] - subtotal2[f-1])*100/subtotal2[f];
	   	cout <<"Relative error is "<<apperror<<"%"<<endl;
	   	cout <<"-----------------------------"<<endl;
		final = subtotal2[f];
		iterations = f+1;
	   	 if (accerror > apperror) f = 200;
	   }
	   
	  
	  
	for (int i = 0; i<n; i++){ //differentiation of each term to calculate the next term in Tylor series.
		
		if (power[i] >0 && power[i] != 1) {
			
		coeff[i] =  coeff[i] * power[i];
		power[i] = power[i] - 1;	
	}
		else if (power[i] == 0){
			
			power[i] = 0;
			coeff[i] = 0;
		}
		
		else if (power[i] == 1) {
		power[i] = 0;
		coeff[i] = coeff[i];
	}
	}	
}
		cout<<"The f(x1)= "<<final<<"\t The percentage error is "<<apperror<<"%"<<endl;
		cout<<"Number of iterations is "<<iterations<<endl;
	
	return 0;	
}
