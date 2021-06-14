#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>



#include <ctime>
#include <cstdlib>
#include <wchar.h>
#include <locale.h>

#define N 40
#define sizeNotas 10

struct alumno{
	char nombre[30];
	int numeroLegajo;
	int edad;
	int cantidadNotas;
	int notas[sizeNotas]={0,0,0,0,0,0,0,0,0,0};
	float promedioNotas;
	int mejor_10;
}alumnos[N],alumnoRecorder;

int contadorAlumnos=0;

FILE *arcAlumno;

void loadFile(){
	arcAlumno=fopen("alumnos","r");
    if(!arcAlumno){
       arcAlumno=fopen("alumnos","w");
    }
    fclose(arcAlumno);
}

void cargaNotas();

void loadAlumnos(){
	loadFile();
	if(arcAlumno==NULL){
         return;             
     }
     
     
     arcAlumno=fopen("alumnos","r");
     fread(&alumnoRecorder,sizeof(struct alumno),1, arcAlumno);
     while(!feof(arcAlumno)){
     	alumnos[contadorAlumnos].numeroLegajo=alumnoRecorder.numeroLegajo;
     	strcpy(alumnos[contadorAlumnos].nombre,alumnoRecorder.nombre);
     	alumnos[contadorAlumnos].edad=alumnoRecorder.edad;
     	
		cargaNotas();
     	
 		for(int i=0;i<sizeNotas;i++){
	     		alumnos[contadorAlumnos].notas[i]=alumnoRecorder.notas[i];
	    }
		 

     	     	
     	contadorAlumnos++;
     	fread(&alumnoRecorder,sizeof(struct alumno),1, arcAlumno);
	 }
     
     fclose(arcAlumno);
}

void updateAlumno(){
		arcAlumno=fopen("alumnos","w+");
		fclose(arcAlumno);
		arcAlumno=fopen("alumnos","a+");
		for(int i=0;i<contadorAlumnos;i++){
			alumnoRecorder.numeroLegajo=alumnos[i].numeroLegajo;
			strcpy(alumnoRecorder.nombre,alumnos[i].nombre);
			alumnoRecorder.edad=alumnos[i].edad;
			for(int j=0;j<sizeNotas;j++){
				alumnoRecorder.notas[j]=alumnos[i].notas[j];
			}
			fwrite(&alumnoRecorder,sizeof( struct alumno),1,arcAlumno);
		}
		fclose(arcAlumno);	
}


void title(){
	system("title Gestión Facultad Alumnos");
}

void menu();

////////////**Gestión datos alumnos***////////////
void menuGestionAlumno();
void agregarAlumno();
void consultarAlumno();
void editarAlumno();
void eliminarAlumno();
void listarAlumno();
void listarDatosGeneralAlumno();
void listarNotasAlumno();
bool verficaLegajo(int legajo,int counter);
bool verificaRangoLegajo(int legajo);
////////////************************////////////

//////*************Estadísticas************//////////////
void menuEstadistico();
void listadoOrdenPorPromedio();
void cantidadUnaNota();
void mayorCantidad10();
////////////************************////////////

int main(){
	title();
	loadAlumnos();
	setlocale(LC_ALL, "");
	menu();
	printf("\n\n");
	getch();
}

void cargaNotas(){
	
	for(int i=0;i<sizeNotas;i++){
		alumnos[contadorAlumnos].notas[i]=0;
	}
}


