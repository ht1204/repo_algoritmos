//Librerías que permiten cargar recursos necesarios para el programa

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include <ctime>
#include <cstdlib>
#include <wchar.h>
#include <locale.h>


#define N 10000 //capacidad de almacenamiento de productos.

//estructura que contiene los datos de producto, se utiliza un arreglo para manejar datos en memoria.
struct producto{
	int numeroRadicado;
	char nombreProducto['w'];
	int precio;
	int cantidadExistencias;
}stock[N];

int contador=0;//contador general de productos

/*Funciones de menú */
void menu();
void menuGestionProducto();
void menuDatosEstadisticos();
/**********************/


/*Funciones para gestión de productos */
int generadorRadicado();
void agregarProducto();
void consultarProducto();
void editarProducto();
void eliminarProducto();
void listarProductos();
/**********************/

/*Funciones para datos estadísticos de productos en inventario */
void menorExistencias();
void mayorExistencias();
void menorPrecio();
void mayorPrecio();
void promedioExistencias();
void promedioPrecio();
/**********************/


int main(){
	setlocale(LC_ALL, "");
	menu();
	printf("\n\n");
	system("pause");
	printf("\n\n");
	return 0;
}

void menu(){
	char opcionMenu='3';
	do{
		system("cls");
		printf("\n\tMenú Principal");
		printf("\n\t1.Gestión de productos");
		printf("\n\t2.Datos estadísticos");
		printf("\n\t3.Salir");
		printf("\n\t");
		scanf("%c",&opcionMenu);
		switch(opcionMenu){
			case '1':
				system("cls");
				menuGestionProducto();
			break;
				
			case '2':
				system("cls");
				if(contador>0){
					menuDatosEstadisticos();
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


///////////////*********Gestión de productos*************/////////////////
void menuGestionProducto(){
	char opcionMenuGestion='6';
	do{
		system("cls");
		printf("\n\tMenú Gestión de productos");
		printf("\n\t1.Agregar Producto");
		printf("\n\t2.Consultar Producto");
		printf("\n\t3.Editar Producto");
		printf("\n\t4.Eliminar Producto");
		printf("\n\t5.Listar Productos");
		printf("\n\t6.Volver a menú principal");
		printf("\n\t");
		scanf("%c",&opcionMenuGestion);
		switch(opcionMenuGestion){
			case '1':
				system("cls");
				agregarProducto();
			break;
				
			case '2':
				system("cls");
				if(contador>0){
					consultarProducto();
				}else{
					printf("\n\tNo existen productos registrados");
				}
				printf("\n\n");
				system("pause");
				
			break;
			
			case '3':
				system("cls");
				if(contador>0){
					editarProducto();
				}else{
					printf("\n\tNo existen productos registrados");
				}
				printf("\n\n");
				system("pause");
			break;
			
			case '4':
				system("cls");
				if(contador>0){
					eliminarProducto();
				}else{
					printf("\n\tNo existen productos registrados");
				}
				printf("\n\n");
				system("pause");
			break;	
			
			case '5':
				system("cls");
				if(contador>0){
					listarProductos();
				}else{
					printf("\n\tNo existen productos registrados");
				}
				printf("\n\n");
				system("pause");
			break;
			
		}
	
	}while(opcionMenuGestion!='6');
	
}


int generadorRadicado(){
	srand(time(NULL));
	int radicado=(rand() % N) + 1;
	return radicado;
}


void agregarProducto(){
	int precioProducto, existencias;
	if(contador<N){
		stock[contador].numeroRadicado=generadorRadicado();
		printf("\n\tNúmero Radicado: %d",stock[contador].numeroRadicado);
	
		printf("\n\tIngrese nombre de producto: ");
		fflush(stdin);
		gets(stock[contador].nombreProducto);
			
		do{
			printf("\n\tIngrese precio de producto (S/): ");
			scanf("%d",&precioProducto);
			
			if(precioProducto<500){
				printf("\n\tEl precio de venta debe ser superior a S/ 500 ");
			}
		}while(precioProducto<500);
		stock[contador].precio=precioProducto;
		
		do{
			printf("\n\tIngrese cantidad de existencias : ");
			scanf("%d",&existencias);
			
			if(existencias<1){
				printf("\n\tDebe haber al menos un (1) producto en stock ");
			}
		}while(existencias<1);
		stock[contador].cantidadExistencias=existencias;
		
		printf("\n\tProducto Registrado!");	
		contador++;	
	}else{
		printf("\n\tLímite de productos en memoria alcanzado :(");
	}
	
	printf("\n\n");
	system("pause");
}

void consultarProducto(){
	char escogerProducto;
	int item;
	
	printf("\n\tConsultar Producto");
	for(int i=0;i<contador;i++){
		printf("\n\t %d \t %d - %s",(i+1),stock[i].numeroRadicado,stock[i].nombreProducto);
	//	cout<<"\n\t"<<i+1<<" "<<stock[i].numeroRadicado<<" - "<<stock[i].nombreProducto;		
	}
	
	do{
		printf("\n\tIngrese posición producto a consultar : ");
		printf("\n\t");
		scanf(" %c",&escogerProducto);
		printf("\n\t Elegir: %c",escogerProducto);
		if(isdigit(escogerProducto)){
			item = (int)escogerProducto - 48;
		}
		
		if(item<1 || item>contador){
			printf("\n\tDebe haber escoger producto dentro de listado ");
		}
	}while(item<1 || item>contador);
	
	system("cls");
	printf("\n\tNúmero Radicado: %d",stock[item-1].numeroRadicado);
	printf("\n\tNombre Producto: %s",stock[item-1].nombreProducto);
	printf("\n\tPrecio Producto: S/ %d ",stock[item-1].precio);
	printf("\n\tCantidad Existencias: %d",stock[item-1].cantidadExistencias);
	printf("\n\n");
	
}

void editarProducto(){
	char escogerProducto;
	char escogerDato='4';
	
	int item;
	int precioProducto, existencias;
	printf("\n\tConsultar Producto");
	for(int i=0;i<contador;i++){
		printf("\n\t %d \t %d - %s",(i+1),stock[i].numeroRadicado,stock[i].nombreProducto);
	//	cout<<"\n\t"<<i+1<<" "<<stock[i].numeroRadicado<<" - "<<stock[i].nombreProducto;		
	}
	
	do{
		printf("\n\tIngrese posición producto a consultar : ");
		printf("\n\t");
		scanf(" %c",&escogerProducto);
		
		if(isdigit(escogerProducto)){
			item = (int)escogerProducto - 48;
		}
		
		if(item<1 || item>contador){
			printf("\n\tDebe haber escoger producto dentro de listado ");
		}
	}while(item<1 || item>contador);
	

	
	
	do{
		system("cls");
		printf("\n\tSeleccione dato a editar");
		printf("\n\tNúmero Radicado: %d",stock[item-1].numeroRadicado);
		printf("\n\t1.Nombre Producto");
		printf("\n\t2.Precio Producto");
		printf("\n\t3.Cantidad en Existencias");
		printf("\n\t4.Salir");
		printf("\n\t");
		scanf("%c",&escogerDato);
		switch(escogerDato){
			case '1':
				printf("\n\tIngrese nombre de producto: ");
				fflush(stdin);
				gets(stock[item-1].nombreProducto);
				break;
			case '2':
				do{
					printf("\n\tIngrese precio de producto (S/): ");
					scanf("%d",&precioProducto);
			
					if(precioProducto<500){
						printf("\n\tEl precio de venta debe ser superior a S/ 500 ");
					}
				}while(precioProducto<500);
				stock[item-1].precio=precioProducto;
				break;
			case '3':
				do{
					printf("\n\tIngrese cantidad de existencias : ");
					scanf("%d",&existencias);
			
					if(existencias<1){
						printf("\n\tDebe haber al menos un (1) producto en stock ");
					}
				}while(existencias<1);
				stock[item-1].cantidadExistencias=existencias;
				break;
		}
		
	}while(escogerDato!='4');	
	printf("\n\n");		
}

void eliminarProducto(){
	char escogerProducto;
	int item=0;
	
	printf("\n\tConsultar Producto");
	for(int i=0;i<contador;i++){
		printf("\n\t %d \t %d - %s",(i+1),stock[i].numeroRadicado,stock[i].nombreProducto);
		//cout<<"\n\t"<<i+1<<" "<<stock[i].numeroRadicado<<" - "<<stock[i].nombreProducto;		
	}
	
	do{
		printf("\n\tIngrese posición producto a eliminar : ");
		printf("\n\t");
		scanf(" %c",&escogerProducto);
		if(isdigit(escogerProducto)){
			item = (int)escogerProducto - 48;
		}
		if(item<1 || item>contador){
			printf("\n\tDebe haber escoger producto dentro de listado ");
		}
	}while(item<1 || item>contador);
	
	system("cls");
	for(int i=item-1;i<contador;i++){
		stock[i]=stock[i+1];
	}
	contador--;
	printf("\n\tProducto eliminado ");
}

void listarProductos(){
	printf("\n\tListado de Productos");
	for(int i=0;i<contador;i++){
		printf("\n\tNúmero Radicado: %d",stock[i].numeroRadicado);
		printf("\n\tNombre Producto: %s",stock[i].nombreProducto);
		printf("\n\tPrecio Producto: S/ %d ",stock[i].precio);
		printf("\n\tCantidad Existencias: %d",stock[i].cantidadExistencias);
		printf("\n\t_______________________");
		
	}
	printf("\n\n");

}



///////////////*********Datos Estadísticos-administrativos*************/////////////////
void menuDatosEstadisticos(){
		char opcionMenuEstadisticos='6';
	do{
		system("cls");
		printf("\n\tMenú Datos Estadísticos");
		printf("\n\t1.Producto en menor cantidad");
		printf("\n\t2.Producto en mayor cantidad");
		printf("\n\t3.Producto con menor precio");
		printf("\n\t4.Producto con mayor precio");
		printf("\n\t5.Promedio de cantidades en existencias general");
		printf("\n\t6.Promedio de precios en general");
		printf("\n\t7. Volver al menú principal");
		printf("\n\t");
		scanf("%c",&opcionMenuEstadisticos);
		switch(opcionMenuEstadisticos){
			case '1':
				system("cls");
				menorExistencias();
				system("pause");
			break;
				
			case '2':
				system("cls");
				mayorExistencias();
				system("pause");
				
			break;
			
			case '3':
				system("cls");
				menorPrecio();
				system("pause");
			break;
			
			case '4':
				system("cls");
				mayorPrecio();
				system("pause");			
			break;	
			
			case '5':
				system("cls");
				promedioExistencias();
				system("pause");
			break;
			
			case '6':
				system("cls");
				promedioPrecio();
				system("pause");
			break;
			
		}
	
	}while(opcionMenuEstadisticos!='7');
	
		
}

void menorExistencias(){
	int menorExistencia=stock[0].cantidadExistencias;
	int posicionMenor=0;
	for(int i=1;i<contador;i++){
		if(stock[i].cantidadExistencias<menorExistencia){
			menorExistencia=stock[i].cantidadExistencias;
			posicionMenor=i;
		}
		
	}
	
	printf("\n\tProducto menor existencias: %d - %s",stock[posicionMenor].numeroRadicado, stock[posicionMenor].nombreProducto);
	printf("\n\tExistencias en inventario: %d ",stock[posicionMenor].cantidadExistencias);
	printf("\n\n");
	
}

void mayorExistencias(){
	int mayorExistencia=stock[0].cantidadExistencias;
	int posicionMayor=0;
	for(int i=1;i<contador;i++){
		if(stock[i].cantidadExistencias>mayorExistencia){
			mayorExistencia=stock[i].cantidadExistencias;
			posicionMayor=i;
		}
		
	}
	
	printf("\n\tProducto mayor existencias:  %d - %s ",stock[posicionMayor].numeroRadicado, stock[posicionMayor].nombreProducto);
	printf("\n\tExistencias en inventario:  %d ",stock[posicionMayor].cantidadExistencias);
	printf("\n\n");
}


void menorPrecio(){
	int menorPrecio=stock[0].precio;
	int posicionMenor=0;
	for(int i=1;i<contador;i++){
		if(stock[i].precio<menorPrecio){
			menorPrecio=stock[i].precio;
			posicionMenor=i;
		}
		
	}
	
	printf("\n\tProducto menor precio: %d - %s",stock[posicionMenor].numeroRadicado, stock[posicionMenor].nombreProducto);
	printf("\n\tPrecio: S/ %d",stock[posicionMenor].precio);
	printf("\n\n");
	
	
}




void mayorPrecio(){
	int mayorPrecio=stock[0].precio;
	int posicionMayor=0;
	for(int i=1;i<contador;i++){
		if(stock[i].precio>mayorPrecio){
			mayorPrecio=stock[i].precio;
			posicionMayor=i;
		}
		
	}
	
	printf("\n\tProducto mayor precio: %d - %s",stock[posicionMayor].numeroRadicado, stock[posicionMayor].nombreProducto);
	printf("\n\tPrecio: S/ %d",stock[posicionMayor].precio);;
	printf("\n\n");
}


void promedioExistencias(){
	int sumaExistencias=0;
	for(int i=0;i<contador;i++){
		sumaExistencias+=stock[i].cantidadExistencias;
	}
	int promedioExistenciaGeneral=sumaExistencias/contador;
	printf("\n\tPromedio existencias en general: %d",promedioExistenciaGeneral);
	printf("\n\n");
}


void promedioPrecio(){
	int sumaPrecios=0;
	for(int i=0;i<contador;i++){
		sumaPrecios+=stock[i].precio;
	}
	int promedioPrecioGeneral=sumaPrecios/contador;
	printf("\n\tPromedio precios en general: S/ %d",promedioPrecioGeneral);
	printf("\n\n");
}








