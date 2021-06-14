#include<stdio.h>
#include <string.h>
#define N 3 //Productos
#define M 4 //Piezas
#define cantChar 10 //Cantidad caracteres

void cargaProducto(int [][M],char [][cantChar], float [][M],int ,int, int);
void listadoProductosIngresados(int [][M],char [][cantChar], float [][M],int ,int, int);
bool verificaExistente(int [][M], int , int,int);
void calificacionPiezas(int [][M],int [][M], int, int);
void partesEvaluadas(int [][M], int,int);
void partesCalificacionPromedio(int [][M],int [][M], int, int);
void costoPiezasRechazadas(int [][M],int [][M],float [][M], int, int);
void piezaMasRechazada(int [][M],int [][M], int, int);


int main(){
	int numeroParte[N][M];
	int calificacion[N][M];
	char descripcion[N][cantChar];
	float costoProd[N][M];
	
	
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			numeroParte[i][j]=0;
			costoProd[i][j]=0;
			calificacion[i][j]=0;
		}
	}
	printf("\n\tIngreso de productos y piezas en sistema");
	cargaProducto(numeroParte,descripcion,costoProd,N,M,cantChar);
	printf("\n\n\t______________________________________");
	printf("\n\tListado productos y piezas ingresados");
	listadoProductosIngresados(numeroParte,descripcion,costoProd,N,M,cantChar);
	printf("\n\n\t______________________________________");
	printf("\n\tClasificacion de piezas");
	calificacionPiezas(numeroParte,calificacion,N,M);
	printf("\n\n\t______________________________________");
	printf("\n\tPiezas sujetas a evaluacion ");
	partesEvaluadas(numeroParte,N,M);
	printf("\n\n\t______________________________________");
	printf("\n\tPromedio clasificacion Producto-Piezas");
	partesCalificacionPromedio(numeroParte,calificacion,N,M);
	printf("\n\n\t______________________________________");
	printf("\n\tCosto de piezas rechazadas");
	costoPiezasRechazadas(numeroParte,calificacion,costoProd,N,M);
	printf("\n\n\t______________________________________");
	printf("\n\tProducto-Pieza mas rechazada (peor evaluada)");
	piezaMasRechazada(numeroParte,calificacion,N,M);
	return 0;
} 

bool verificaExistente(int numeroParte[][M], int numero, int row,int column){
	bool existe=false;
 	
 	for(int j=0;j<column;j++){
 		if(numeroParte[row][j]==numero){
 			existe=true;
 			break;
		 }
	 }
	
	return existe;
}


void cargaProducto(int numeroParte[][M],char desc[][cantChar], float costoProd[][M],int size,int column,int chatSize){
	int i,j;
	int numParte;
	printf("\n\nIngreso de datos ");
	for(i=0;i<size;i++){
		
		do{
			printf("\nIngrese descripcion del producto  %d : ", (i+1));
	   		fflush(stdin);
	   		gets(desc[i]);
		}while(strlen(desc[i])<5 ||strlen(desc[i])>chatSize);
			
		for(j=0;j<column;j++){
			
			printf("\nProducto : %d ",(i+1));
			
			do{
				printf("\nIngrese Numero de parte : ");
				scanf("%d",&numParte);
			}while(verificaExistente(numeroParte,numParte,i,j) || numParte>column);
			
			if(numParte>=0){
				
				numeroParte[i][j]=numParte;
				
				do{
					printf("\nIngrese Costo Produccion : S/ ");
					scanf("%f",&costoProd[i][j]);
				}while(costoProd[i][j]<1);
					
			}else{
				j=column;
			}
					
		}

	}
	
}

void listadoProductosIngresados(int numeroParte[][M],char desc[][cantChar], float costoProd[][M],int size,int column,int chatSize){
	
	for(int i=0;i<size;i++){
		
		printf("\n\tProducto : %d  ",(i+1));
		printf("\n\tDescripcion Producto :  %s ",desc[i]);
		
		for(int j=0;j<column;j++){
			
			if(numeroParte[i][j]!=0){
				printf("\n\tIngrese Numero de parte : %d ",numeroParte[i][j]);
				printf("\n\tCosto Produccion Numero de parte : S/ %.2f ",costoProd[i][j]);
				printf("\n");
			}	
			
		}
		printf("\n\t-----------------------");
	}
	
}

