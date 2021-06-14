#include<iostream>
using namespace std;

int main(){
	
	int cantidadRolloTipo1,cantidadRolloTipo2, cantidadRolloTipo3;
	int costoRolloTipo1=120, costoRolloTipo2=90, costoRolloTipo3=40;	
	float subtotalRolloTipo1, subtotalRolloTipo2, subtotalRolloTipo3;
	
	cout<<"\n\t Informacion";
	cout<<"\n\t Rollos tipo 1 : 500 ft | S/ 120";
	cout<<"\n\t Rollos tipo 2 : 300 ft | S/ 90";
	cout<<"\n\t Rollos tipo 1 : 75 ft | S/ 40";
	cout<<"\n\t_______________________________";
	cout<<"\n\t";
	
	do{
		
		cout<<"\n\t Ingrese cantidad rollos tipo 1: ";
		cin>>cantidadRolloTipo1;
		
	}while(cantidadRolloTipo1 < 1);
	
	do{
		
		cout<<"\n\t Ingrese cantidad rollos tipo 2: ";
		cin>>cantidadRolloTipo2;
		
	}while(cantidadRolloTipo2 < 1);
	
	do{
		
		cout<<"\n\t Ingrese cantidad rollos tipo 3: ";
		cin>>cantidadRolloTipo3;
		
	}while(cantidadRolloTipo3 < 1);	
	
	subtotalRolloTipo1=costoRolloTipo1*cantidadRolloTipo1;
	subtotalRolloTipo2=costoRolloTipo2*cantidadRolloTipo2;
	subtotalRolloTipo3=costoRolloTipo3*cantidadRolloTipo3;
	
	cout<<"\n\t";
	cout<<"\n\tReporte subtotales ";
	cout<<"\n\tSubtotal Rollo Tipo 1: S/ "<<subtotalRolloTipo1;
	cout<<"\n\tSubtotal Rollo Tipo 2: S/ "<<subtotalRolloTipo2;
	cout<<"\n\tSubtotal Rollo Tipo 3: S/ "<<subtotalRolloTipo3;
	cout<<"\n\t";
	
	float netoPagar=subtotalRolloTipo1+subtotalRolloTipo2+subtotalRolloTipo3;
	cout<<"\n\tReporte neto a pagar : S/ "<<netoPagar;
	
	float montoIGV=netoPagar * 0.18;
	cout<<"\n\tReporte IGV (18%) : S/ "<<montoIGV;	

	float totalVenta = netoPagar + montoIGV;
	cout<<"\n\tReporte Total de venta: S/ "<<totalVenta;
	
	cout<<"\n\t";
	cout<<"\n\t";	
	
	
	return 0;
}		
