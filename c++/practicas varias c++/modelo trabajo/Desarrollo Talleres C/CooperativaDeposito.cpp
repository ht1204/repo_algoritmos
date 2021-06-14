#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>



#include <ctime>
#include <cstdlib>
#include <wchar.h>
#include <locale.h>

#define N 20
#define PAUSE system("pause")

struct asociado{
	long dni;
	char nombre[30];
	char apellido[30];
	float deposito=0.0;
}asociados[N],asociadoRecorder;

int contadorAsociados=0;

FILE *arcAsociados;

void loadFile(){
	arcAsociados=fopen("asociados","r");
    if(!arcAsociados){
       arcAsociados=fopen("asociados","w");
    }
    fclose(arcAsociados);
}

void loadAsociados(){
	loadFile();
	
	if(arcAsociados==NULL){
         return;             
     }
     
     arcAsociados=fopen("asociados","r");
     fread(&asociadoRecorder,sizeof(struct asociado),1, arcAsociados);
     while(!feof(arcAsociados)){
     	asociados[contadorAsociados].dni=asociadoRecorder.dni;
     	strcpy(asociados[contadorAsociados].nombre,asociadoRecorder.nombre);
     	strcpy(asociados[contadorAsociados].apellido,asociadoRecorder.apellido);
     	asociados[contadorAsociados].deposito=asociadoRecorder.deposito;
    	
     	contadorAsociados++;
     	fread(&asociadoRecorder,sizeof(struct asociado),1, arcAsociados);
	 }
     
     fclose(arcAsociados);
}

void updateAsociado(){
		arcAsociados=fopen("asociados","w+");
		fclose(arcAsociados);
		arcAsociados=fopen("asociados","a+");
		for(int i=0;i<contadorAsociados;i++){
			asociadoRecorder.dni=asociados[i].dni;
			strcpy(asociadoRecorder.nombre,asociados[i].nombre);
			strcpy(asociadoRecorder.apellido,asociados[i].apellido);
			asociadoRecorder.deposito=asociados[i].deposito;
			fwrite(&asociadoRecorder,sizeof(struct asociado),1, arcAsociados);
		}
		fclose(arcAsociados);	
}

void title(){
	system("title Gestión Cooperativa Asociados");
}

void menu();

////////////**Gestión datos asociados***////////////
void menuGestionAsociados();
void agregarAsociado();
void editarAsociado();
void listarAsociado();
bool verificaDni(long dni);
bool verficaDniExistente(long dni,int counter);
////////////************************////////////

//////*************Estadísticas************//////////////
void menuEstadistico();
void promedioDepositoGeneral();
void mayorDepositante();
////////////************************////////////


int main(){
	title();
	loadAsociados();
	setlocale(LC_ALL, "");
	menu();
	printf("\n\n");
	getch();
}

void menu(){
	char opcionMenu='3';
	do{
		system("cls");
		printf("\n\tMenú Principal");
		printf("\n\t1.Gestionar datos asociados");
		printf("\n\t2.Datos estadísticos");
		printf("\n\t3.Salir");
		printf("\n\t");
		scanf("%c",&opcionMenu);
		switch(opcionMenu){
			case '1':
				system("cls");
				menuGestionAsociados();
				getch();
			break;
				
			case '2':
				system("cls");
				if(contadorAsociados>0){
					menuEstadistico();
				}else{
					printf("\n\tNo existen productos registrados");
				}
				printf("\n\n");
				system("pause");
				
			break;
			
			case '3':
				system("cls");
				printf("\n\tAdiós!");
				printf("\n\n");
			break;	
			
		}
	
	}while(opcionMenu!='3');
}

void menuGestionAsociados(){
	char opcionMenuGestion='4';
	do{
		system("cls");
		printf("\n\tMenú Gestión de Asociados");
		printf("\n\t1.Agregar asociado");
		printf("\n\t2.Editar asociado");
		printf("\n\t3.Listar asociados");
		printf("\n\t4.Volver a menú principal");
		printf("\n\t");
		scanf("%c",&opcionMenuGestion);
		switch(opcionMenuGestion){
			case '1':
				system("cls");
				agregarAsociado();
				getch();
			break;
				
			case '2':
				system("cls");
				if(contadorAsociados>0){
					editarAsociado();
				}else{
					printf("\n\tNo existen asociados registrados");
				}
				printf("\n\n");
				getch();
				
			break;
			
			case '3':
				system("cls");
				if(contadorAsociados>0){
					listarAsociado();
				}else{
					printf("\n\tNo existen asociados registrados");
				}
				printf("\n\n");
				getch();
			break;
			
		}
	
	}while(opcionMenuGestion!='4');
	
}

bool verificaDni(long dni){
	
	return (dni<100000000 || dni>999999999) ? true : false;
}

bool verficaDniExistente(long dni,int counter){
	bool flag=false;
	
	for(int i=0;i<counter;i++){
		if(asociados[i].dni==dni){
			flag=true;
			break;
		}
	}
	return flag;
}


