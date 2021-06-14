#include<iostream>
using namespace std;

int main(){
	
	float x, y;
	
	cout<<"\n\t Ingrese valor de X: ";
	cin>>x;
	
	if(x>=-3 && x<=2){
		
		y = (x*x) + (2*x) - 3;
		
	}else if(x>2 && x<=10){
		
		y = (5*x) + 7;
		
	}else if(x<=-3 || x>10){
		y=0;
	}
	
	cout<<"\n\t Y= "<<y;
	
	
	return 0;
}
