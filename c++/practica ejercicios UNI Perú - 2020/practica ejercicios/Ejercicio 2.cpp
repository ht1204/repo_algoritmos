#include<iostream>
using namespace std;

int main(){
	
	float T1, T2;

	
	do{
		
		cout<<"\n\t Ingrese valor T1 : ";
		cin>>T1;
		
	}while(T1<=0 || T1>1);
	
	do{
		
		cout<<"\n\t Ingrese valor T2 : ";
		cin>>T2;		
		
	}while(T2<=0 || T2>1);
	
	if(T1>0.95 && T2>0.75){
		
		cout<<"\n\t Acero grado 1 ";
		
	}else if(T1>0.95 && T2<=0.75){
		
		cout<<"\n\t Acero grado 2 ";
		
	}else if(T1 < 0.95){
		
		cout<<"\n\t Acero grado 3";	
		
	}
	
	
	
	return 0;
}	