void agregarAsociado(){
	long dni; float deposito;
	
	if(contadorAsociados<N){
		
		do{
			
			printf("\n\tIngrese DNI de asociado: ");
			scanf("%ld",&dni);
			
			if(verificaDni(dni) || verficaDniExistente(dni,contadorAsociados)){
				printf("\n\tIngrese DNI apropiado ");
			}
			
		}while(verificaDni(dni) || verficaDniExistente(dni,contadorAsociados));	
		
		asociados[contadorAsociados].dni=dni;	
		
		
		printf("\n\tIngrese nombre de asociado: ");
		fflush(stdin);
		gets(asociados[contadorAsociados].nombre);			
		
		printf("\n\tIngrese apellido de asociado: ");
		fflush(stdin);
		gets(asociados[contadorAsociados].apellido);	
		
		do{
			printf("\n\tIngrese depósito de asociado: S/ ");
			scanf("%f",&deposito);			
		}while(deposito<=0);
		
		asociados[contadorAsociados].deposito=deposito;
		
		asociadoRecorder.dni=asociados[contadorAsociados].dni;
		strcpy(asociadoRecorder.nombre,asociados[contadorAsociados].nombre);
		strcpy(asociadoRecorder.apellido,asociados[contadorAsociados].apellido);
		asociadoRecorder.deposito=asociados[contadorAsociados].deposito;
		
		arcAsociados=fopen("asociados","a+");
    	fwrite(&asociadoRecorder,sizeof (struct asociado),1,arcAsociados);
    	fclose(arcAsociados);	
			
		
		contadorAsociados++;
		printf("\n\n\tAsociado agregado!");		
	}
}

void editarAsociado(){
	
	char escogerAsociado;
	char escogerDatoAsociado='4';
	int item=0; float depositoMonto=0.0;
	
	printf("\n\tEditar Asociado");
	for(int i=0;i<contadorAsociados;i++){
		printf("\n\t %d \t %ld - %s %s",(i+1),asociados[i].dni,asociados[i].nombre,asociados[i].apellido);	
	}
	
	do{
		printf("\n\tSeleccione asociado a editar : ");
		printf("\n\t");
		escogerAsociado=getch();
		printf("\n\t Elegir: %c ",escogerAsociado);
		if(isdigit(escogerAsociado)){
			item = (int)escogerAsociado - 48;
		}
		
		if(item<1 || item>contadorAsociados){
			printf("\n\tDebe escoger asociado dentro del rango ");
		}
	}while(item<1 || item>contadorAsociados);
	printf("\n\n\t");	
	PAUSE;
	
	do{
		system("cls");
		printf("\n\tSeleccione dato a editar");
		printf("\n\tDNI: %ld",asociados[item-1].dni);
		printf("\n\t1.Nombre Asociado");
		printf("\n\t2.Apellido Asociado");
		printf("\n\t3.Depósito");
		printf("\n\t4.Salir");
		printf("\n\t");
		escogerDatoAsociado=getch();
		printf("\n\t");
		printf("%c",escogerDatoAsociado);
		switch(escogerDatoAsociado){
			case '1':
				printf("\n\tIngrese nombre de asociado: ");
				fflush(stdin);
				gets(asociados[item-1].nombre);	
						
			break;
			
			case '2':
				printf("\n\tIngrese apellido de asociado: ");
				fflush(stdin);
				gets(asociados[item-1].apellido);	
				
			break;
			
			case '3':
				
				do{
					printf("\n\tIngrese monto de depósito: S/ ");
					scanf("%f",&depositoMonto);
			
					if(depositoMonto<=0){
						printf("\n\tIngreso fuera de rango ");
					}
			
				}while(depositoMonto<=0);
				asociados[item-1].deposito=depositoMonto;
			break;
			
		}
		
		updateAsociado();
	}while(escogerDatoAsociado!='4');
	printf("\n\t");		
}


void listarAsociado(){
	
	printf("\n\tListado de Asociados");
	for(int i=0;i<contadorAsociados;i++){
		printf("\n\tDNI: %ld",asociados[i].dni);
		printf("\n\tNombre Asociado: %s  %s",asociados[i].nombre,asociados[i].apellido);
		printf("\n\tMonto Depósito: S/ %0.2f ",asociados[i].deposito);
		printf("\n\t_______________________");
		
	}
	printf("\n\n");	
	
}

//////////////////////////////////Estadístico///////////////////////////////
void menuEstadistico(){
	char opcionMenuEstadisticos='3';
	do{
		system("cls");
		printf("\n\tMenú Datos Estadísticos");
		printf("\n\t1. Promedio General Depósitos ");
		printf("\n\t2. Mayor Depositante ");
		printf("\n\t3. Volver al menú principal");
		printf("\n\t");
		scanf("%c",&opcionMenuEstadisticos);				
		switch(opcionMenuEstadisticos){
			case '1':
				system("cls");
				promedioDepositoGeneral();
				getch();
			break;
			case '2':
				system("cls");
				mayorDepositante();
				getch();
			break;			
		}
	}while(opcionMenuEstadisticos!='3');
}

void promedioDepositoGeneral(){
	float promedioGeneral=0.0,sumaTotal=0.0;
	for(int i=0;i<contadorAsociados;i++){
		sumaTotal+=asociados[i].deposito;
	}
	promedioGeneral=sumaTotal/contadorAsociados;
	printf("\n\t Promedio Depósito General : %f ",promedioGeneral);
	
}

void mayorDepositante(){
	int indexMayor=0;
	float deposito=asociados[indexMayor].deposito;
	
	for(int i=1;i<contadorAsociados;i++){
		if(deposito<asociados[i].deposito){
			deposito=asociados[i].deposito;
			indexMayor=i;
		}
	}
	
	printf("\n\t Mayor depositante : %s %s ",asociados[indexMayor].nombre,asociados[indexMayor].apellido);
}







