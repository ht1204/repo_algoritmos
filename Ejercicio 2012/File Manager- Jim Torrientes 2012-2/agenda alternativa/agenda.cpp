#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

int main(){
    system("cls");
    cargar();
    menu();
    getch();
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
     cout<<"\n\t5.Salir \n";
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
         cout<<"\n\tIngrese nombre :  ";
         cin>>per[i].nombre;
         cout<<"\n\tIngrese apellido  : ";     
         cin>>per[i].apellido;
         do{
         cout<<"\n\tIngrese numero telefonico :  ";
         cin>>per[i].num;
         }while(validanumero(per[i].num));
              i++;
          persistencia();


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
     cout<<"\n\tIngrese numero de celular para modificar registro ";
     cin>>num1;
     
     for(int y=0;y<i;y++){
         if(per[y].num==num1){ 
          pos=y;   
            do{
                   system("cls");
              cout<<"\n\tMenu modificar ";            
              cout<<"\n\t1.Nombre :  "<<per[pos].nombre;
              cout<<"\n\t2.Apellido :  "<<per[pos].apellido;
              cout<<"\n\t3.Numero telefonico :  "<<per[pos].num;
              cout<<"\n\t4.Salir \n\t";
              cin>>op;
              switch(op){
              case 1:
                   cout<<"\n\tIngrese nuevo nombre ";
                   cin>>per[pos].nombre;
                   break;           
              case 2:
                   cout<<"\n\tIngrese nuevo apellido ";
                   cin>>per[pos].apellido;
                   break;
              case 3:
                   do{
                   cout<<"\n\tIngrese nuevo numero telefonico ";
                   cin>>numero;
                   }while(validanumero(numero)==1);          
                   per[pos].num=numero;
                   break;
              
              }
            }while(op!=4); 
            break;
            }
             }
             
                persistencia();      
             
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
          cout<<"\n\tIngrese numero de celular para modificar registro ";
          cin>>num1;          
          for(int y=0;y<i;y++){
                  if(per[y].num==num1){
                  pos=y;
                  b=true;
                  break;                    
                  }
                  }
         if(b==true){
                  for(int u=pos;u<i;u++){
                          per[u]=per[u+1];
                          }
                          i--; 
                          persistencia(); 
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
     
void persistencia(){
     FILE *f;
     f=fopen("persistencia.txt","w+");


     for(int y=0;y<i;y++){
       fprintf(f,"%s %s %d\n",per[y].nombre,per[y].apellido,per[y].num);   

      }
      fclose(f);       
       return;      
            
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
     
     
void cargar(){
     FILE *arcper;
     persona p;
     arcper=fopen("persistencia.txt","r");
    if(arcper==NULL){
     arcper=fopen("persistencia.txt","r");
     fclose(arcper);
     }else{
     i=-1;
     while(!feof(arcper)){

             fscanf(arcper,"%s %s %d",&p.nombre,&p.apellido,&p.num);
              i++;
             strcpy(per[i].nombre,p.nombre);
             strcpy(per[i].apellido,p.apellido);
             per[i].num=p.num;
             

             }
             
       fclose(arcper);  
       }    
		return;
     }
