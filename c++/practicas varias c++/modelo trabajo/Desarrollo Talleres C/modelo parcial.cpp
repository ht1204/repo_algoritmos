/*En una fábrica se producen 10 productos distintos. Por cada producto se cuenta con un código de parte que consiste en un numero de 5 cifras, un nombre de producto que puede tener hasta 8 letras y un costo de producción por unidad.
Cada venta que se realiza, la fábrica  carga el código de parte, la cantidad vendida y el precio unitario del producto.
La carga de venta se termina al ingresar un producto con código 0.

Se pide:
  Cargar la base de datos inicial de los 10 productos.
  Permitir el ingreso de ventas con las características mencionadas arriba.
  Si el precio de venta unitario de un producto es menor a su costo imprimir un cartel con la siguiente consigna  "Venta del producto xxx por debajo del costo" donde xxx es el nombre del mismo.
  Al finalizar la carga determinar:
	Un listado ordenado alfabéticamente informando las cantidades vendidas de cada producto y su contribución neta a la fábrica( precio de venta - costo de producción)
	Listar, de existir, los códigos que fueron vendidos en alguna oportunidad por debajo del costo.
	Informar el código y nombre que más se vendió en cantidad y la que produjo menos ingreso*/

#include<stdio.h>
#include <string.h>
#define N 3   // en el enunciado son 10

void CARGA(int [],char[][9],float[],int );
int BUSQUEDA(int [],int,int);
void INFORMEBAJOCOSTO(int[],int[],int);
int MAXIMO (int[],int);
int MINIMO (float[],int);
void ORDEN(int[],int[],char[][9],float[],int);
void LISTAR(int[],int[],char[][9],float[],int);

main()
{
 int COD[N],CODPROD,POS,CANTV,CVXP[N]={0},F[N]={0},PMAX,PMIN;
 char DES[N][9];
 float COST[N],PU,G[N]={0};
 
 CARGA(COD,DES,COST,N);
 
 printf("\ningrese codigo de producto vendido (Finaliza con CERO)");
 scanf("%d",&CODPROD);
 while(CODPROD!=0)
 {
  POS=BUSQUEDA(COD,CODPROD,N);
  if(POS>=0)
   {
    printf("\ningrese cantidad vendida ");
    scanf("%d",&CANTV);
	printf("\ningrese precio unitario ");
	scanf("%f",&PU);
	
	if(PU<COST[POS]) 
	 {
	  printf("\n\n\tVENTA DEL PRODUCTO  %s POR DEBAJO DEL COSTO \n",DES[POS]);
	  F[POS]=1;
       }
     
     CVXP[POS]=CVXP[POS]+CANTV; //CVXP[POS]+=CANTV;
     G[POS]=G[POS]+CANTV*(PU-COST[POS]);
   
   }
  else
     printf("\nERROR CODIGO DE PRODUCTO");
   
  printf("\ningrese codigo de producto vendido (Finaliza con CERO)");
  scanf("%d",&CODPROD);
 }
 printf("\n--------------------------------------------------------------------------------------------\n");
 INFORMEBAJOCOSTO(COD,F,N);
 
 printf("\n--------------------------------------------------------------------------------------------\n");
 PMAX=MAXIMO(CVXP,N);
 
 printf("\n\n\ncodigo producto %d descripcion %s de mayor cantidad vendida ",COD[PMAX],DES[PMAX]);
 
 printf("\n--------------------------------------------------------------------------------------------\n");
 PMIN=MINIMO(G,N);
 
 printf("\n\n\ncodigo producto %d descripcion %s de menor ganancia ",COD[PMIN],DES[PMIN]);
 
 ORDEN(COD,CVXP,DES,G,N);
 printf("\n--------------------------------------------------------------------------------------------\n");
 LISTAR(COD,CVXP,DES,G,N);
  printf("\n--------------------------------------------------------------------------------------------\n\n");
}

void CARGA(int V1[],char M[][9],float V2[],int TAM)
{
 int I;
 printf("\n\ningreso de datos ");
 for (I=0;I<TAM;I++)
  {printf("\ningrese codigo del producto ");
   scanf("%d",&V1[I]);
   printf("\ningrese descripcion del producto ");
   fflush(stdin);
   gets(M[I]);
   printf("\ningrese costo del producto ");
   scanf("%f",&V2[I]);
  }
}


int BUSQUEDA(int V[],int DATO,int TAM)
{
 int POSI=-1,I=0;
 while(POSI==-1&&I<TAM)
   if(V[I]==DATO)
     POSI=I;
   else
    I++;
 return(POSI);
}


void INFORMEBAJOCOSTO(int V1[],int V2[],int TAM)
{
 int I, MARCA=0;
 printf("\n\n\ncodigo producto que se vendieron bajo costo ");
 for(I=0;I<TAM;I++)
  if(V2[I]!=0)
    {printf("\n %d",V1[I]);
     MARCA=1;
    }
   if(MARCA==0)
    printf("\n\t ningun productos se vendio para el costo "); 
}


int MAXIMO (int V[],int TAM)
{
 int I, PMAX = 0;
 for(I=0;I<TAM;I++)
  if(V[I]>V[PMAX])
    PMAX=I;
 return(PMAX);   
}


int MINIMO (float V[],int TAM)
{
 int I, PMIN =0;
 for(I=0;I<TAM;I++)
  if(V[I]<V[PMIN])
    PMIN=I;
 return(PMIN);   
}


void ORDEN(int V[],int V1[],char M[][9],float V2[],int TAM)
{
 int I,J,AUX1;
 char AUX2[9];
 float AUX3;
 for(I=0;I<TAM-1;I++)
   for(J=0;J<TAM-1-I;J++)
     if(strcmpi(M[J],M[J+1])>0)
      {
	   strcpy(AUX2,M[J]);
       strcpy(M[J],M[J+1]);
       strcpy(M[J+1],AUX2);
       
       AUX1=V[J];
       V[J]=V[J+1];
       V[J+1]=AUX1;
       
       AUX3=V2[J];
       V2[J]=V2[J+1];
       V2[J+1]=AUX3;
       
       AUX1=V1[J];
       V1[J]=V1[J+1];
       V1[J+1]=AUX1;
      } 
}


void LISTAR(int V[],int V1[],char M[][9],float V2[],int TAM)
{
 int I;
 printf("\n\n\n\n\tcodigo    Cantidad vendida    descripcion     Ganancia ");
 for(I=0;I<TAM;I++)
 printf("\n       %5d        %5d          %8s          %8.2f", V[I], V1[I], M[I], V2[I]);
}
