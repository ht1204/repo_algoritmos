#include <stdio.h>
#include <stdbool.h>
#include<conio.h>

void inputData();
void besselFunction(double x, int n);
bool validarTerminos(int terminos);
double calcularFactorial(int k);
double potencia(double coef, int k);


main(int argc, char *argv[]) {

inputData();
getch();
return 0;
}

void inputData(){
	double x;
	int n, menosN;
	
	do{
		printf("\n\tIngrese termino x: ");
		scanf("%lf",&x);
	}while(x<1 || x>=3);
	
	do{
		printf("\n\tIngrese cantidad de terminos: ");
		scanf(" %d",&n);
		if(validarTerminos(n)){
			printf("\n\tEl numero de terminos debe ser mayor o igual a 1 y menor o igual a 10");
		}
	}while(validarTerminos(n));
	
	besselFunction(x,n);
	
}

bool validarTerminos(int terminos){
	bool flag=false;
	if(terminos<1 || terminos>10){
		flag=true;		
	}else{
		flag=false;	
	}
	return flag;	
}

void besselFunction(double x, int n){
	int k=0,subN=0;
	int jMasCoef=1;
	int jMenosCoef=-1;
	double sumaBessel=0;
	double sumaBesselMenos=0;
	
	while(subN<=n){
		
		while(k<n){
			sumaBessel+=(potencia(jMenosCoef,k)/(calcularFactorial(k)*calcularFactorial(subN+k)))*potencia(x/2,2*k+subN);
			sumaBesselMenos=potencia(jMenosCoef,subN)*sumaBessel;
			
			k++;
		}
		printf("\n\tPara n=%d, J(x)= %.10lf",subN,sumaBessel);
		printf("\n\tPara n=%d, J(x)= %.10lf",subN,sumaBesselMenos);
		printf("\n\t(-1)^n * J(x)= %.10lf",sumaBesselMenos);
		printf("\n\n\t________________________________________");
		sumaBessel=0;
		sumaBesselMenos=0;
		
		k=0;
		subN++;
	}

}

double calcularFactorial(int k){
	double factorial=1;
	int i=1;
	while(i<=k){
		factorial*=i;
		i++;
	}

	return factorial;
}

double potencia(double coef, int k){
	double potenciaNumero=1;
	int i=0;
	while(i<k){
		potenciaNumero*=coef;
		i++;
	}
		
	return potenciaNumero;
}












