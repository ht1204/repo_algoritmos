#include<iostream>
using namespace std;

bool validarX(double x){
	if(x <= 0 || x > 1) return true;
	return false;
}

bool validarN(int n){
	if(n < 1 || n > 1000) return true;
	return false;
}

double potencia(double x, int iteracion);
double factorial(int iteracion);


void series();

int main(){
	
   series();
   cout<<"\n\n\t";	
   system("pause");
   return 0;	
}


void series(){
	double x;
	int n;
	do{
		
		cout<<"\n\tIngrese X : ";
		cin>>x;
		
		if(validarX(x)) cout<<"\n\tDebe x mayor a cero y menor e igual a uno ";
	}while(validarX(x));
	
	do{
		cout<<"\n\tIngrese n-terminos : ";
		cin>>n;
		if(validarN(n)) cout<<"\n\tIngrese entre uno hasta mil terminos";		
	}while(validarN(n));
	
	double sumaSerie = 0.0;
	
	for(int i=0; i < n; i++){
		
		sumaSerie += potencia(x, i) / factorial(i);

	}
	
	cout<<"\n\tResultado suma de serie : "<<sumaSerie;
}

double potencia(double x, int iteracion){
	
	if(iteracion == 0) return 1;
	if(iteracion == 1) return x;
	
	if(iteracion > 1) {
		
		double potencia = 1.0;
		
		for(int i = 1; i <= iteracion; i++){
			potencia *= x;
		}
		

		return potencia;
				
	}
	

}

double factorial(int iteracion){
	
	if(iteracion <= 1) return 1;
	else{
		
		double fact = 1;
		
		for(int i = 2; i <= iteracion; i++){
			fact *= i;
		}

		return fact;
	}
	
}

