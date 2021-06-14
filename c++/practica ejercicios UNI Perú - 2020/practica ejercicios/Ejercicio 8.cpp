#include<iostream>
using namespace std;

int main(){
	
	float costoArticulo, utilidadArticulo;
	int codigoArticulo;
	
	do{
		
		cout<<"\n\t Ingrese costo articulo: S/ ";
		cin>>costoArticulo;		
			
	}while(costoArticulo<=0);
	
	
	do{
		
		cout<<"\n\t Ingrese codigo de articulo : ";
		cin>>codigoArticulo;			
		
	}while(codigoArticulo<1 || codigoArticulo>3);
	
	
	if(codigoArticulo == 1){
		utilidadArticulo=costoArticulo*0.1;
	}else if(codigoArticulo == 2){
		utilidadArticulo=costoArticulo*0.12;
	}else{
		utilidadArticulo=costoArticulo*0.15;
	}
	
	
	cout<<"\n\t Utilidad del articulo : S/ "<<utilidadArticulo;
	
	
	
	return 0;
}	