void menu(){
	char opcionMenu='3';
	do{
		system("cls");
		printf("\n\tMenú Principal");
		printf("\n\t1.Gestionar datos alumno");
		printf("\n\t2.Datos estadísticos");
		printf("\n\t3.Salir");
		printf("\n\t");
		scanf("%c",&opcionMenu);
		switch(opcionMenu){
			case '1':
				system("cls");
				menuGestionAlumno();
				getch();
			break;
				
			case '2':
				system("cls");
				if(contadorAlumnos>0){
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


///////////////*********Gestión de alumnos*************/////////////////
void menuGestionAlumno(){
	char opcionMenuGestion='6';
	do{
		system("cls");
		printf("\n\tMenú Gestión de Alumnos");
		printf("\n\t1.Agregar alumno");
		printf("\n\t2.Consultar alumnos");
		printf("\n\t3.Editar alumno");
		printf("\n\t4.Eliminar alumno");
		printf("\n\t5.Listar alumnos");
		printf("\n\t6.Volver a menú principal");
		printf("\n\t");
		scanf("%c",&opcionMenuGestion);
		switch(opcionMenuGestion){
			case '1':
				system("cls");
				agregarAlumno();
				getch();
			break;
				
			case '2':
				system("cls");
				if(contadorAlumnos>0){
					consultarAlumno();
				}else{
					printf("\n\tNo existen alumnos registrados");
				}
				printf("\n\n");
				getch();
				
			break;
			
			case '3':
				system("cls");
				if(contadorAlumnos>0){
					editarAlumno();
				}else{
					printf("\n\tNo existen alumnos registrados");
				}
				printf("\n\n");
				getch();
			break;
			
			case '4':
				system("cls");
				if(contadorAlumnos>0){
					eliminarAlumno();
				}else{
					printf("\n\tNo existen alumnos registrados");
				}
				printf("\n\n");
				getch();
			break;	
			
			case '5':
				system("cls");
				if(contadorAlumnos>0){
					listarAlumno();
				}else{
					printf("\n\tNo existen alumnos registrados");
				}
				printf("\n\n");
				getch();
			break;
			
		}
	
	}while(opcionMenuGestion!='6');
	
}

bool verificaRangoLegajo(int legajo){
	
	return (legajo<0 || legajo>10000) ? true : false;
}

bool verficaLegajo(int legajo,int counter){
	bool flag=false;
	
	for(int i=0;i<counter;i++){
		if(alumnos[i].numeroLegajo==legajo){
			flag=true;
			break;
		}
	}
	return flag;
}

void agregarAlumno(){
	int legajo, edad, cantNotas;
	if(contadorAlumnos<N){
		
		do{
			
			printf("\n\tIngrese número de legajo: ");
			scanf("%d",&legajo);
			
		}while(verificaRangoLegajo(legajo) || verficaLegajo(legajo,contadorAlumnos));
	
		alumnos[contadorAlumnos].numeroLegajo=legajo;
		

		
			printf("\n\tIngrese nombre de alumno: ");
			fflush(stdin);
			gets(alumnos[contadorAlumnos].nombre);
		
	
		
		do{
			printf("\n\tIngrese edad: ");
			scanf("%d",&edad);
			
			if(edad<5){
				printf("\n\tLa edad debe ser mayor a 5 años");
			}
			
		}while(edad<5);
		
		alumnos[contadorAlumnos].edad=edad;
		
		
		do{
			printf("\n\tIngrese cantidad de notas: ");
			scanf("%d",&cantNotas);
			
			if(cantNotas<1 || cantNotas>10){
				printf("\n\tIngreso fuera de rango ");
			}
			
		}while(cantNotas<1 || cantNotas>10);
		
		int calificacion;
		for(int i=0;i<cantNotas;i++){
			
			do{
			
				printf("\n\tIngrese nota  %d :  ",(i+1));
				scanf("%d",&calificacion);
				
			}while(calificacion<1||calificacion>10);
			
			alumnos[contadorAlumnos].notas[i]=calificacion;

		}
		
		for(int i=0;i<cantNotas;i++){
			alumnoRecorder.notas[i]=alumnos[contadorAlumnos].notas[i];
		}
		
		alumnoRecorder.numeroLegajo=alumnos[contadorAlumnos].numeroLegajo;
		strcpy(alumnoRecorder.nombre,alumnos[contadorAlumnos].nombre);
		alumnoRecorder.edad=alumnos[contadorAlumnos].edad;
		
		arcAlumno=fopen("alumnos","a+");
    	fwrite(&alumnoRecorder,sizeof (struct alumno),1,arcAlumno);
    	fclose(arcAlumno);	
			
		contadorAlumnos++;
		printf("\n\n\tAlumno agregado!");
		
	}else{
		printf("\n\n\tLímite de almacenamiento alcanzado :(");
	}
}


void listarAlumno(){
	char opcionMenuListar='3';
	do{
		system("cls");
		printf("\n\tListar Alumnos");
		printf("\n\t1.Listado General de Alumnos");
		printf("\n\t2.Listado de notas de Alumno");
		printf("\n\t3.Regresar a menú gestión alumnos");
		printf("\n\t");
		scanf(" %c",&opcionMenuListar);
		switch(opcionMenuListar){
			case '1':
				system("cls");
				listarDatosGeneralAlumno();	
				getch();				
				break;
			case '2':
				system("cls");
				listarNotasAlumno();
				getch();
				break;
		}
		
	}while(opcionMenuListar!='3');

}


void listarDatosGeneralAlumno(){
	
	printf("\n\tListado de Alumnos");
	for(int i=0;i<contadorAlumnos;i++){
		printf("\n\tNúmero Legajo: %d",alumnos[i].numeroLegajo);
		printf("\n\tNombre Alumno: %s",alumnos[i].nombre);
		printf("\n\tEdad: %d ",alumnos[i].edad);
		printf("\n\t_______________________");
		
	}
	printf("\n\n");
	
}

void listarNotasAlumno(){
	char escogerAlumno;
	int item=0;
	
	printf("\n\tListar Notas de Alumno");
	for(int i=0;i<contadorAlumnos;i++){
		printf("\n\t %d \t %d - %s",(i+1),alumnos[i].numeroLegajo,alumnos[i].nombre);	
	}
	
	do{
		printf("\n\tSeleccione alumno a revisar : ");
		printf("\n\t");
		scanf(" %c",&escogerAlumno);
		printf("\n\t Elegir: %c",escogerAlumno);
		if(isdigit(escogerAlumno)){
			item = (int)escogerAlumno - 48;
		}
		
		if(item<1 || item>contadorAlumnos){
			printf("\n\tDebe escoger a alumno dentro del rango ");
		}
	}while(item<1 || item>contadorAlumnos);
	
	system("cls");
	printf("\n\tNúmero Legajo: %d",alumnos[item-1].numeroLegajo);
	printf("\n\tNombre Alumno: %s",alumnos[item-1].nombre);
	for(int i=0;i<sizeNotas;i++){
		if(alumnos[item-1].notas[i]!=0){
			printf("\n\tNota No %d : %d",(i+1),alumnos[item-1].notas[i]);
		}
	}
	printf("\n\t");
}

void consultarAlumno(){
	char escogerAlumno;
	int item=0;
	
	printf("\n\tConsultar Alumno");
	for(int i=0;i<contadorAlumnos;i++){
		printf("\n\t %d \t %d - %s",(i+1),alumnos[i].numeroLegajo,alumnos[i].nombre);	
	}
	
	do{
		printf("\n\tSeleccione alumno a consultar : ");
		printf("\n\t");
		scanf(" %c",&escogerAlumno);
		printf("\n\t Elegir: %c",escogerAlumno);
		if(isdigit(escogerAlumno)){
			item = (int)escogerAlumno - 48;
		}
		
		if(item<1 || item>contadorAlumnos){
			printf("\n\tDebe escoger a alumno dentro del rango ");
		}
	}while(item<1 || item>contadorAlumnos);
	
	system("cls");
	printf("\n\tNúmero Legajo: %d",alumnos[item-1].numeroLegajo);
	printf("\n\tNombre Alumno: %s",alumnos[item-1].nombre);
	printf("\n\tEdad Alumno: %d",alumnos[item-1].edad);
	for(int i=0;i<sizeNotas;i++){
		if(alumnos[item-1].notas[i]!=0){
			printf("\n\tNota No %d : %d",(i+1),alumnos[item-1].notas[i]);
		}
	}
	printf("\n\t");
}

void editarAlumno(){
	char escogerAlumno;
	char escogerDatoAlumno='4';
	int item=0,edadAlumno, cantidadNotas, nota;
	
	printf("\n\tEditar Alumno");
	for(int i=0;i<contadorAlumnos;i++){
		printf("\n\t %d \t %d - %s",(i+1),alumnos[i].numeroLegajo,alumnos[i].nombre);	
	}
	
	do{
		printf("\n\tSeleccione alumno a editar : ");
		printf("\n\t");
		scanf(" %c",&escogerAlumno);
		printf("\n\t Elegir: %c",escogerAlumno);
		if(isdigit(escogerAlumno)){
			item = (int)escogerAlumno - 48;
		}
		
		if(item<1 || item>contadorAlumnos){
			printf("\n\tDebe escoger a alumno dentro del rango ");
		}
	}while(item<1 || item>contadorAlumnos);
	
	do{
		system("cls");
		printf("\n\tSeleccione dato a editar");
		printf("\n\tNúmero Legajo: %d",alumnos[item-1].numeroLegajo);
		printf("\n\t1.Nombre Alumno");
		printf("\n\t2.Edad Alumno");
		printf("\n\t3.Notas Alumno");
		printf("\n\t4.Salir");
		printf("\n\t");
		scanf("%c",&escogerDatoAlumno);
		switch(escogerDatoAlumno){
			case '1':
				printf("\n\tIngrese nombre de alumno: ");
				fflush(stdin);
				gets(alumnos[item-1].nombre);			
			break;
			
			case '2':
				do{
					printf("\n\tIngrese edad: ");
					scanf("%d",&edadAlumno);
				
					if(edadAlumno<5){
						printf("\n\tLa edad debe ser mayor a 5 años");
					}
			
				}while(edadAlumno<5);
		
				alumnos[item-1].edad=edadAlumno;

			break;
			
			case '3':
				
				do{
						printf("\n\tIngrese cantidad de notas: ");
						scanf("%d",&cantidadNotas);
			
					if(cantidadNotas<1 || cantidadNotas>10){
						printf("\n\tIngreso fuera de rango ");
					}
			
				}while(cantidadNotas<1 || cantidadNotas>10);
				
				for(int i=0;i<sizeNotas;i++){
					alumnos[item-1].notas[i]=0;
				}
		
				for(int i=0;i<cantidadNotas;i++){
					
					do{
			
						printf("\n\tIngrese nota  %d :  ",(i+1));
						scanf("%d",&nota);
				
					}while(nota<1||nota>10);
			
					alumnos[item-1].notas[i]=nota;

				}
				
			break;
			
		}
		
		updateAlumno();
	}while(escogerDatoAlumno!='4');
	printf("\n\t");
}


void eliminarAlumno(){
	char escogerAlumno;
	char escogerDatoAlumno='4';
	int item=0;
	printf("\n\tEliminar Alumno");
	for(int i=0;i<contadorAlumnos;i++){
		printf("\n\t %d \t %d - %s",(i+1),alumnos[i].numeroLegajo,alumnos[i].nombre);	
	}
	
	do{
		printf("\n\tSeleccione alumno a eliminar : ");
		printf("\n\t");
		scanf(" %c",&escogerAlumno);
		printf("\n\t Elegir: %c",escogerAlumno);
		if(isdigit(escogerAlumno)){
			item = (int)escogerAlumno - 48;
		}
		
		if(item<1 || item>contadorAlumnos){
			printf("\n\tDebe escoger a alumno dentro del rango ");
		}
	}while(item<1 || item>contadorAlumnos);	
	
	system("cls");
	for(int i=item-1;i<contadorAlumnos;i++){
		alumnos[i]=alumnos[i+1];
	}
	
	contadorAlumnos--;
	updateAlumno();
	printf("\n\tAlumno eliminado ");
	
}

/////////////////////***************Gestión estadísticas*****************/////////////////////////
void menuEstadistico(){
	char opcionMenuEstadisticos='4';
	do{
		system("cls");
		printf("\n\tMenú Datos Estadísticos");
		printf("\n\t1. Listado ordenado promedio notas ");
		printf("\n\t2. Cantidad alumnos 1 sóla nota ");
		printf("\n\t3. Alumno con mayor cantidad de 10s ");
		printf("\n\t4. Volver al menú principal");
		printf("\n\t");
		scanf("%c",&opcionMenuEstadisticos);				
		switch(opcionMenuEstadisticos){
			case '1':
				system("cls");
				listadoOrdenPorPromedio();
				getch();
			break;
			case '2':
				system("cls");
				cantidadUnaNota();
				getch();
			break;		
			case '3':
				system("cls");
				mayorCantidad10();
				getch();
			break;		
		}
	}while(opcionMenuEstadisticos!='4');
}

void listadoOrdenPorPromedio(){
	int cont=0,sumaNotas=0;
	for(int i=0;i<contadorAlumnos;i++){
		for(int j=0;j<sizeNotas;j++){
			sumaNotas+=alumnos[i].notas[j];
			if(alumnos[i].notas[j]!=0){
				cont++;
			}
			alumnos[i].promedioNotas=(float) sumaNotas/cont;
		}
			sumaNotas=0;
			cont=0;
	}
	
	alumno aux;
	for(int i=0; i<contadorAlumnos;i++){
		for(int j=i+1;j<contadorAlumnos;j++){
				if(alumnos[i].promedioNotas<alumnos[j].promedioNotas){
					aux=alumnos[i];
					alumnos[i]=alumnos[j];
					alumnos[j]=aux;
				}
				
		}
	}
	
	printf("\n\tListado Ordenado Promedio de Alumnos");
	for(int i=0;i<contadorAlumnos;i++){
		printf("\n\tNúmero Legajo: %d",alumnos[i].numeroLegajo);
		printf("\n\tNombre Alumno: %s",alumnos[i].nombre);
		printf("\n\tPromedio notas: %f",alumnos[i].promedioNotas);
		printf("\n\t_______________________");
		
	}
	printf("\n\n");
}

void cantidadUnaNota(){
	int cantNota=0,unaNota=0;
	for(int i=0;i<contadorAlumnos;i++){
		for(int j=0;j<sizeNotas;j++){
			if(alumnos[i].notas[j]!=0){
				cantNota++;
			}
			alumnos[i].cantidadNotas=cantNota;
			
		}
		cantNota=0;
	}
	
	for(int i=0;i<contadorAlumnos;i++){
		if(alumnos[i].cantidadNotas==1){
			unaNota++;
		}
	}
	printf("\n\tCantidad alumnos con una sóla nota: %d",unaNota);
	printf("\n");
}

void mayorCantidad10(){
	int cantNota10=0;
	for(int i=0;i<contadorAlumnos;i++){
		for(int j=0;j<sizeNotas;j++){
			if(alumnos[i].notas[j]==10){
				cantNota10++;
			}
			alumnos[i].mejor_10=cantNota10;
			
		}
	}	
	
	int indexMejor=0,mejor10=0;
	alumno aux;
	for(int i=0; i<contadorAlumnos;i++){
		if(mejor10<alumnos[i].mejor_10){
			mejor10=alumnos[i].mejor_10;
			indexMejor=i;
		}
	}
	
	printf("\n\tAlumno con máxima cantidad de notas 10 ");
	printf("\n\tNúmero Legajo: %d",alumnos[indexMejor].numeroLegajo);
	printf("\n\tNombre Alumno: %s",alumnos[indexMejor].nombre);
	printf("\n");	
}
