#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 2
#define M 2

void INGRESO_PARTICIPANTE(int [], float [][M],float [][M], int, int);
bool verificaParticipanteExistente(int [], int , int);
bool verificaRangoIdParticipante(int );
void CUADRANTE(int [], float [][M],float [][M], int [][M], int, int);
void PUNTAJE(int [],int [][M],int [][M], int, int);
void IMPRIMIR_PUNTAJE_PARTICIPANTE(int [], int[],int[],int [][M],int [][M], int, int);
void IMPRIMIR_PARTICIPANTE_GANADOR(int [],int [],int);
void IMPRIMIR_DISPAROS_CENTRO(int [],int [],int);

void setTitle(){
	system("title Sistema Tiro al Blanco");
}

int main(){
	setTitle();
	int participante[N];
	float coordDisparoX[N][M];
	float coordDisparoY[N][M];
	int cuadrante[N][M];
	int puntaje[N][M];
	int puntajeTotalParticipante[N];
	int disparosCentroParticipante[N];
	
	for(int i=0;i<N;i++){
		participante[i]=-1;
		puntajeTotalParticipante[i]=0;
		disparosCentroParticipante[i]=0;
		for(int j=0;j<M;j++){
			coordDisparoX[i][j]=coordDisparoY[i][j]=0;
			cuadrante[i][j]=0;
			puntaje[i][j]=0;
		}
	}
	
	printf("\nIngreso de participantes ");
	INGRESO_PARTICIPANTE(participante,coordDisparoX,coordDisparoY,N,M);
	printf("\n\n\t______________________________________");
	printf("\nIngreso de coordenadas de disparos ");
	CUADRANTE(participante,coordDisparoX,coordDisparoY,cuadrante,N, M);
	printf("\n\n\t______________________________________");
	PUNTAJE(participante,puntaje,cuadrante,N,M);
	printf("\n\n\t______________________________________");
	printf("\nPuntajes obtenidos de participantes ");
	IMPRIMIR_PUNTAJE_PARTICIPANTE(participante,puntajeTotalParticipante,disparosCentroParticipante, puntaje,cuadrante,N,M);
	printf("\n\n\t______________________________________");
	printf("\nParticipante ganador ");
	IMPRIMIR_PARTICIPANTE_GANADOR(participante,puntajeTotalParticipante,N);
	printf("\n\n\t______________________________________");
	printf("\nDisparos efectuados al centro por participante ");
	IMPRIMIR_DISPAROS_CENTRO(participante,disparosCentroParticipante,N);
	printf("\n\n\t______________________________________");
	
	return 0;
}

bool verificaParticipanteExistente(int participante[], int idParticipante, int counter){
	int i;
	bool existe=false;
	
	for(i=0;i<counter;i++){
		if(participante[i]==idParticipante){
			existe=true;
		}else{
			existe=false;
		}
	}
	
	return existe;
	
}

bool verificaRangoIdParticipante(int idParticipante){
	bool rangeFlag=false;
	
	if(idParticipante>10000){
		rangeFlag=true;
	}else{
		rangeFlag=false;
	}
	
	return rangeFlag;
}



void INGRESO_PARTICIPANTE(int participante[], float coordDisparoX[][M],float coordDisparoY[][M],int cantParticipantes, int cantDisparos){
	int i,j;
	int idParticipante=0;
	for(i=0;i<cantParticipantes;i++){
		
		do{
			printf("\nIngrese Id del participante  %d : ", (i+1));
			scanf("%d",&idParticipante);
			
			
		}while(verificaParticipanteExistente(participante,idParticipante,i) || verificaRangoIdParticipante(idParticipante));
		
		if(idParticipante>-1){
			participante[i]=idParticipante;	
			
			for(j=0;j<cantDisparos;j++){
				
				printf("\nDisparo No  %d ", (j+1));
				do{
					printf("\nIngrese disparo coordenada X participante  %d : ", (i+1));
					scanf("%f",&coordDisparoX[i][j]);
				}while(coordDisparoX[i][j]<-7 || coordDisparoX[i][j]>7);
				
				do{
					printf("\nIngrese disparo coordenada Y participante  %d : ", (i+1));
					scanf("%f",&coordDisparoY[i][j]);
				}while(coordDisparoY[i][j]<-7 || coordDisparoY[i][j]>7);				
			}
			
		}else{
			i=cantParticipantes;
		}
	
	}

}

