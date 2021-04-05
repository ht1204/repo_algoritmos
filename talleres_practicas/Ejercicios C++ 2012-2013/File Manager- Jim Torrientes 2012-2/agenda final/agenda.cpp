#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fstream.h>


struct persona{
       char nombre['w'];
       char apellido['w'];
       int num;
       }per[50];
       
int i=0;


void menu();
void registrar();
void modificar();
void eliminar();
void listar();
int validanumero(int numero);
void persistencia();
void cargar();
void borrar();
void goodbye();

void cargatodo(){
    system("cls");
    system("title Agenda telefonica ");
    cargar();
    menu();
    goodbye();
    getch();
     }

int main(){
    cargatodo();
    return 0;
    }       
       
void menu(){
     int op;
     do{
     system("cls");
     cout<<"\n\tMenu agenda ";         
     cout<<"\n\t1.Registrar ";
     cout<<"\n\t2.Modificar ";
     cout<<"\n\t3.Listar ";
     cout<<"\n\t4.Eliminar ";
     cout<<"\n\t5.Salir \n\t";
     cin>>op;
     switch(op){
     case 1:
          registrar();
          break;
      case 2:
           modificar();
          break;
      case 3:
           listar();
           break;
      case 4:
           eliminar();
          break;
                 
      }
     }while(op!=5);
          getch();
     }

void registrar(){
     system("cls");
     if(i<50){
          fflush(stdin);    
         cout<<"\n\tIngrese nombre : ";
         gets(per[i].nombre);
         
         fflush(stdin);
         cout<<"\n\tIngrese apellido : ";     
         gets(per[i].apellido);
         
         do{
         cout<<"\n\tIngrese numero telefonico : ";
         cin>>per[i].num;
         }while(per[i].num<100||per[i].num>1000000);
          
           i++;
	  borrar();//borramos archivo de registros anteriores 
      persistencia(); //creamos archivo con todos los registros anteriores hasta el último agregado al usar esta función
          
     }else{
     cout<<"\n\t Límite de memoria ";      
     }
	    
     }
   
void modificar(){
     system("cls");
     if(i!=0){
     int num1;
     int op;
     int pos;
     int numero;
     int band=0;
     cout<<"\n\tIngrese numero de celular para modificar registro ";
     cin>>num1;
     
     for(int y=0;y<i;y++){
         if(per[y].num==num1){ 
          pos=y;   
            do{
                   system("cls");
              cout<<"\n\tMenú modificar ";            
              cout<<"\n\t1.Nombre "<<per[pos].nombre;
              cout<<"\n\t2.Apellido "<<per[pos].apellido;
              cout<<"\n\t3.Numero telefonico "<<per[pos].num;
              cout<<"\n\t4.Salir \n\t";
              cin>>op;
              switch(op){
              case 1:
                   fflush(stdin);
                   cout<<"\n\tIngrese nuevo nombre : ";
                   gets(per[pos].nombre);
                   break;           
              case 2:
                   fflush(stdin);
                   cout<<"\n\tIngrese nuevo apellido : ";
                   gets(per[pos].apellido);
                   break;
              case 3:
                   do{
                   cout<<"\n\tIngrese nuevo numero telefonico : ";
                   cin>>numero;
                   }while((validanumero(numero)==1)||(numero<100||numero>1000000));          
                   per[pos].num=numero;
                   break;
              
              }
            }while(op!=4); 
            band=0;
            break;
            }else{
              band=1;    
            }
             }
             if(band==0){//en caso de encontrar
               borrar();//borra archivo de registros anteriores
                persistencia(); //crea archivo con registros nuevos               
             }else{
             cout<<"\n\tNo hay coincidencias  ";
             }
				
             
}else{
      cout<<"\n\tNo hay registros ";
      }
     getch();
     }
	 
	 
	 
	 void eliminar(){
          system("cls");
          if(i!=0){
          int num1;
          int pos;
          bool b=false;
          cout<<"\n\tIngrese numero de celular para modificar registro :  ";
          cin>>num1;          
          for(int y=0;y<i;y++){
                  if(per[y].num==num1){//si encuentra captura posición del dato y rompe el ciclo
                  pos=y;
                  b=true;
                  break;                    
                  }
                  }
         if(b==true){
                  for(int u=pos;u<i;u++){//recorre desde posición del dato a borrar hasta el final
                          per[u]=per[u+1];//sobreescribe esa posición de dato con la siguiente
                          }
                          i--; //decrementamos iterador principal para poder guardar en última posición de vector
						  borrar();//borramos el archivo de registros anteriores
                          persistencia(); //creamos el archivo con registros nuevos
                     cout<<"\n\tRegistro eliminado  ";                                 
                  }else{
                     cout<<"\n\tNo hay coincidencias ";      
                     }  
                    
                     }else{
                     cout<<"\n\tNo hay registros ";      
                     }       
                     
                   getch();       
     } 
	 
	 

