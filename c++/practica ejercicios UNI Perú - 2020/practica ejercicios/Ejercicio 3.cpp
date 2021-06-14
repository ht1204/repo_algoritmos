#include<iostream>
using namespace std;

int main(){
	
	float temperatura;
	float fahrenheit, rankine, kelvin;
	
	
	do{
		
		cout<<"\n\t Ingrese Temperatura en Celsius : ";
		cin>>temperatura;		
		
	}while(temperatura < 0);
	
	if(temperatura <= 50){
		
		fahrenheit = (temperatura*9/5) + 32;
		
		cout<<"\n\t Equivale a "<<fahrenheit<<" \370F";
				
	}else if(temperatura > 50 && temperatura <= 100){
		
		rankine = (temperatura + 273.15)*9/5;
		
		cout<<"\n\t Equivale a "<<rankine<<" \370R";
			
	}else{
		
		kelvin = temperatura + 273.15;
		
		cout<<"\n\t Equivale a "<<kelvin<<" K";
	}
	

	return 0;
}	
