#include<iostream>
using namespace std;

int main(){
	
	int sumaImpares=0;
	int contadorImpares=0;
	
//	for(int i=1;contadorImpares<20;i++){
//		
//		if(i % 2 != 0){
//			
//			contadorImpares++;
//			sumaImpares+=i;
//			cout<<"\n\t Iterador : "<<i;
//			cout<<"\n\t Suma Impar : "<<sumaImpares;
//			cout<<"\n\t No Impar : "<<contadorImpares;
//			cout<<"\n\t__________________  ";
//			
//		}
//		
//	}
//
	int i=1;
	
	do{
		
		if(i % 2 != 0){
			contadorImpares++;;
			sumaImpares+=i;
		}
		
		i++;
		
	}while(contadorImpares<20);	
	
	cout<<"\n\t Suma total impares: "<<sumaImpares;	

	return 0;
}	
