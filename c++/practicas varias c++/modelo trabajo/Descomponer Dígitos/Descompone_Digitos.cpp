#include <stdio.h>
#include<iostream>
#define N 19
using namespace std;

//Soporta hasta números de 19 cifras, ajustar en #define N XX


int main(){
	long int number;
	int digits[N];
	int counter=0;
	 
	 cout<<"\n\t Please, input a number : ";
	 cin>>number;
	 
	 int containerNumber=0;
	 
	 while(number>0){
	 	containerNumber= number % 10;
	 	number=number/10;
	 	digits[counter]=containerNumber;
	 	counter=counter+1;
	 }
	 
	 cout<<"\n\n\n Decomposed Number: \t";
	 cout<<"\n";
	 cout<<"\n";
	for(int i=counter-1;i>=0;i--){
		cout<<"\t"<<digits[i]<<"*10^"<<(i)<<"";
		
		if(i!=0){
			cout<<"+";
		}
		
	}
	 	
		
}
