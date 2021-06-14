#include<iostream>
using namespace std;

int main(){
	
	int n;
	float puntaje;
	int cantIngreso1=0,cantIngreso2=0,cantIngreso3=0,cantIngreso4=0, cantIngreso5=0, cantIngreso6=0, cantIngreso7=0, cantIngreso8=0;
	int totalIngresaron=0, totalNoPasaron=0;
	
			
	 do{
	 	
	 	cout<<"\n\t Ingrese cantidad de postulantes : ";
	 	cin>>n;
	 	
	 }while(n<1);
	 
	 float ingresados[n][8], noIngresadosPuntajes[n];
	 int ingresaronPostulantes[n][8], noIngresaron[n];
	 
	 cout<<"\n\t_______________________";
	 
	 for(int i=0;i<n;i++){
	 	
	 	cout<<"\n\tPostulante No "<<i+1;
	 	
	 	do{
	 		
		 	cout<<"\n\tIngrese puntaje postulante : ";
		 	cin>>puntaje;
		 	 		
		}while(puntaje<=0 || puntaje > 140);
		
		
		if(puntaje>=70 && puntaje<75){
		 	ingresados[cantIngreso1][0]=puntaje;
		 	ingresaronPostulantes[cantIngreso1][0]=i+1;		 	
		 	cantIngreso1++;
		 	totalIngresaron++;
		 }else{
		 	if(puntaje>=75 && puntaje<80){
			 	ingresados[cantIngreso2][1]=puntaje;
			 	ingresaronPostulantes[cantIngreso2][1]=i+1;
			 	cantIngreso2++;
				 totalIngresaron++;	 		
			 }else{
			 	if(puntaje>=80 && puntaje<85){
				 	ingresados[cantIngreso3][2]=puntaje;
				 	ingresaronPostulantes[cantIngreso3][2]=i+1;
				 	cantIngreso3++;
					totalIngresaron++; 	 		
				 }else{
				 	if(puntaje>=85 && puntaje<90){
					 	ingresados[cantIngreso4][3]=puntaje;
					 	ingresaronPostulantes[cantIngreso4][3]=i+1;
					 	cantIngreso4++;
						totalIngresaron++;	 		
					 }else{
					 	if(puntaje>=90 && puntaje<94){
						 	ingresados[cantIngreso5][4]=puntaje;
						 	ingresaronPostulantes[cantIngreso5][4]=i+1;
						 	cantIngreso5++;
							totalIngresaron++; 	 		
						 }else{
						 	if(puntaje>=94 && puntaje<96){
							 	ingresados[cantIngreso6][5]=puntaje;
							 	ingresaronPostulantes[cantIngreso6][5]=i+1;
							 	cantIngreso6++;
								totalIngresaron++; 	 		
							 }else{
							 	if(puntaje>=96 && puntaje<100){
								 	ingresados[cantIngreso7][6]=puntaje;
								 	ingresaronPostulantes[cantIngreso7][6]=i+1;
								 	cantIngreso7++;
									totalIngresaron++; 	 		
								 }else{
								 	if(puntaje>=100){
									 	ingresados[cantIngreso8][7]=puntaje;
									 	ingresaronPostulantes[cantIngreso8][7]=i+1;
									 	cantIngreso8++;
										totalIngresaron++;	 		
									 }else{
									 	noIngresaron[totalNoPasaron]=i+1;
									 	noIngresadosPuntajes[totalNoPasaron]=puntaje;
									 	totalNoPasaron++;
									 }							 	
								 }						 	
							 }					 	
						 }				 	
					 }			 	
				 }		 	
			 }
		 }
	 	
	 }
	 
	 
	 cout<<"\n\t";
	 cout<<"\n\t";
	 cout<<"\n\tReporte Admisiones ";
	 cout<<"\n\tCantidad Postulantes Ingresaron : "<<totalIngresaron;
	 cout<<"\n\tCantidad Postulantes No Ingresaron : "<<totalNoPasaron;
	 
	 float puntajePromedio1=0, puntajePromedio2=0,puntajePromedio3=0, puntajePromedio4=0, puntajePromedio5=0,
	 puntajePromedio6=0, puntajePromedio7=0, puntajePromedio8=0;
	 cout<<"\n\t";
	 cout<<"\n\t_______________________";
	 if(cantIngreso1>0){
		 cout<<"\n\t________Hoteleria____________";
		 for(int i=0;i<cantIngreso1;i++){
		 	cout<<"\n\tPostulante ingresado No "<<ingresaronPostulantes[i][0];
		 	cout<<"\n\tPuntaje : "<<ingresados[i][0];
		 	cout<<"\n\t________";
		 	puntajePromedio1+=ingresados[i][0];
		 }
		 cout<<"\n\tPuntaje Promedio Ingresados Hoteleria:  "<<puntajePromedio1/cantIngreso1;	 	
	 }else{
	 	cout<<"\n\tNo hubo admisiones en hoteleria";
	 }

	 
	 
	 cout<<"\n\t";
	 if(cantIngreso2>0){
	 	cout<<"\n\t__________Educacion_____________";
		 for(int i=0;i<cantIngreso2;i++){
		 	cout<<"\n\tPostulante ingresado No "<<ingresaronPostulantes[i][1];
		 	cout<<"\n\tPuntaje : "<<ingresados[i][1];
		 	cout<<"\n\t________";
		 	puntajePromedio2+=ingresados[i][1];
		 }
		 cout<<"\n\tPuntaje Promedio Ingresados Educacion:  "<<puntajePromedio2/cantIngreso2;	 	
	 }else{
	 	cout<<"\n\tNo hubo admisiones en educacion";
	 }
	
	 
	 cout<<"\n\t";
	 if(cantIngreso3>0){
		 cout<<"\n\t___________Comunicaciones__________";
		 for(int i=0;i<cantIngreso3;i++){
		 	cout<<"\n\tPostulante ingresado No "<<ingresaronPostulantes[i][2];
		 	cout<<"\n\tPuntaje : "<<ingresados[i][2];
		 	cout<<"\n\t________";
		 	puntajePromedio3+=ingresados[i][2];
		 }
		 cout<<"\n\tPuntaje Promedio Ingresados Comunicaciones:  "<<puntajePromedio3/cantIngreso3;	 	 	
	 }else{
	 	cout<<"\n\tNo hubo admisiones en comunicaciones";
	 }
	 
	
	 cout<<"\n\t";
	 if(cantIngreso4>0){
		 cout<<"\n\t________Marketing___________";
		 for(int i=0;i<cantIngreso4;i++){
		 	cout<<"\n\tPostulante ingresado No "<<ingresaronPostulantes[i][3];
		 	cout<<"\n\tPuntaje : "<<ingresados[i][3];
		 	cout<<"\n\t________";
		 	puntajePromedio4+=ingresados[i][3];
		 }
		 cout<<"\n\tPuntaje Promedio Ingresados Marketing:  "<<puntajePromedio4/cantIngreso4;	 	
	 }else{
	 	cout<<"\n\tNo hubo admisiones en marketing";
	 }
	
	
	 cout<<"\n\t";
	 if(cantIngreso5>0){
	 	cout<<"\n\t__________Turismo__________";
		 for(int i=0;i<cantIngreso5;i++){
		 	cout<<"\n\tPostulante ingresado No "<<ingresaronPostulantes[i][4];
		 	cout<<"\n\tPuntaje : "<<ingresados[i][4];
		 	cout<<"\n\t________";
		 	puntajePromedio5+=ingresados[i][4];
		 }
		 cout<<"\n\tPuntaje Promedio Ingresados Turismo:  "<<puntajePromedio5/cantIngreso5;		 	
	 }else{
	 	cout<<"\n\tNo hubo admisiones en turismo";
	 }
	

	 cout<<"\n\t";
	 if(cantIngreso6>0){
		 cout<<"\n\t__________Economia___________";
		 for(int i=0;i<cantIngreso6;i++){
		 	cout<<"\n\tPostulante ingresado No "<<ingresaronPostulantes[i][5];
		 	cout<<"\n\tPuntaje : "<<ingresados[i][5];
		 	cout<<"\n\t________";
		 	puntajePromedio6+=ingresados[i][5];
		 }
		 cout<<"\n\tPuntaje Promedio Ingresados Economia:  "<<puntajePromedio6/cantIngreso6;	 	
	 }else{
	 	cout<<"\n\tNo hubo admisiones en economia";
	 }

	 
	 cout<<"\n\t";	
	 if(cantIngreso7>0){
		 cout<<"\n\t__________Admon_____________";
		 for(int i=0;i<cantIngreso7;i++){
		 	cout<<"\n\tPostulante ingresado No "<<ingresaronPostulantes[i][6];
		 	cout<<"\n\tPuntaje : "<<ingresados[i][6];
		 	cout<<"\n\t________";
		 	puntajePromedio7+=ingresados[i][6];
		 }
		 cout<<"\n\tPuntaje Promedio Ingresados Administracion:  "<<puntajePromedio7/cantIngreso7;	 	
	 }else{
	 	cout<<"\n\tNo hubo admisiones en admon";
	 }

	 	 
	 cout<<"\n\t";	
	 if(cantIngreso8>0){
		 cout<<"\n\t_________Informatica______________";
		 for(int i=0;i<cantIngreso8;i++){
		 	cout<<"\n\tPostulante ingresado No "<<ingresaronPostulantes[i][7];
		 	cout<<"\n\tPuntaje : "<<ingresados[i][7];
		 	cout<<"\n\t________";
		 	puntajePromedio8+=ingresados[i][7];
		 }
		 cout<<"\n\tPuntaje Promedio Ingresados Informatica:  "<<puntajePromedio8/cantIngreso8;	 	 	
	 }else{
	 	cout<<"\n\tNo hubo admisiones en informatica";
	 }
	
	  
	 cout<<"\n\t";	
	 cout<<"\n\t_______________________";
	 if(totalNoPasaron>0){
	 	cout<<"\n\t_______________________";
	 	cout<<"\n\t_________No Admitidos______________";
		 for(int i=0;i<totalNoPasaron;i++){
		 	cout<<"\n\tPostulante No "<<noIngresaron[i];
			cout<<"\n\tPuntaje:  "<<noIngresadosPuntajes[i];
		 }	 	
	 }else{
	 	cout<<"\n\tTodos fueron admitidos en alguna carrera";
	 }

	 
	 
	cout<<"\n\t";	
	cout<<"\n\t";	
	
	return 0;
}		 
