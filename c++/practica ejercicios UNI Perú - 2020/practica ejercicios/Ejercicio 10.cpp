#include<iostream>
using namespace std;

int main(){
	
	int n;
		
	 do{
	 	
	 	cout<<"\n\t Ingrese cantidad de empleados: ";
	 	cin>>n;
	 	
	 }while(n<1);	
	
	
	
	int codigoEmpleado[n];
	int cantSueldoRango1=0,cantSueldoRango2=0,cantSueldoRango3=0,cantSueldoRango4=0,cantSueldoRango5=0,cantSueldoRango6=0;
	float sueldoBruto[n];
	float descuento[n];
	float sueldoTotal[n];
	float totalPorDescuento=0;
	float sueldoBrutoRango1=0,sueldoBrutoRango2=0,sueldoBrutoRango3=0,sueldoBrutoRango4=0,sueldoBrutoRango5=0,sueldoBrutoRango6=0;
	bool flagExist=false;
	int codigo;
	float montoTotalPagar=0;
	float totalSueldoBruto=0;
	
	for(int i=0;i<n;i++){
		
		cout<<"\n\tEmpleado No "<<i+1;
		
		do{
			
			flagExist=false;
			
		 	cout<<"\n\tIngrese codigo empleado: ";
		 	cin>>codigo;	
		 	
			 if(codigo<0){
			 	cout<<"\n\tNo ingrese codigo negativo ";
			 }else{
			 	
			 	for(int j=0;j<i;j++){
			 		
			 		if(codigoEmpleado[j]==codigo){
			 			flagExist=true;
			 			break;
					 }
					 
				 }
				 
				 if(flagExist){
				 	cout<<"\n\tEl codigo se encuentra registrado";
				 }
			 }	
			
		}while(codigo<0 || flagExist);
		
		codigoEmpleado[i]=codigo;
		
		do{
		 	cout<<"\n\tIngrese sueldo bruto empleado : S/ ";
		 	cin>>sueldoBruto[i];			
		}while(sueldoBruto[i] < 100);
		
		if(sueldoBruto[i]<500){
			descuento[i]=sueldoBruto[i]*0;
			sueldoBrutoRango1+=sueldoBruto[i];
			cantSueldoRango1++;
		}else if(sueldoBruto[i]>=501 && sueldoBruto[i]<=1000){
			descuento[i]=sueldoBruto[i]*0.02;
			sueldoBrutoRango2+=sueldoBruto[i];
			cantSueldoRango2++;
		}else if(sueldoBruto[i]>=1001 && sueldoBruto[i]<=4000){
			descuento[i]=sueldoBruto[i]*0.08;
			sueldoBrutoRango3+=sueldoBruto[i];
			cantSueldoRango3++;
		}else if(sueldoBruto[i]>=4001 && sueldoBruto[i]<=8000){
			descuento[i]=sueldoBruto[i]*0.15;
			sueldoBrutoRango4+=sueldoBruto[i];
			cantSueldoRango4++;
		}else if(sueldoBruto[i]>=8001 && sueldoBruto[i]<=10000){
			descuento[i]=sueldoBruto[i]*0.21;
			sueldoBrutoRango5+=sueldoBruto[i];
			cantSueldoRango5++;			
		}else{
			descuento[i]=sueldoBruto[i]*0.3;
			sueldoBrutoRango6+=sueldoBruto[i];
			cantSueldoRango6++;				
		}
		
		sueldoTotal[i]=sueldoBruto[i]-descuento[i];	
		totalSueldoBruto+=sueldoBruto[i];
		totalPorDescuento+=descuento[i];
		montoTotalPagar+=sueldoTotal[i];
		
	}
	
	float datoPromedioSueldoBrutoRangos[6];
	if(cantSueldoRango1>0){
		datoPromedioSueldoBrutoRangos[0]=sueldoBrutoRango1/cantSueldoRango1;
	}else{
		datoPromedioSueldoBrutoRangos[0]=0;
	}
	if(cantSueldoRango2>0){
		datoPromedioSueldoBrutoRangos[1]=sueldoBrutoRango2/cantSueldoRango2;
	}else{
		datoPromedioSueldoBrutoRangos[1]=0;
	}	
	if(cantSueldoRango3>0){
		datoPromedioSueldoBrutoRangos[2]=sueldoBrutoRango3/cantSueldoRango3;
	}else{
		datoPromedioSueldoBrutoRangos[2]=0;
	}
	if(cantSueldoRango4>0){
		datoPromedioSueldoBrutoRangos[3]=sueldoBrutoRango4/cantSueldoRango4;
	}else{
		datoPromedioSueldoBrutoRangos[3]=0;
	}	
	if(cantSueldoRango5>0){
		datoPromedioSueldoBrutoRangos[4]=sueldoBrutoRango5/cantSueldoRango5;
	}else{
		datoPromedioSueldoBrutoRangos[4]=0;
	}
	
	if(cantSueldoRango6>0){
		datoPromedioSueldoBrutoRangos[5]=sueldoBrutoRango6/cantSueldoRango6;
	}else{
		datoPromedioSueldoBrutoRangos[5]=0;
	}
	cout<<"\n\t";
	cout<<"\n\t______________________________________";
	cout<<"\n\tReporte Financiero ";
	cout<<"\n\tTotal Pagar por Empresa : S/ "<<montoTotalPagar;
	cout<<"\n\tTotal Pagar por Descuentos : S/ "<<totalPorDescuento;
	cout<<"\n\tTotal Pagar Sueldo Bruto : S/ "<<totalSueldoBruto;
	cout<<"\n\tTotal de empleados: "<<n;
	
	cout<<"\n\t";	
	for(int i=0;i<n;i++){
		cout<<"\n\tEmpleado Ingresado No "<<i+1;
		cout<<"\n\t Codigo Empleado : "<<codigoEmpleado[i];
		cout<<"\n\t Sueldo Bruto Empleado : S/ "<<sueldoBruto[i];
		cout<<"\n\t Descuento Sueldo Empleado : S/ "<<descuento[i];
		cout<<"\n\t Sueldo Total Empleado : S/ "<<sueldoTotal[i];
	}	
	cout<<"\n\t";
	cout<<"\n\t";	
	cout<<"\n\tPromedio de sueldo por cada rango de sueldo bruto ";
	cout<<"\n\t";
	
	for(int i=0;i<6;i++){
		cout<<"\n\tPromedio Sueldo Rango "<<i+1<<" : S/"<<datoPromedioSueldoBrutoRangos[i];
		cout<<"\n\t";
	}
	cout<<"\n\t";
	cout<<"\n\t";	
	
	return 0;
}		
