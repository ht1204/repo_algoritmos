#include<iostream>
using namespace std;

void upDownCount();
void upDownCountWhile();

int main(){
	
   upDownCount();
   cout<<"\n\n\t";
   cout<<"\n\n\t";
   upDownCountWhile();
   cout<<"\n\n\t";	
   system("pause");
   return 0;
}


void upDownCount(){
	
	for(int oneToEnd = 1, endToOne=100; oneToEnd<=100 && endToOne>=1;oneToEnd++, endToOne--){
		cout<<"\n\t Count Up : "<<oneToEnd<<" | "<<" Count Down : "<<endToOne;
	}
}

void upDownCountWhile(){
	int oneToEnd = 1, endToOne=100;
	
	while(oneToEnd<=100 && endToOne>=1){
		
		cout<<"\n\t Count Up : "<<oneToEnd<<" | "<<" Count Down : "<<endToOne;
		oneToEnd++;
		endToOne--;	
	}
	
}