void listar(){
          system("cls");
          if(i!=0){
          cout<<"\n\tListado general \n\n__________________";
          for(int y=0;y<i;y++){
                  cout<<"\n\tNombre : "<<per[y].nombre;
                  cout<<"\n\tApellido : "<<per[y].apellido;
                  cout<<"\n\tNumero telefonico : "<<per[y].num;
                  cout<<"\n______________________";
                  }
                  

                  }else{
                   cout<<"\n\tNo hay registros "; 
                   }       
                      
               getch();
     }       
     

	 
	 
int validanumero(int numero){
     
     for(int y=0;y<i;y++){
             if(per[y].num==numero){
                  return 1;
                  break;               
             }
            }
             
     return 0;
     
     }	 
	 
	 
	 
void goodbye(){
     system("cls");
     cout<<"\n\tGracias por usar este aplicativo, que estes bien !!";
     }
	 
	 
void cargar(){
ifstream f;
persona p;// variable de tipo struct persona auxiliar usada para transferir datos de archivo hasta el vector
f.open("persistencia.txt");//busca archivo 
    if(f.bad()){//en caso de ausencia de archivo
       cout<<"\n\tError en archivo  ";            
       getch();
    }else{//si hay archivo 
          i=-1;//hacemos el iterador principal i=-1 para que no hayan registros duplicados en la última casilla
       while(!f.eof()){
             i++;//partimos desde la primera posición per[0] para empezar a cargar
            f>>p.nombre>>p.apellido>>p.num;//captura datos de archivo a variable auxiliar para transferir a vector
            strcpy(per[i].nombre,p.nombre);//capturando nombre
            strcpy(per[i].apellido,p.apellido);//capturando apellido
            per[i].num=p.num;//capturando número telefónico
        
        }      

   }
        f.close();//cierra proceso de lectura de archivo
        cout<<"\n\tHola!!, esta es su agenda telefonica,\n\tpresione enter para acceder a las funcionalidades\n\t ";
    	getch();

}

	 
void persistencia(){
 ofstream salida("persistencia.txt");//el sistema entra al archivo 
    
    if(salida == 0)//si no hay archivo, lo indica
    {
       cout << "ERROR AL ABRIR EL ARCHIVO.";
       getch();
    }
    for(int y=0;y<i;y++){//carga contenido de vector en archivo 
       salida << per[y].nombre <<"\t"<<per[y].apellido<<"\t"<<per[y].num<< endl;
    }
    
    salida.close();//cierra proceso de transferencia de datos de vector a archivo

}        

void borrar(){
long tamArchivo;
char * nomArchivo;
FILE * archivo;
long i;

nomArchivo = "persistencia.txt"; /* Nombre (si esta en misma carpeta) o ruta del archivo */

archivo = fopen(nomArchivo,"r+"); /* Abro el archivo para lectura/escritura */
fseek(archivo,0,SEEK_END); /* Recorro el archivo hasta el final */
tamArchivo = ftell(archivo); /* Almaceno la posicion actual en el archivo */
rewind(archivo); /* Regreso al principio del archivo */

for(i=0; i<tamArchivo; i++) /* Recorro cada posicion del archivo */
{
fprintf(archivo,"%c",'0'); /* Imprimo un 0 en la posicion */
}

fclose(archivo); /* Cierro el archivo */
remove(nomArchivo); /* Elimino el archivo */
getch();

}		
		
		
