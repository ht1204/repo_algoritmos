#include<iostream>
using namespace std;

int main(){
	
	int sumaNaturales=0;
	
//	for(int i=0;i<20;i++){
//		
//		sumaNaturales+=i;
//		cout<<"\n\t Iterador: "<<i;
//		cout<<"\n\t Suma : "<<sumaNaturales;
//		cout<<"\n\t______________";		
//	}
	
	int i=0;
	do{
		
		sumaNaturales+=i;
		i++;
		
	}while(i<20);
	
	cout<<"\n\t Suma total : "<<sumaNaturales;	
	
	
	return 0;
}	
