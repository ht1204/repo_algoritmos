#include<iostream>
using namespace std;

int main(){
	 int n, i=0;
	 int nota;
	 
	 
	 do{
	 	
	 	cout<<"\n\t Ingrese cantidad de alumnos: ";
	 	cin>>n;
	 	
	 }while(n<1);
	 
	 
	 do{
	 	
	 	
	 	do{
	 		cout<<"\n\t Ingrese nota alumuno "<<i+1<<" : ";
	 		cin>>nota;
		 }while(nota<0 || nota>20);
		 
		if(nota < 5){
			cout<<"\n\t Sin bonificacion ";
		}else if(nota>=5 && nota <10){
			cout<<"\n\t Bonificacion : 2 puntos";
			nota+=2;
		}else if(nota>=5 && nota <10){
			cout<<"\n\t Bonificacion : 2 puntos";
			nota+=2;
		}else if(nota>=10 && nota <15){
			cout<<"\n\t Bonificacion : 3 puntos";
			nota+=3;
		}else{
			cout<<"\n\tBonificacion : 4 puntos";
			nota+=4;			
		}
		
		
		cout<<"\n\tNota final alumno "<<i+1<<" : "<<nota;
	 	cout<<"\n\t_______________________";
	 	cout<<"\n\t";
	  i++;	
	 }while(i<n);
	 
	
	
	return 0;
}		