void CUADRANTE(int participante[], float coordDisparoX[][M],float coordDisparoY[][M],int cuadrante[][M],int cantParticipantes, int cantDisparos){
	
	int i,j;	
	
	for(i=0;i<cantParticipantes;i++){
		
		if(participante[i]>-1){
			
			for(j=0;j<cantDisparos;j++){
				
				if(coordDisparoX[i][j]>0 && coordDisparoY[i][j]>0){
					cuadrante[i][j]=1;
				}else if(coordDisparoX[i][j]<0 && coordDisparoY[i][j]>0){
					cuadrante[i][j]=2;
				}else if(coordDisparoX[i][j]<0 && coordDisparoY[i][j]<0){
					cuadrante[i][j]=3;
				}else if(coordDisparoX[i][j]>0 && coordDisparoY[i][j]<0){
					cuadrante[i][j]=4;
				}else if (coordDisparoX[i][j]==0 && coordDisparoY[i][j]==0){
					cuadrante[i][j]=5;
				}
				
			}
			
		}
		
	}
	
}

void PUNTAJE(int participante[],int puntaje[][M] ,int cuadrante[][M],int cantParticipantes, int cantDisparos){
	
	int i,j;
	
	for(i=0;i<cantParticipantes;i++){
		
		if(participante[i]>-1){
			
			for(j=0;j<cantDisparos;j++){
				if(cuadrante[i][j]==1 || cuadrante[i][j]==2){
					puntaje[i][j]=50;
				}else if(cuadrante[i][j]==3 || cuadrante[i][j]==4){
					puntaje[i][j]=40;
				}else if(cuadrante[i][j]==5){
					puntaje[i][j]=100;
				}else{
					puntaje[i][j]=0;
				}

			}
			
		}
		
	}	
	
}

void IMPRIMIR_PUNTAJE_PARTICIPANTE(int participante[],int puntajeTotalParticipante[],int disparosCentroParticipante[],int puntaje[][M],
int cuadrante[][M],int cantParticipantes, int cantDisparos){
	int i,j;
	int contCuadrante1=0,contCuadrante2=0,contCuadrante3=0,contCuadrante4=0,contCentro=0;
	int sumaPuntaje=0;
	for(i=0;i<cantParticipantes;i++){
		
		
		
		if(participante[i]>-1){
			
			printf("\n\tParticipante No %d : ",(i+1));
			printf("\n\tId : %d  ",participante[i]);
			
			puntajeTotalParticipante[i]=0;
			
			for(j=0;j<cantDisparos;j++){
				
				if(cuadrante[i][j]==1){
					contCuadrante1++;
				} else if (cuadrante[i][j]==2){
					contCuadrante2++;
				}else if (cuadrante[i][j]==3){
					contCuadrante3++;
				}else if (cuadrante[i][j]==4){
					contCuadrante4++;
				}else if (cuadrante[i][j]==5){
					contCentro++;
				}
				
				sumaPuntaje+=puntaje[i][j];

			}
			puntajeTotalParticipante[i]=sumaPuntaje;
			sumaPuntaje=0;
			printf("\n\tPuntaje Total : %d  ",puntajeTotalParticipante[i]);
			printf("\n\t ");
			printf("\n\tDisparos en cuadrante 1 : %d  ",contCuadrante1);
			printf("\n\tDisparos en cuadrante 2 : %d  ",contCuadrante2);
			printf("\n\tDisparos en cuadrante 3 : %d  ",contCuadrante3);
			printf("\n\tDisparos en cuadrante 4 : %d  ",contCuadrante4);
			printf("\n\tDisparos en centro : %d  ",contCentro);
			printf("\n\t ");
			printf("\n\t ");
			disparosCentroParticipante[i]=contCentro;
			contCuadrante1=contCuadrante2=contCuadrante3=contCuadrante4=contCentro=0;
		}
		
	}	
	
}

void IMPRIMIR_PARTICIPANTE_GANADOR(int participante[],int puntajeTotalParticipante[],int cantParticipantes){
	int i;
	int mayor=participante[0];
	int indexMayor=0;
	
	for(i=1;i<cantParticipantes;i++){
		if(mayor<puntajeTotalParticipante[i]){
			mayor=puntajeTotalParticipante[i];
			indexMayor=i;
		}
	}
	printf("\n\tParticipante Ganador : %d  ",participante[indexMayor]);
	printf("\n\tPuntaje Ganador : %d  ", puntajeTotalParticipante[indexMayor]);
	
}

void IMPRIMIR_DISPAROS_CENTRO(int participante[],int disparosCentroParticipante[],int cantParticipantes){
	int i;
	
	for(i=0;i<cantParticipantes;i++){
		if(participante[i]>-1){
			printf("\n\tParticipante No : %d | Id: %d ",(i+1),participante[i]);
			printf("\n\tCantidad disparos centro: %d",disparosCentroParticipante[i]);
			printf("\n\t_____________________________________________");
		}
	}
}

