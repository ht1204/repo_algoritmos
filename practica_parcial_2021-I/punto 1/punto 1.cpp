#include<iostream>
using namespace std;

bool cantidadNumeros(int cantidad);
bool rangoCifras(int num);
bool verificaCifras(int num);
void ingresaNumeros();
void analizaNumeros(int numeros[], int cantidad);
bool analizadorCifras(int num);

int main(){
	
   ingresaNumeros();
   cout<<"\n\n\t";	
   system("pause");
   return 0;
}

bool cantidadNumeros(int cantidad){
	if(cantidad < 1) return true;
	return false;
}

bool verificaCifras(int num){
	if(num < 1000 || num > 9999) return true;
	return false;
}

void ingresaNumeros(){
	
	int cantidad;
	do{
		cout<<"\n\tIngrese cantidad de numeros : ";
		cin>>cantidad;
		
		if(cantidadNumeros(cantidad)) cout<<"\n\tDebe haber al menos un numero";
	}while(cantidadNumeros(cantidad));
	
	int numeros[cantidad];
	
	for(int i = 0; i < cantidad; i++){
		
		do{
			cout<<"\n\tIngrese numero "<<i + 1<<" : ";
			cin>>numeros[i];
			
			if(verificaCifras(numeros[i])) cout<<"\n\tEl numero debe tener cuatro (4) cifras ";
			
		}while(verificaCifras(numeros[i]));
		
	}
	
	cout<<"\n\tNumeros ingresados en sistema, \n\tse procede a evaluar criterio de cifras\n\n";
	analizaNumeros(numeros, cantidad);
}

void analizaNumeros(int numeros[], int cantidad){
	cout<<"\n\tListado numeros ";
	bool flag = false;
	for(int i= 0; i < cantidad; i++){
		if(analizadorCifras(numeros[i])) {
			cout<<"\n\t"<<numeros[i];
			flag = true;
		}
	}
	if(!flag) cout<<"\n\tNingun numero cumple el criterio";
}

bool analizadorCifras(int num){
	int numAux = num;
	int digitosPar = 0, digitosImpar = 0;
	int i = 0;
	

	while(numAux > 0){
		
		int cifra = numAux % 10;

		if(i % 2 == 0) digitosPar += cifra;
		else digitosImpar += cifra;
		numAux /= 10;
		i++;
	}
	
	if(digitosPar == digitosImpar) return true;
	return false;
}















