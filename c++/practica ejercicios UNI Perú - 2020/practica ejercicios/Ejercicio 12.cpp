#include<iostream>
using namespace std;

int main(){
	
	int n;
	
	float montoComprado;
	int genero, origen, talla;
	float matrizDescuentos[2][6]={
		{0.1,0.12,0.15,0.15,0.17,0.2},
		{0.05,0.07,0.1,0.07,0.09,0.12}
	};
	
	do{
	 	cout<<"\n\tIngrese Cantidad de Prendas Compradas: ";
	 	cin>>n;			
	}while(n<1);
	
	float montoProductos[n];
	float importeDescuento[n];
	float montoPagar[n];
	float montoTotal=0;
	
	for(int i=0;i<n;i++){
		cout<<"\n\tProducto No "<<i+1;
		do{
		 	cout<<"\n\tIngrese Monto comprado : S/ ";
		 	cin>>montoComprado;		
		}while(montoComprado<1);
		
		montoProductos[i]=montoComprado;	
		
		do{
		 	cout<<"\n\tSeleccione genero ";
		 	cout<<"\n\t1-Hombre ";
		 	cout<<"\n\t2-Mujer \n\t";
		 	cin>>genero;				
		}while(genero<1 || genero>2);
		
		do{
		 	cout<<"\n\tSeleccione talla";
		 	cout<<"\n\t1-S ";
		 	cout<<"\n\t2-M ";
		 	cout<<"\n\t3-L \n\t";
		 	cin>>talla;				
		}while(talla<1 || talla>3);	
		
		do{
		 	cout<<"\n\tSeleccione origen";
		 	cout<<"\n\t1-Nacional ";
		 	cout<<"\n\t2-Importado \n\t";
		 	cin>>origen;				
		}while(origen<1 || origen>2);
		

		
		if(origen == 1){
			if(genero==1){
				if(talla==1){
					importeDescuento[i]=montoProductos[i]*matrizDescuentos[0][0];
				}else if(talla==2){
					importeDescuento[i]=montoProductos[i]*matrizDescuentos[0][1];
				}else{
					importeDescuento[i]=montoProductos[i]*matrizDescuentos[0][2];
				}		
			}else{
				if(talla==1){
					importeDescuento[i]=montoProductos[i]*matrizDescuentos[0][3];
				}else if(talla==2){
					importeDescuento[i]=montoProductos[i]*matrizDescuentos[0][4];
				}else{
					importeDescuento[i]=montoProductos[i]*matrizDescuentos[0][5];
				}
			}	
		}else{
			if(genero==1){
				if(talla==1){
					importeDescuento[i]=montoProductos[i]*matrizDescuentos[1][0];
				}else if(talla==2){
					importeDescuento[i]=montoProductos[i]*matrizDescuentos[1][1];
				}else{
					importeDescuento[i]=montoProductos[i]*matrizDescuentos[1][2];
				}		
			}else{
				if(talla==1){
					importeDescuento[i]=montoProductos[i]*matrizDescuentos[1][3];
				}else if(talla==2){
					importeDescuento[i]=montoProductos[i]*matrizDescuentos[1][4];
				}else{
					importeDescuento[i]=montoProductos[i]*matrizDescuentos[1][5];
				}
			}			
		}
		
		montoPagar[i]=montoProductos[i]-importeDescuento[i];
		montoTotal+=montoPagar[i];
	}

	 cout<<"\n\t";
	 cout<<"\n\t";
	 cout<<"\n\tFacturacion ";	
	for(int i=0;i<n;i++){
		cout<<"\n\tProducto No "<<i+1;
		cout<<"\n\tMonto Comprado: S/ "<<montoProductos[i];
		cout<<"\n\tImporte descuento: S/ "<<importeDescuento[i];
		cout<<"\n\tMonto a pagar por prenda: S/ "<<montoPagar[i];
		cout<<"\n\t_____________________";	
	}
	
	cout<<"\n\tTotal a pagar: S/"<<montoTotal;

	
	
	cout<<"\n\t";
	cout<<"\n\t";	
	
	return 0;
}		
