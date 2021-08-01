#include<iostream>
#include<cmath>
using namespace std;

double function(double x){
	double f_a=exp(-x*x);
	return f_a;
}


int main(){
	cout.precision(8);
	int n,i;
	double a,b,c,h,sum=0,integral;
	
	cout<<"\n\tIngrese limite inferior de integracion:  ";
	cin>>a;
	
	do{
		
		cout<<"\n\tIngrese limite superior de integracion:  ";
		cin>>b;
	
	}while(b<=a);
	
	do{
	
		cout<<"\n\tIngrese cantidad de intervalos (tipo de orden):  ";
		cin>>n;
		
		if(n%3!=0){
			cout<<"\n\tLa cantidad de subintervalos debe ser multiplo de 3";
		}
		
	}while(n%3!=0);
	
	
	double x[n+1],y[n+1];
	h=(b-a)/n; //Tamaño de paso, ancho de subintervalos
	
	for(i=0;i<n+1;i++){
		x[i]=a+(i*h);
		y[i]=function(x[i]);
	}
	
	for(i=1;i<n;i++){
		if(i%3==0){
			sum+=2*y[i];
		}else{
			sum+=3*y[i];
		}
	}
	
	integral=3*(h/8)*(y[0]+y[n]+sum);
	cout<<"\n\tEl resultado de la integral es: "<<integral;
	
	cout<<"\n\n ";
	system("pause");
}