void calificacionPiezas(int numeroParte[][M],int calificacion[][M], int size,int column){
	int i,j;
	
	for(i=0;i<size;i++){
		for(j=0;j<column;j++){
			if(numeroParte[i][j]!=0){
				do{
					printf("\n\t Ingrese calificacion de producto %d - No Parte %d : ",(i+1),numeroParte[i][j]);
					scanf("%d",&calificacion[i][j]);
				}while(calificacion[i][j]<0 || calificacion[i][j]>10);
			}
		}
		
	}
	
}

void partesEvaluadas(int numeroPartes[][M],int size, int column){
	int i,j;
	for(i=0;i<size;i++){

		printf("\n\tProducto %d  ",(i+1));

		for(j=0;j<column;j++){
			if(numeroPartes[i][j]!=0){
				
				printf("\n\tNo Parte : %d ",numeroPartes[i][j]);
			}
			
		}
		printf("\n");
	}
	printf("\n\t------------------------------------------");
	printf("\n\tPiezas no sujetas a evaluacion ");
	
	for(i=0;i<size;i++){

		printf("\n\tProducto %d  ",(i+1));

		for(j=0;j<column;j++){
			if(numeroPartes[i][j]==0){
				printf("\n\tNo Parte : %d ",j);
			}
			
		}
		printf("\n");
	}	
}

void partesCalificacionPromedio(int numeroPartes[][M], int calificacion[][M],int size,int column){
	int i,j,contCal=0;
	float calProm=0.0,sumaCalificacion=0.0;
	for(i=0;i<size;i++){
		printf("\n\tProducto %d  ",(i+1));
		for(j=0;j<column;j++){
			if(numeroPartes[i][j]!=0){
				sumaCalificacion+=calificacion[i][j];
				contCal++;
			}
			
		}
		calProm=sumaCalificacion/contCal;
		printf("\n\t Promedio Calificacion : %.2f ",calProm);
		printf("\n");
		sumaCalificacion=contCal=0;
	}
	
}

void costoPiezasRechazadas(int numeroPartes[][M],int calificacion[][M],float costoProd[][M], int size,int column){
	int i,j;
	float costoTotalRechazadas=0.0;
	for(i=0;i<size;i++){
	for(j=0;j<column;j++){
			if(numeroPartes[i][j]!=0){
				if(calificacion[i][j]<=7){
					costoTotalRechazadas+=costoProd[i][j];
				}
			}
			
		}
	}
		printf("\n\t Costo total rechazadas : S/ %.2f ",costoTotalRechazadas);
		printf("\n");	
}

void piezaMasRechazada(int numeroPartes[][M], int calificacion[][M],int size, int column){
	int i,j;
	int contRechazadas=0;
	int productoRechazado[size];
	

	for(i=0;i<size;i++){
		for(j=0;j<column;j++){
			if((calificacion[i][j]!=0) &&(calificacion[i][j]<=7)){
				contRechazadas++;
			}	
		}
		productoRechazado[i]=contRechazadas;
		contRechazadas=0;
	}

	int masRechazada=productoRechazado[0];
	int index=0;
	for(i=1;i<size;i++){
		if(masRechazada<productoRechazado[i]){
			masRechazada=productoRechazado[i];
			index=i;
		}
	}
	
	for(int x=0;x<size;x++){
		printf("\n\t Cantidad piezas rechazadas Prod. %d  : %d ",(x+1),productoRechazado[x]);
	}
	
	printf("\n");
	printf("\n\t Producto con Piezas Mas rechazadas : Prod. %d ",index+1);
	
	int peorCalificacion=calificacion[index][0];
	int indexPeor=0;
	
	for(j=1;j<column;j++){
		
		if((calificacion[index][j]!=0) && (peorCalificacion > calificacion[index][j])){
			peorCalificacion=calificacion[index][j];
			indexPeor=j;
		}
		
	}	
	
	printf("\n\t Pieza Peor Calificada : Pieza %d ",numeroPartes[index][indexPeor]);
	printf("\n\t Peor Calificacion : %d ",calificacion[index][indexPeor]);
	
}
