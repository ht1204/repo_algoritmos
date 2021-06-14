#include<iostream>
using namespace std;

int main(){
	
	int sumaPares=0;
	int contadorPares=0;
	
//	for(int i=0;contadorPares<20;i++){
//		
//		if(i % 2 == 0){
//			
//			contadorPares++;
//			sumaPares+=i;
//			cout<<"\n\t Iterador : "<<i;
//			cout<<"\n\t Suma Par : "<<sumaPares;
//			cout<<"\n\t No Par : "<<contadorPares;
//			cout<<"\n\t__________________  ";
//		}
//		
//	}
	
	int i=0;
	
	do{
		
		if(i % 2 == 0){
			contadorPares++;
			sumaPares+=i;
		}
		
		i++;
		
	}while(contadorPares<20);	
	
	
	
	cout<<"\n\t Suma total pares: "<<sumaPares;	
	
	
	return 0;
}		
