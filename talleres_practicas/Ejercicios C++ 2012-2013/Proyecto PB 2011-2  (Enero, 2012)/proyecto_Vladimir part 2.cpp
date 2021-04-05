/*
  Name: Proyecto gestion de pedido
  Copyright: 
  Author: Luis Cervantes
         Hector Triana
  Date: 20/01/12 13:08
  Description: 
*/
/*
  Declaracion de librerias
*/ 
# include <iostream>
# include <stdio.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <conio.h>
using namespace std;
/*
  Fin Declaracion de librerias
*/
/*Declaracion de constantes y variables*/

/*Fin Declaracion de constantes y variables*/

/*Declaracion de Estructuras y punteros para el manejo de archivo*/
struct fecha{//Este struct nos va a ayudar a guardar las fechas en variables enteras
       int dia;
       int mes;
       int ano;
}f;
struct fechacomp{//Este struct nos va a ayudar junto con el anterior en el manejo de fecha 
       fecha fecm;//Permite acceder a las variables enteras de fecha
       char hora['v'];//Nos va a permitir guardar la hora
       }ftot;
      
       
       
struct empresa{//Aqui estan todos los atributos de empresa
       long nit;//su numero nit
       char nom['a'];//nombre de la empresa que nos vende un producto para vender
       char dir['s'];//Direccion de la empresa
       empresa *proemp;//Estos punteros
}*nodoemp,*pemp,nodoe;//nos ayudaran a desplazarnos en los espacios de memoria de la lista enlazada , actualizar y cargar el fichero
   //declaracio del puntero de fichero
   FILE *arcEmp;
   
struct producto{
       long idem;//Esta es para identificar la identificacion de la empresa que nos vende un producto
       long id;//identificacion del producto en bodega
       char nom['w'];//nombre del producto
       long codinv;//codigo invima para calidad ISO 9001
       long codcom;//codigo de comercio que se halla vigente en la camara 
       fecha ven;//nos permite acceder a las variables de fecha para asignar una fecha de vencimiento
       producto *propro;//Estos punteros
}*nodopro,*ppro,pro;//nos ayudaran a desplazarnos en los espacios de memoria de la lista enlazada,actualizar y cargar el fichero
    //declaracio del puntero de fichero
    FILE *arcPro;
    
struct trabajador{
       long id;//identificacion del vendedor
       char nom['s'];//nombre del vendedor
       long long sal;//salario neto del vendedor
       trabajador *protra;//Estos punteros
}*nodotra,*ptra,tra2;//nos ayudaran a desplazarnos en los espacios de memoria de la lista enlazada, actualizar y cargar el fichero
    //declaracio del puntero de fichero
    FILE *arcTra;

struct cliente{
       long id;//numero de identificacion del cliente, esto es universal en personas y propietarios de empresa
       char dir['w'];//direccion del cliente
       char nom['w'];//nombre del cliente
       long nit;//nit para registrarse comercialmente
       cliente *procli;//Estos punteros
}*nodocli,*pcli,cli2;//nos ayudaran a desplazarnos en los espacios de memoria de la lista enlazada, actualizar y cargar el fichero
    //declaracio del puntero de fichero
    FILE *arcCli;
   
    struct fechacomp2{//Este estruct nos ayudara a transferir fechas de entrega basandonos en manejo de fecha
       int dia2;//dia de entrega
       int mes2;//mes de entrega
       int ano2;//año de entrega
       char hora2['v'];//hora de entrega
       }f1; 
    
struct gestion{
       long nitemp,nitempd;//nit de empresa que nos vende un producto y de la empresa a la cual vendemos
       long idpro;//identificacion del producto
       long int idtra;//identificacion del vendedor que hace la venta
       int cant;//cantidad de unidades vendidas del producto
       fechacomp eventoventa;//nos ayudara a guardar el momento exacto de realizacion de venta 
       //fecha y hora;
       int plazo;//plazo estipulado, fue validado de 1 a 15 dias para garantizar responsabilidad
       
       fechacomp2 entrega;//Nos ayudara a estimar el momento de entrega 
       gestion *proges;//Estos punteros
}*nodogestion,*pges,ges1;//nos ayudaran a desplazarnos en los espacios de memoria de la lista enlazada, actualizar y cargar el fichero
    //declaracio del puntero de fichero
    FILE *arcGes;
/*Fin Declaracion de Estructuras y punteros para el manejo de archivo*/

/*Declaracion de Funciones*/
void menu(); // se encarga de mostrar el primer mensage a los usuarios
void error(long double a,long double b,long double c);     //Muestra un mensaje a las opciones incorrectas
void seleccionar(int opc);                                 //DETERMINA EL MENU A EJECUTAR

/*************************Funciones de empresa*****************/
void registraremp();                                       //registrar empresa
bool validarcodemp(long cod);                              //se encarga de validar la existencia de codigos de empresa
void modificaremp();                                       //se encarga de modificar los datos de una empresa
void consultaremp();                                       //se encarga de mostar los datos de la empresa en caso de existir
void eliminaremp();                                        //se encarga de eliminar un elemento de la lista
void listaremp();                                          //se encarga de listar las empresas registradas
void loadempresa();                                        //se encarga de cargar las empresas que se encuentran en el archivo
void actualizaremp();                                      //se encarga de actualizar el archivo, frete a cualquier actualizacion en las listas
/*************************Funciones de producto*****************/

void productos();                                           //se encarga de mostrar las instrucciones, para el tratamiento de los productos
void registropro();                                         //se encarga del regsitro de productos
bool validarpro(long n,long pr);                             //se encarga de validar la existencia de un codigo de producto
void modificarpro();                                        //se encarga de modificar un registro
void actualizarpro();                                       //se encarga de actualizar los datos en el archivo de empresa
void consultarpro(long e,long pr);                          //se encarga de listar un producto
void eliminarpro();                                          //elimina producto de bloque de memoria 
void loadproducto();                                        //carga los datos de productos al iniciar el programa 
/*************************Funciones de trabajador*****************/

void menutrabajador();               //menu de opciones del trabajador
void registrartra();                 //registra trabajadores
bool validarcodtra(long int iden);   //se encarga de validar la existencia de codigos de identificacion de trabajadores
void modificartra();                 //se encarga de modificar los datos de un trabajador
void consultartra();                 //se encarga de mostrar los datos de un trabajador en caso de existir 
void eliminartra();                 //se encarga de eliminar un elemento de la lista
void listartra();                   //se encarga de listar trabajadores registrados
void actualizartra();                //se encarga de actualizar las empresas que se encuentran en el archivo
void loadtrabajador();              //se encarga de cargar los datos de los trabajadores que se ecuentran en el archivo
/*************************Funciones de cliente*****************/

 void menucli();       //menu de opciones del cliente
 void registracli();   //registra clientes
 void modificacli();       //se encarga de modificar los datos de un cliente
 void consultacli();     //se encarga de mostrar los datos de un cliente en caso de existir 
 void eliminacli();     //se encarga de eliminar un elemento de la lista
 void listacli();      //se encarga de listar clientes registrados
 void loadcli();       //se encarga de cargar los datos de los clientes que se ecuentran en el archivo
 void actualizarcli();  //se encarga de actualizar los clientes que se encuentran en el archivo
 bool validarcodcli(long nitemp);//se encarga de validar la existencia de codigos de clientes

/*************************Funciones de gestion*****************/
void menuges();     //menu de opciones de la gestion de pedido
void loadges();      //se encarga de cargar los datos de los gestiones que se ecuentran en el archivo
void registrargest();  //registra gestiones
void consulistargest();  //se encarga de mostrar los datos de una gestion en caso de existir 
void eliminargest();  //se encarga de eliminar una gestion de la lista
void actualizages();  //se encarga de actualizar las gestiones que se encuentran en el archivo
void consultarproges(long codem, long codid);

/*************************Funciones de manejo de fecha*****************/
void fechas(int *d,int *m,int *a,char *fecha);//permite tomar la fecha del sistema para una conversion final de caracteres a enteros
void cortar(char *h,char *f);//Permite mediante ciclos determinados separar la fecha y la hora de sistema
int menuchartoint(char j);//convierte caracter por caracter la fecha del sistema a entero obedeciendo el codigo ASCII
fechacomp fregis();
/*******Utilidades***********/
void mensage(char m['s']);                                  //se encarga de generar un mensage 
/***Fin Utilidades***********/
/*Fin Declaracion de Funciones*/

/*Funcion Principal*/
int main(){
    int opc;
    //se procede a inicializar las listas del proyecto
    //empresa
    pemp = new empresa;
    pemp->proemp=NULL;
    //producto
    ppro= new producto;
    ppro->propro=NULL;
    //Trabajador
    ptra= new trabajador;
    ptra->protra=NULL;
    //Cliente
    pcli= new cliente;
    pcli->procli=NULL;
    //Gestion
    pges = new gestion;
    pges->proges=NULL;
    /*******************Implementacion de manejo de Achivos*****************/
    //empresa
    arcEmp=fopen("empresa","r");
    if(!arcEmp){
       arcEmp=fopen("empresa","w");
    }
    fclose(arcEmp);
    //producto
    arcPro= fopen("producto","r");
    if(!arcPro){
       arcPro=fopen("producto","w");
    }
    fclose(arcPro);
    //Trabajador
    arcTra=fopen("trabajador","r");
    if(!arcTra){
       arcTra=fopen("trabajador","w");
    }
    fclose(arcTra);
    //Cliente
    arcCli=fopen("cliente","r");
    if(!arcCli){
       arcCli=fopen("cliente","w");
    }
    fclose(arcCli);
    //Gestion
    arcGes=fopen("gestion","r");
    if(!arcGes){
       arcGes=fopen("gestion","w");
    }
    fclose(arcGes);
    /*********************Fin  Implementacion de manejo de Achivos************************/
    /*********************load de los distintos archivos de el programa*******************/
    loadempresa();
    loadproducto();
    loadtrabajador();
    loadcli();
    loadges();
    /*********************Fin load de los distintos archivos de el programa***************/
    do{
       system("title Proyecto gestion de pedido");
       system("cls");
       menu();
       cout<<"\n\n\tDigite la opcion :  ";cin>>opc;
       error(1,5,opc);  
       seleccionar(opc);   
    }while(opc != 5);
}
/*Fin Funcion Principal*/
void menu(){
     cout<<"\n\t\t\tMenu Principal";
     cout<<"\n\n\t1. Empresa";
     cout<<"\n\t2. Trabajadores";
     cout<<"\n\t3. Clientes";
     cout<<"\n\t4. Gestion de Pedidos";
     cout<<"\n\t5. Salir"; 
}
/*Implementacion de funciones*/
//**FUNCION DE ERROR**//
void error(long double a,long double b,long double c){
     if(c<a || c>b){
        cout<<"\n\n\tLA OPCION DIGITADA ES INCORRECTA....!\n\t";
        getch();
        }
}

//**FUNCION SELECCIONAR**//
void seleccionar(int opc){
     int opc1=0;
     switch (opc){
            case 1 :
                 do{
                    system("cls");
                    cout<<"\t\t\nMENU DE EMPRESA";
                    cout<<"\n\n\t1. Registrar";
                    cout<<"\n\t2. Modificar";
                    cout<<"\n\t3. Consultar";
                    cout<<"\n\t4. Eliminar";
                    cout<<"\n\t5. Listar";
                    cout<<"\n\t6. Producto";
                    cout<<"\n\t7.Salir";
                    cout<<"\n\n\t Digite la opcion : ";cin>>opc1;
                    error(1,7,opc1);
                    switch (opc1){
                                  case 1:
                                       registraremp();
                                  break;
                                  case 2:
                                      if(pemp->proemp==NULL){//validamos en caso que no se halla registrado nada antes
                                      printf("\n\tNo hay empresas registradas  ");
                                       getch();
                                       break;
                                      }else{
                                       modificaremp();
                                       }
                                  break;
                                  case 3:
                                      if(pemp->proemp==NULL){//validamos en caso que no se halla registrado nada antes
                                      printf("\n\tNo hay empresas registradas  ");
                                      getch();
                                      break;
                                      }
                                       consultaremp();
                                  break;
                                  case 4:
                                  if(pemp->proemp==NULL){//validamos en caso que no se halla registrado nada antes
                                      printf("\n\tNo hay empresas registradas  ");
                                       getch();
                                       break;
                                      }else{
                                       eliminaremp();
                                       }
                                  break;
                                  case 5:
                                      if(pemp->proemp==NULL){//validamos en caso que no se halla registrado nada antes
                                      printf("\n\tNo hay empresas registradas  ");
                                       getch();
                                       break;
                                      }else{
                                       listaremp();
                                       }
                                  break;
                                  case 6:
                                       productos();
                                  break;
                    
                    }                  
                 }while(opc1 != 7);
                 opc1=0;
            break;
            case 2 :
                 menutrabajador(); 
            break;
            case 3 :
                menucli();
            break;
            case 4 :
                 menuges();
            break;
            case 5 :
                 system("cls");
                 for(int i=0;i<=11;i++){
                     if(i==0 || i==11){
                        for(int y=0;y<=59;y++){
                            cout<<"*";
                        }
                        cout<<"\n";
                     }else if(i==6){
                           cout<<"*  EL MUNDO ES DE AQUELLOS QUE ESTAN DISPUESTOS A TOMARLO  *";
                           cout<<"\n";
                     }else{
                           for(int z=0;z<=59;z++){
                               if(z==0 || z==59){
                                  cout<<"*";
                               }else{
                                  cout<<" ";
                               }
                           }
                           cout<<"\n";
                     }
                 }
                 getch();
            break;
     }
}
//void registraremp(): se encarga de registrar las empresas
void registraremp(){
     empresa emp;      //se crea esta instancia para evitar el problema con el almacenamiento en el archivo
     long nit;
     do{
          system("cls");
           cout<<"\n\t\t\tREGISTRAR EMPRESA";
           cout<<"\n\n\tDigite el nit :    ";cin>>nit;
           if(validarcodemp(nit)==true){//validamos que el nit de la empresa se encuente en registro para evitar confusiones
              cout<<"\n\n\t\tLA EMRESA SE ENCUENTRA REGISTRADA...!";
              getch();
              return;
           }
     }while(nit<1 || nit >1000);//lo validamos de 1 a mil para darle orden, se puede modificar si lo deseas, no afecta
     nodoemp= new empresa;//asignando espacio en memoria para iniciar registro en lista
     nodoemp->nit=nit;//asignando nit
     fflush(stdin);//buffer para evitar inconvientes con caracteres
     cout<<"\n\tDigite el nombre               :             ";gets(nodoemp->nom);//asignando nombre de empresa
     cout<<"\n\tDigite la direccion           :             ";gets(nodoemp->dir);//asignando direccion de empresa 
     /****************llenado del archivo con los datos********************************/
     nodoe.nit=nodoemp->nit;//añadiendo
     strcpy(nodoe.nom,nodoemp->nom);//datos
     strcpy(nodoe.dir,nodoemp->dir);//al fichero que guarda datos de empresa
     arcEmp=fopen("empresa","a+");//garantizando
     fwrite(&nodoe,sizeof (struct empresa),1,arcEmp);//flujo de datos
     fclose(arcEmp);//cerrando fichero
     /********************************************************************************/
     nodoemp->proemp=pemp->proemp;//asignando espacio en memoria dinamica
     pemp->proemp=nodoemp;//para nueva implementacion de registro
}
//VALIDARCODEMP() : esta funcion se encarga de validar las existencia de empresas
bool validarcodemp(long cod){
     empresa *aux;
     aux=pemp->proemp;//asignando espacio de memoria siguiente
     while(aux != NULL){//buscando en la lista para ver si el dato digitado ya se encuentra registrado
           if(aux->nit == cod){//si esta anteriormente devuelve true y nos ayuda a validar y evitar confusiones posteriores
              return true;
           }
           aux=aux->proemp;//sigue buscando en lista
     }
     return false;//si no se halla devuelve false y nos ayudara a registrar nuevo dato y saber si no estaba anteriormente
}

//modidicaremp() :  se encarga de modificar los datos de una empresa en particular
void modificaremp(){
     long nit;
     int opc;
          system("cls");
           cout<<"\n\t\t\tMODIFICAR EMPRESA";
           cout<<"\n\n\tDigite el nit :    ";cin>>nit;
           if(validarcodemp(nit)==false){//validando para saber si la empresa esta registrada en la lista
              cout<<"\n\n\t\tLA EMRESA NO SE ENCUENTRA REGISTRADA...!";
              getch();
              return;
           }
           empresa *aux;
           aux=pemp->proemp;//asignando memoria al espacio siguiente 
           while(aux != NULL){
                 if(aux->nit==nit){//si la lista el dato nit se encuentra entonces muestra la lista con los atributos que acompañan
                    do{//ese dato
                        system("cls");
                        cout<<"\n\t\t\tMODIFICAR EMPRESA";//menu modificar empresa
                        cout<<"\n\n\t1. Nit :              "<<aux->nit;
                        cout<<"\n\t2. Nombre :           "<<aux->nom;
                        cout<<"\n\t3. Dirreccion :       "<<aux->dir;
                        cout<<"\n\t4. Salir.             ";
                        cout<<"\n\n\tDigite la opcion :  ";cin>>opc; 
                        error(1,4,opc);
                        switch(opc){
                                    case 1 ://modificando nit
                                         long nit;
                                         do{
                                          do{
                                            cout<<"\n\n\tDigite el nit :   ";cin>>nit;
                                            if(validarcodemp(nit) == true){
                                               cout<<"\n\n\tEl nit se encuentra registrado....!";
                                               getch();
                                            }
                                          }while((aux->nit <0 || aux->nit>1000) );
                                         }while(validarcodemp(nit)==true);//si en nit esta registrado, sigue pidiendo nuevo registro
                                         aux->nit=nit;//asignando nuevo registro
                                    break;
                                    
                                    case 2:
                                         fflush(stdin);
                                         cout<<"\n\n\tDigite el nombre  :   ";gets(aux->nom);//cambiando nombre de empresa
                                    break;
                                    
                                    case 3:
                                         fflush(stdin);
                                         cout<<"\n\n\tDigite la direccion  :   ";gets(aux->dir);//cambiando direccion de empresa
                                    break;
                                    
                        }
                        actualizaremp();                         //se actualizan los datos en el archivo de empresa
                    }while(opc != 4);//cuando se presion 4, se rompe el meno
                    return;
                 }
                 aux=aux->proemp;//buscando registros en memoria hasta llegar a null
           }
}

//consultaremp(); se encarga de mostrar los datos de una empre de existir
void consultaremp(){
     long nit;
     system("cls");
     cout<<"\n\t\t\tCONSULTAR EMPRESA";
     cout<<"\n\n\tDigite el nit : ";cin>>nit;
     if(validarcodemp(nit)==false){//si no se halla la empresa, no consulta
        cout<<"\n\n\n\t\t\a\a\aLA EMPRESA NO SE ENCUENTRA REGISTRADA...!\n\t";
        getch();
        return;
     }
     empresa *aux;
     aux=pemp->proemp;//asignando memoria a espacio siguiente
     while(aux != NULL){
          if(aux->nit==nit){// si halla en nit en lista, lo muestra con sus atributos  
             system("cls");
             cout<<"\n\t\t\tCONSULTAR EMPRESA";
             cout<<"\n\n\tNit :              "<<aux->nit;
             cout<<"\n\tNombre :           "<<aux->nom;
             cout<<"\n\tDirreccion :       "<<aux->dir<<"\n\t";
             getch();
             return;               
          }
          aux=aux->proemp;
     }
}

//eliminaremp(): se encarga de eliminar un elemento de la lista
void eliminaremp(){
     long nit;
     int res;
     system("cls");
     cout<<"\n\t\t\tELIMINAR EMPRESA";
     cout<<"\n\n\tDigite el nit : ";cin>>nit;
     if(validarcodemp(nit)==false){//si la empresa no se halla registrada no elimina
        cout<<"\n\n\n\t\t\a\a\aLA EMPRESA NO SE ENCUENTRA REGISTRADA...!\n\t";
        getch();
        return;
     }
     empresa *aux,*a;//punteros auxiliares que permitiran el intercambio de espacios en memoria para borrar registro
     aux=pemp->proemp;//asignando memoria a espacio siguiente 
     a=pemp;// Este puntero estara un espacio de memoria anterior a aux, asi podremos borrar 
     while(aux != NULL){
          if(aux->nit==nit){//si halla el nit, muestra al usuario los atributos compañeros, y ayuda al usuario a decidir
             system("cls");
             cout<<"\n\t\t\tELIMINAR EMPRESA";
             cout<<"\n\n\tNit :              "<<aux->nit;
             cout<<"\n\tNombre :           "<<aux->nom;
             cout<<"\n\tDirreccion :       "<<aux->dir<<"\n\t";
             do{
                cout<<"\n\n\tDesea eliminar la empresa (1. Si - 2. No) :  ";cin>>res;//decidiendo si quiere borrar
                error(1,2,res);
             }while(res<1 || res>2);
             if(res == 1){//borrando
                a->proemp=aux->proemp;//intercambiando espacios de memoria en lista para borrar
                delete aux;//dato borrado   
                actualizaremp();               //se actulizan los datos en el archivo
                mensage("SUS DATOS SE BORRARON SATISFACTORIAMENTE");
             }
             
             return;               
          }
          a=aux;//cambiando datos en lista por traspaso de memoria entre ficheros
          aux=aux->proemp;//avanzando en lista para actualizacion
     }
}
/*********************Seccion de productos************************/
//producto(): se encarga de mostrar las opciones para los productos
void productos(){
     int opcpro;
     do{
        system("cls");
        cout<<"\n\t\t\tMENU DE PRODUCTOS";
        cout<<"\n\n\t1. Registrar";
        cout<<"\n\t2. Modificar";
        cout<<"\n\t3. consultar";
        cout<<"\n\t4. Listar";
        cout<<"\n\t5. Eliminar";
        cout<<"\n\t6. Salir";
        cout<<"\n\n\t   Digite la opcion : ";cin>>opcpro;
        error(1,6,opcpro);
        switch (opcpro){
                        case 1:
                             registropro();              //se encarga del regsitro de productos
                        break;
                        
                        case 2:
                            if(ppro->propro==NULL){//validamos en caso que no se halla registrado nada antes
                                      printf("\n\tNo hay productos registrados  ");
                                      getch();
                                      break;
                                      }else{
                             modificarpro();
                             }             //se encarga de modificar un registro
                        break;
                        
                        case 3:
                            if(ppro->propro==NULL){//validamos en caso que no se halla registrado nada antes
                                      printf("\n\tNo hay productos registrados  ");
                                      getch();
                                      break;
                                      }else{
                             long em,p;
                             cout<<"\n\t\tCONSULTAR PRODUCTO";
                             cout<<"\n\n\tDigite el nit de la empresa :    ";cin>>em;
                             if(validarcodemp(em)== false){//valida para cerciorarse que la empresa exista
                                mensage("LA EMPRESA NO SE ENCUENTRA REGISTRADA");
                                break;
                             }
                             cout<<"\n\tDigite el codigo del producto :       ";cin>>p;//se debe validar que el codigo existe en bodega
                             if(validarpro(em,p)==false){
                                  mensage("EL CODIGO NO SE ENCUENTRA REGISTRADO");
                                  break;
                             }
                             system("cls");
                             cout<<"\n\t\t\tCONSULTAR PRODUCTO";
                             consultarpro(em,p);
                             cout<<"\n\t";
                             getch();
                             }
                        break;
                        
                        case 4:
                              if(ppro->propro==NULL){//validamos en caso que no se halla registrado nada antes
                                      printf("\n\tNo hay productos registrados  ");
                                      getch();
                                       break;
                                      }else{
                               producto *aux;
                               aux=ppro->propro;
                               system("cls");
                               cout<<"\n\t\t\tLISTAR PRODUCTO";
                               while(aux != NULL){//lista todos los productos en bodega con su informacion necesaria
                                         cout<<"\n\tnit de la empresa que vende el producto   "<<aux->idem;
                                         cout<<"\n\tIdentificacion del producto  "<<aux->id;
                                         cout<<"\n\tcodigo de comercializacion  "<<aux->codcom;
                                         cout<<"\n\tcodigo invima  "<<aux->codinv;
                                         cout<<"\n\tFecha de Vencimiento  ";
                                         cout<<"\n\tDia :  "<<aux->ven.dia;
                                         cout<<"\n\tMes :  "<<aux->ven.mes;
                                         cout<<"\n\tAño :  "<<aux->ven.ano;
                                         cout<<"\n\n";
                                         aux=aux->propro;
                               }
                               cout<<"\n\t";
                               getch();
                               }
                        break;
                        
                        case 5:
                            if(ppro->propro==NULL){//validamos en caso que no se halla registrado nada antes
                                      printf("\n\tNo hay productos registrados  ");
                                      getch();
                                      }
                             eliminarpro();//elimina productos
                        break;
        }
     }while(opcpro != 6);
}
//void registropro() : se encarga del regsitro de productos
void registropro(){
     long em,p;int y;
     system("cls");
     cout<<"\n\t\t\tREGISTRO DE PRODUCTO";
     cout<<"\n\n\tDigite el nit de la empresa :    ";cin>>em;
     if(validarcodemp(em)== false){//validamos  el nit para saber si la empresa esta registrada o no
        mensage("LA EMPRESA NO SE ENCUENTRA REGISTRADA");
        return;
     }
     cout<<"\n\tDigite el codigo del producto :       ";cin>>p;//validamos el codigo del producto en bodega para evitar confusiones 
     if(validarpro(em,p)==true){
         mensage("EL CODIGO SE ENCUENTRA REGISTRADO");
         return;
     }
     nodopro= new producto;//asignando memoria dinamica para registrar en lista 
     nodopro->idem=em;//asignando
     nodopro->id=p;//codigos 
     ftot=fregis();//tomando fecha del sistema para evitar vender productos vencidos 
     //Digitando datos para registro de producto
     fflush(stdin);
     cout<<"\n\tDigite el nombre del producto :       ";gets(nodopro->nom);
     cout<<"\n\tDigite el codigo invima       :       ";cin>>nodopro->codinv;
     cout<<"\n\tDigite el codigo de comercio  :       ";cin>>nodopro->codcom;
     cout<<"\n\tDigite la fecha de vencimiento:       ";
     do{//validando año de vencimiento para no vender productos expirados 
      cout<<"\n\t                          Año :       ";cin>>nodopro->ven.ano;
     }while(nodopro->ven.ano<ftot.fecm.ano);
     if(nodopro->ven.ano==ftot.fecm.ano){
    do{//validando mes de vencimiento respecto a año
        cout<<"\n\t                          Mes :       ";cin>>nodopro->ven.mes;                              
     }while(nodopro->ven.mes<ftot.fecm.mes||nodopro->ven.mes>12);
         }
  
   if(nodopro->ven.ano>ftot.fecm.ano){
      do{
    cout<<"\n\t                          Mes :       ";cin>>nodopro->ven.mes;                              
       }while(nodopro->ven.mes<1||nodopro->ven.mes>12);
         }
      if(nodopro->ven.mes==1||nodopro->ven.mes==3||nodopro->ven.mes==5||nodopro->ven.mes==7||nodopro->ven.mes==8||nodopro->ven.mes==10||nodopro->ven.mes==12){
          do{//validando dias respecto a mes de registro
           cout<<"\n\t                          Dia :       ";cin>>nodopro->ven.dia;                                                                                                                                                     
          }while(nodopro->ven.dia<1||nodopro->ven.dia>31);                                                                                                                                                                                                                                                                                                        
     y=1;
      }else{
           do{
           cout<<"\n\t                          Dia :       ";cin>>nodopro->ven.dia;                                                                                                                                                     
          }while(nodopro->ven.dia<1||nodopro->ven.dia>30);
       y=2;
         }
        if((nodopro->ven.ano==ftot.fecm.ano)&&(nodopro->ven.mes==2)){ 
        do{//validando dia de vencimiento respecto a febrero 
        cout<<"\n\t                          Dia :       ";cin>>nodopro->ven.dia; 
         }while(nodopro->ven.dia<1||nodopro->ven.dia>29);
        }
        
         if((nodopro->ven.ano==ftot.fecm.ano)&&(nodopro->ven.mes==2)&&(ftot.fecm.mes==2)){ 
        do{
        cout<<"\n\t                          Dia :       ";cin>>nodopro->ven.dia; 
         }while(nodopro->ven.dia<ftot.fecm.dia||nodopro->ven.dia>29);
        }
        
         if((nodopro->ven.ano%4==0)&&(nodopro->ven.mes==2)&&(ftot.fecm.mes==2)){ 
        do{
        cout<<"\n\t                          Dia :       ";cin>>nodopro->ven.dia; 
         }while(nodopro->ven.dia<ftot.fecm.dia||nodopro->ven.dia>29);
        }
        //validando dia de vencimiento respecto a mismo año y mismo mes del sistema 
        if((nodopro->ven.ano==ftot.fecm.ano)&&(nodopro->ven.mes==ftot.fecm.mes)&&(y==1)){
           do{
           cout<<"\n\t                          Dia :       ";cin>>nodopro->ven.dia;                                                                                                                                                     
          }while(nodopro->ven.dia<ftot.fecm.dia||nodopro->ven.dia>31); 
             }                                                                 
      if((nodopro->ven.ano==ftot.fecm.ano)&&(nodopro->ven.mes==ftot.fecm.mes)&&(y==2)){
           do{
           cout<<"\n\t                          Dia :       ";cin>>nodopro->ven.dia;                                                                                                                                                     
          }while(nodopro->ven.dia<ftot.fecm.dia||nodopro->ven.dia>30); 
             }  
        
     /****************llenado del archivo con los datos********************************/
     pro.idem=nodopro->idem;
     pro.id=nodopro->id;
     strcpy(pro.nom,nodopro->nom);
     pro.codinv=nodopro->codinv;
     pro.codcom=nodopro->codcom;
     pro.ven.dia=nodopro->ven.dia;
     pro.ven.mes=nodopro->ven.mes;
     pro.ven.ano=nodopro->ven.ano;
     arcPro=fopen("producto","a+");
     fwrite(&pro,sizeof(struct producto),1,arcPro);
     fclose(arcPro);
     /********************************************************************************/     
     nodopro->propro=ppro->propro;
     ppro->propro=nodopro;
     
} 
//bool validarpro(long n,long p) : se encarga de validar la existencia de un codigo de producto 
bool validarpro(long n,long pr){
     producto *aux;
     aux=ppro->propro;
     while(aux != NULL){//buscando si el nit de la empresa y la identificacion del producto existe 
          if(aux->idem == n && aux->id==pr){
              return true;         
          }
          aux=aux->propro;
     }
     return false;
} 
//void modificarpro():se encarga de modificar un registro      
void modificarpro(){
     long em,p;
     int opcp;
     system("cls");
     cout<<"\n\t\t\tMODIFICADO DE PRODUCTO";
     cout<<"\n\n\tDigite el nit de la empresa :    ";cin>>em;
     if(validarcodemp(em)== false){//validando para saber si la empresa existe en registro
        mensage("LA EMPRESA NO SE ENCUENTRA REGISTRADA");
        return;
     }
     cout<<"\n\tDigite el codigo del producto :       ";cin>>p;//?se debe validar
     if(validarpro(em,p)==false){//validando para saber si el producto existe en bodega 
         mensage("EL CODIGO NO SE ENCUENTRA REGISTRADO");
         return;
     }
     producto *aux;
     aux=ppro->propro;
     while(aux != NULL){
           if(aux->idem==em && aux->id ==p){//si se hallan, muestra todos los atributos 
              do{
                  system("cls");
                  cout<<"\n\t\t\tMODIFICADO DE PRODUCTO";
                  cout<<"\n\n\t1. Codigo de la empresa       :       "<<aux->idem;
                  cout<<"\n\t2. Codigo del producto        :       "<<aux->id; 
                  cout<<"\n\t3. Nombre del producto        :       "<<aux->nom;
                  cout<<"\n\t4. Codigo invima              :       "<<aux->codinv;
                  cout<<"\n\t5. Codigo de comercializacion :       "<<aux->codcom;
                  cout<<"\n\t6. Salir";
                  cout<<"\n\n\t   Digite la opcion :  ";cin>>opcp;
                  error(1,6,opcp);
                  switch (opcp){
                                case 1:
                                     long nit;
                                     do{
                                         cout<<"\n\n\tDigite el nit :   ";cin>>nit;//puede darse el caso de que la empesa se cambie
                                         if(validarcodemp(nit)==true)// y el producto que esta contenga se encuentre duplicado
                                            mensage("EL NIT SE ENCUENTRA REGISTRADO");
                                     }while(validarcodemp(nit)==true);
                                     aux->idem=nit;
                                break;
                                
                                case 2:
                                     long cod;
                                     do{
                                         cout<<"\n\n\tDigite el codigo del producto :  ";cin>>cod;
                                         if(validarpro(aux->idem,cod)==true){
                                               mensage("EL CODIGO SE ENCUENTRA REGISTRADO");
                                         }
                                     }while(validarpro(aux->idem,cod)==true);
                                     aux->id=cod;
                                break;
                                
                                case 3:
                                     fflush(stdin);//cambiando nombre
                                     cout<<"\n\tDigite el nombre del producto :       ";gets(aux->nom);
                                break;
                                
                                case 4://cambiando codigo invima
                                     cout<<"\n\tDigite el codigo invima       :       ";cin>>aux->codinv;
                                break;
                                
                                case 5://cambiando codigo de comercio
                                     cout<<"\n\tDigite el codigo de comercio  :       ";cin>>aux->codcom;
                                break;
                                
                             
                  }//se decidio mejor no cambiar fecha de vencimiento porque eso obedecen a estandares solo de la empresa, no de nosotros
              actualizarpro(); 
              }while(opcp != 6);//al presionar 6, rompe el meno
             
              return;
           }
           aux=aux->propro;//buscando en lista 
     }
}   
void consultarpro(long e,long pr){
     producto *aux;
     long codem,codid;
    cout<<"\n\tConsultar producto  ";
    cout<<"\n\tIngrese codigo de empresa  ";cin>>codem;
    cout<<"\n\tIngrese codigo del producto ";cin>>codid;
    if(validarpro(codem,codid)==false){//se hace la misma accion de eliminar, saber si la empresa y producto existen
    cout<<"\n\tLa empresa y/o el codigo del producto no se encuentran registrados  ";                             
    getch();
    return;
    }
     aux=ppro->propro;
     while(aux != NULL){
          if(aux->idem ==e && aux->id==pr){//se hallan en lista, los muestra
                  cout<<"\n\n\tCodigo de la empresa       :       "<<aux->idem;
                  cout<<"\n\tCodigo del producto        :       "<<aux->id; 
                  cout<<"\n\tNombre del producto        :       "<<aux->nom;
                  cout<<"\n\tCodigo invima              :       "<<aux->codinv;
                  cout<<"\n\tCodigo de comercializacion :       "<<aux->codcom;
                  cout<<"\n\tFecha de vencimiento       :       "<<aux->ven.dia<<" / "<<aux->ven.mes<<" / "<<aux->ven.ano;           
                  return;
          }    
          aux=aux->propro; //avanzando en lista 
     }
}   
void eliminarpro(){
     long em,p;
     int res;
     system("cls");
     cout<<"\n\t\tELIMINAR PRODUCTO";
     cout<<"\n\n\tDigite el nit de la empresa :    ";cin>>em;
     if(validarcodemp(em)== false){//si el codigo de la empresa no esta, no puede seguir
        mensage("LA EMPRESA NO SE ENCUENTRA REGISTRADA");
        return;
     }
     cout<<"\n\tDigite el codigo del producto :       ";cin>>p;//si el codigo de la empresa no esta, no puede seguir
     if(validarpro(em,p)==false){
          mensage("EL CODIGO NO SE ENCUENTRA REGISTRADO");
          return;
     }
     producto *aux,*a;
     aux=ppro->propro;//asignando
     a=ppro;//bloques de memoria para intercambiar y borrar
     while(aux != NULL){
           if(aux->idem == em && aux->id == p){//si se hallan, muestra los atributos a borrar 
              system("cls");
              cout<<"\n\t\tELIMINAR PRODUCTO";
                  cout<<"\n\n\tCodigo de la empresa       :       "<<aux->idem;
                  cout<<"\n\tCodigo del producto        :       "<<aux->id; 
                  cout<<"\n\tNombre del producto        :       "<<aux->nom;
                  cout<<"\n\tCodigo invima              :       "<<aux->codinv;
                  cout<<"\n\tCodigo de comercializacion :       "<<aux->codcom;
                  cout<<"\n\tFecha de vencimiento       :       "<<aux->ven.dia<<" / "<<aux->ven.mes<<" / "<<aux->ven.ano; 
              do{
                cout<<"\n\n\tDesea eliminar el producto de la empresa (1. Si - 2. No) :  ";cin>>res;
                error(1,2,res);
             }while(res<1 || res>2);
             if(res == 1){//borrando
                a->propro=aux->propro;//cambiando espacios de memoria
                delete aux; //registro borrado  
                actualizarpro();               //se actulizan los datos en el archivo
                mensage("SUS DATOS SE BORRARON SATISFACTORIAMENTE");
             }
             return;
           }
           a=aux;//cambiando bloque de memoria
           aux=aux->propro;//lista avanzando
     }
}                                                                        
/*****************Fin Seccion de productos************************/
//listaremp(): se encarga de listar todas las empresas registrdas
void listaremp(){
     empresa *aux;
     aux=pemp->proemp;
     system("cls");
     cout<<"\n\n\t\tLISTAR EMPRESAS\n\n";
     while(aux != NULL){
           cout<<"\n\n\tNit :              "<<aux->nit;
           cout<<"\n\tNombre :           "<<aux->nom;
           cout<<"\n\tDireccion :       "<<aux->dir;   
           aux=aux->proemp;
     }
     cout<<"\n\t";
     getch();
}
/*Fin de implementacion de funciones*/
/********************Funciones de cargado de imformacion**********************/
//Funcion de load de empresas desde el archivo
void loadempresa(){//carga los datos ya guardados para que la lista pueda preservarlos en nuevo encendido de maquina 
     if(arcEmp==NULL){
         return;             
     }
     empresa emp;
     arcEmp=fopen("empresa","r");
     fread(&emp,sizeof(struct empresa),1,arcEmp);
     while(!feof(arcEmp)){
           nodoemp = new empresa;
           nodoemp->nit=emp.nit;
           strcpy(nodoemp->nom,emp.nom);
           strcpy(nodoemp->dir,emp.dir);
           nodoemp->proemp=pemp->proemp;
           pemp->proemp=nodoemp;
           fread(&emp,sizeof(struct empresa),1,arcEmp);
     }
     fclose(arcEmp);
}

void loadproducto(){//carga los datos ya guardados para que la lista pueda preservarlos en nuevo encendido de maquina 
     if(arcPro==NULL){
        return;   
     }
     producto prod;
     arcPro=fopen("producto","r");
     fread(&prod,sizeof(struct producto),1,arcPro);
     while(!feof(arcPro)){
           nodopro= new producto;
           nodopro->idem=prod.idem;
           nodopro->id=prod.id;
           strcpy(nodopro->nom,prod.nom);
           nodopro->codinv=prod.codinv;
           nodopro->codcom=prod.codcom;
           nodopro->ven.dia=prod.ven.dia;
           nodopro->ven.mes=prod.ven.mes;
           nodopro->ven.ano=prod.ven.ano;
           nodopro->propro=ppro->propro;
           ppro->propro=nodopro;
           fread(&prod,sizeof(struct producto),1,arcPro);
     }
     fclose(arcPro);
}
//actualizaremp() : se encarga de actualizar los datos en el archivo de empresa
void actualizaremp(){
     empresa *aux,pro;
     aux=pemp->proemp;              //se inicializa el auxiliar para recorrer la lista
     arcEmp=fopen("empresa","w+");              //se borran todos los archivos para cargarlos con la actualizacion
     fclose(arcEmp);
     arcEmp=fopen("empresa","a+");              //se inicializa para anexar las estructuras a el archivo
     while(aux != NULL){
           pro.nit=aux->nit;
           strcpy(pro.nom,aux->nom);
           strcpy(pro.dir,aux->dir);
           fwrite(&pro,sizeof( struct empresa),1,arcEmp);
           aux=aux->proemp;
     }
     fclose(arcEmp);//cambios preservados 
}
//actualizarpro() : se encarga de actualizar los datos en el archivo de empresa
void actualizarpro(){
     producto *aux;
     aux=ppro->propro; //se inicializa el auxiliar para recorrer la lista
     arcPro=fopen("producto","w+");  //se borran todos los archivos para cargarlos con la actualizacion
     fclose(arcPro);
     arcPro=fopen("producto","a+"); //se inicializa para anexar las estructuras a el archivo
     while(aux != NULL){
           pro.idem=nodopro->idem;
           pro.id=aux->id;
           strcpy(pro.nom,aux->nom);
           pro.codinv=aux->codinv;
           pro.codcom=aux->codcom;
           pro.ven.dia=aux->ven.dia;
           pro.ven.mes=aux->ven.mes;
           pro.ven.ano=aux->ven.ano; 
           fwrite(&pro,sizeof(struct producto),1,arcPro);
           aux=aux->propro;   
     }
     fclose(arcPro);//cambios guardados
}
void menutrabajador(){
     int op;
     do{
     system("cls");
     cout<<"\n\tMenu de datos para trabajadores  ";
     cout<<"\n\n\t1.Registrar  ";
     cout<<"\n\t2.Modificar  ";
     cout<<"\n\t3.Consultar  ";
     cout<<"\n\t4.Eliminar  ";
     cout<<"\n\t5.Listar  ";
     cout<<"\n\t6.Salir";
     cout<<"\n\n\tDigite la opcion  ";
     cin>>op;
  
     switch(op){
                case 1:
                    registrartra();
                    break;
                case 2:
                    if(ptra->protra==NULL){//validamos en caso que no se halla registrado nada antes
                                      printf("\n\tNo hay trabajadores registrados  ");
                                      }else{
                     modificartra();
                     }
                     break;
                case 3:
                     if(ptra->protra==NULL){//validamos en caso que no se halla registrado nada antes
                                      printf("\n\tNo hay trabajadores registrados  ");
                                      }else{
                    consultartra();
                    }
                    break;
                case 4:
                if(ptra->protra==NULL){//validamos en caso que no se halla registrado nada antes
                                      printf("\n\tNo hay trabajadores registrados  ");
                                      }
                 eliminartra();                        
                break;
                case 5:
                  if(ptra->protra==NULL){//validamos en caso que no se halla registrado nada antes
                                      printf("\n\tNo hay trabajadores registrados  ");
                                      }else{
                  listartra();   
                  }
                break;
                
                   } 
           }while(op!=6); //al presionar 6, rompe el menu       
           
        
            } 

void registrartra(){
  long long int iden;
   do{
     system("cls");
     cout<<"\n\tRegistrando identificacion del trabajador  :    ";
     cin>>iden;
     if(validarcodtra(iden)==true){//si el trabajador se halla, no puede seguir 
     cout<<"\n\tEl trabajador correspondiente se encuentra registrado ";                              
     getch();
     return;                              
     }
     }while(iden<1000000||iden>25000000);//validamos en este intervalo porque el compilador no permitia mas
     nodotra=new trabajador;
     nodotra->id=iden;//asignando identificacion de trabajador en memoria 
      fflush(stdin);
      cout<<"\n\tDigite el nombre               :             ";gets(nodotra->nom);
      cout<<"\n\tDigite su salario              :              ";cin>>nodotra->sal;
     tra2.id=nodotra->id;//añadiendo registros al fichero
     strcpy(tra2.nom,nodotra->nom);
     tra2.sal=nodotra->sal;
     arcTra=fopen("trabajador","a+");
     fwrite(&tra2,sizeof (struct trabajador),1,arcTra);
     fclose(arcTra);
     
     nodotra->protra=ptra->protra;
     ptra->protra=nodotra;
      }
    //validando codigo trabajador   
    bool validarcodtra(long int iden){
       trabajador *aux;
       aux=ptra->protra;
       while(aux!=NULL){//hallando registros ya establecidos para evitar redundandia de informacion 
          if(aux->id==iden){
          return true;                  
          }              
                        
       aux=aux->protra;
       }
      return false; 
       } 
      //modificando trabajador 
   void modificartra(){
      long long int iden;
      int op1;
      system("cls");
      cout<<"\n\tModificando datos del trabajador ";
      cout<<"\n\tDigite el numero de identificacion  :    ";cin>>iden;
      if(validarcodtra(iden)==false){//validando codigo de trabajador 
      cout<<"\n\tEl trabajador no se encuentra registrado  ";
      getch();
      return;                               
      }

      trabajador *aux;
      aux=ptra->protra;//asignando bloque de memoria 
      while(aux!=NULL){
            if(aux->id==iden){//si halla el trabajador, muestra sus datos 
            do{
               system("cls");
              cout<<"\n\tMenu de datos del trabajador  ";                
              cout<<"\n\t1. Identificacion :    "<<aux->id;                
              cout<<"\n\t2.Nombre  :   "<<aux->nom;                
              cout<<"\n\t3.Salario :   "<<aux->sal;                
              cout<<"\n\t4.Salir ";
              cout<<"\n\n\tDigite la opcion para modificar  ";cin>>op1;
              switch(op1){
                      case 1:    
                            do{
                            cout<<"\n\n\tDigite la identificacion :   ";cin>>aux->id;
                            if(validarcodtra(aux->id) == true){
                              cout<<"\n\n\tEl trabajador se encuentra registrado....!";
                                 }//nos cercioramos que el trabajador no se halle anteriormente en lista 
                         }while(aux->id <1000000 || aux->id>25000000 && validarcodtra(aux->id)==true);
                         break;  
                    case 2:
                     fflush(stdin);
                     cout<<"\n\n\tDigite el nombre  :   ";gets(aux->nom);     
                      break;    
                      case 3:
                        cout<<"\n\n\tDigite su salario :   ";cin>>aux->sal;   
                       break;        
                       }     
                  actualizartra(); 
                 }while(op1!=4);           
                     
                    return;      
                    }         
                              
            aux=aux->protra;
            
                       }
          }                  
    //consultar un trabajador en particular                          
  void consultartra(){
      long long int iden;
       cout<<"\n\tConsultar trabajador  ";
       cout<<"\n\tDigite identificacion del trabajador  ";cin>>iden;
        if(validarcodtra(iden)==false){//si se halla, no consulta 
        cout<<"\n\tEl trabajador no se encuentra registrado  ";
        getch();
        return;
     }
     trabajador *aux;
   aux=ptra->protra;
     while(aux!=NULL){
         if(aux->id==iden){//si lo halla en lista, lo muestra 
                     system("cls");       
                   cout<<"\n\t Trabajador consultado  ";
                   cout<<"\n\n\tIdentificacion :              "<<aux->id;
                   cout<<"\n\tNombre :           "<<aux->nom;      
                   cout<<"\n\tSalario :          "<<aux->sal;       
                         return;
                           }             
                      
                      aux=aux->protra;
                      }  
       
         } 
         //eliminando registro de trabajador 
     void eliminartra(){
    long long int iden;
    int res;
     cout<<"\n\t\t\tConsultar trabajador para eliminar ";
     cout<<"\n\n\tDigite identificacion : ";cin>>iden;
     if(validarcodtra(iden)==false){//si no lo halla, no elimina 
        cout<<"\n\n\n\t\t\a\a\aEl trabajador no se encuentra registrado\n\t";
        getch();
        return;
     }
     trabajador *aux,*a;
     aux=ptra->protra;//asignando
     a=ptra;//bloques de memoria 
     while(aux != NULL){
          if(aux->id==iden){//si lo halla, muestra sus datos para decidir
             system("cls");
             cout<<"\n\t\t\tEliminar trabajador ";
             cout<<"\n\n\tIdentificacion :              "<<aux->id;
             cout<<"\n\tNombre :           "<<aux->nom;
             cout<<"\n\tSalario :       "<<aux->sal<<"\n\t";
             do{
                cout<<"\n\n\tDesea eliminar al trabajador (1. Si - 2. No) :  ";cin>>res;
                
             }while(res<1 || res>2);
             if(res == 1){//borrando
                a->protra=aux->protra;//cambiando espacios de memoria
                delete aux;  //dato borrado
                actualizartra();  
            }     
            return;
         }
          a=aux;//cambiando espacio de memoria
          aux=aux->protra;//lista avanzando
   
         }
}
//actualizando
void actualizartra(){
    trabajador *aux,pro;
     aux=ptra->protra;              //se inicializa el auxiliar para recorrer la lista
     arcTra=fopen("trabajador","w+");              //se borran todos los archivos para cargarlos con la actualizacion
     fclose(arcTra);
     arcTra=fopen("trabajador","a+");              //se inicializa para anexar las estructuras a el archivo
     while(aux != NULL){
           pro.id=aux->id;
           strcpy(pro.nom,aux->nom);
           pro.sal=aux->sal;
           fwrite(&pro,sizeof(struct trabajador),1,arcTra);
           aux=aux->protra;
     }
     fclose(arcTra);//cambios guardados
     
     
     
     }
     //listando
    void listartra(){
     trabajador *aux;
     aux=ptra->protra;
     system("cls");
     cout<<"\n\n\t\tListar trabajadores\n\n";
     while(aux != NULL){//listando empleados 
           cout<<"\n\n\tidentificacion :              "<<aux->id;
           cout<<"\n\tNombre :           "<<aux->nom;
           cout<<"\n\tSalario :       "<<aux->sal;   
           aux=aux->protra;
     }
     cout<<"\n\t";
     getch();
  }
  //cargando trabajadores 
  void loadtrabajador(){       
   if(arcTra==NULL){
         return;             
     }
     trabajador tra;
     arcTra=fopen("trabajador","r");
     fread(&tra,sizeof(struct trabajador),1,arcTra);
     while(!feof(arcTra)){//asigna datos para nuevo encendido de maquina 
           nodotra = new trabajador;
           nodotra->id=tra.id;
           strcpy(nodotra->nom,tra.nom);
           nodotra->sal=tra.sal;
           nodotra->protra=ptra->protra;
           ptra->protra=nodotra;
           fread(&tra,sizeof(struct trabajador),1,arcTra);
     }
     fclose(arcTra);    //carga realizada         
                       
                       
     }     
        //menu de cliente  
void menucli(){
      int op;
   
   do{
      system("cls"); 
       cout<<"\n\tMenu de cliente";
       cout<<"\n\t1.Registrar  ";
       cout<<"\n\t2.Modificar  ";
       cout<<"\n\t3.Consultar  ";
       cout<<"\n\t4.Eliminar  ";
       cout<<"\n\t5.Listar  ";
       cout<<"\n\t6.Salir  ";
       cout<<"\n\n\tDigite la opcion   ";cin>>op;
       switch(op){
       case 1:
            registracli();
            break;
       case 2:
             if(pcli->procli==NULL){//validamos en caso que no se halla registrado nada antes
                 printf("\n\tNo hay clientes registrados  ");
                   getch();
                   }else{
            modificacli();
            }
            break;
       case 3:
             if(pcli->procli==NULL){//validamos en caso que no se halla registrado nada antes
                  printf("\n\tNo hay clientes registrados  ");
                   getch();
                   break;
                   }else{
            consultacli();
            }
            break;
       case 4:
             if(pcli->procli==NULL){//validamos en caso que no se halla registrado nada antes
             printf("\n\tNo hay clientes registrados  ");
                        getch();
                         break;
                        }else{
            eliminacli();
            }
            break;
       case 5:
             if(pcli->procli==NULL){//validamos en caso que no se halla registrado nada antes
             printf("\n\tNo hay clientes registrados  ");
                getch();
                 break;
                }else{
            listacli();
            }
            break;          
       
       }
       actualizarcli();
       }while(op!=6);  
      getch();
     }   
void registracli(){
       long nit;
     do{
          system("cls");
           cout<<"\n\t\t\tRegistrar cliente";
           cout<<"\n\n\tDigite el nit :    ";cin>>nit;
           if(validarcodcli(nit)==true){
              cout<<"\n\n\t\tEl cliente no se halla registrado  ";
              getch();
              return;
           }
     }while(nit<1 || nit >1000);//validando intervalos y existencia de nit
     nodocli= new cliente;//asignando memoria dinamica 
     nodocli->nit=nit;//asignando nit en lista
    cout<<"\n\tDigite identificacion del propietario  ";cin>>nodocli->id;
    
     fflush(stdin);
     cout<<"\n\tDigite el nombre del cliente  :             ";gets(nodocli->nom);//ingresando nombre
     fflush(stdin);
     cout<<"\n\tDigite la direccion           :             ";gets(nodocli->dir);//ingresando direccion 
     /****************llenado del archivo con los datos********************************/
     cli2.nit=nodocli->nit;
     cli2.id=nodocli->id;
     strcpy(cli2.nom,nodocli->nom);
     strcpy(cli2.dir,nodocli->dir);
     arcCli=fopen("cliente","a+");
     fwrite(&nodocli,sizeof (struct cliente),1,arcCli);
     fclose(arcCli);
     /********************************************************************************/
     nodocli->procli=pcli->procli;
     pcli->procli=nodocli;
      
       }
  bool validarcodcli(long nitemp){
      cliente *aux;
     aux=pcli->procli;
     while(aux != NULL){//buscando existencia de nit 
           if(aux->nit == nitemp){
              return true;//si hallo
           }
           aux=aux->procli;
     }
    return false;//si no hallo 
       }  
     //modificando
 void modificacli(){     
      long nit;
     int opc;
          system("cls");
           cout<<"\n\t\t\tModificar cliente ";
           cout<<"\n\n\tDigite el nit :    ";cin>>nit;
           if(validarcodcli(nit)==false){//si no halla no modifica 
              cout<<"\n\n\t\tEl cliente no se halla registrado  ";
              getch();
              return;
           }
           cliente *aux;
           aux=pcli->procli;//asignando bloque de memoria 
           while(aux != NULL){
                 if(aux->nit==nit){//si lo halla, muestra sus atributos 
                    do{
                        system("cls");
                        cout<<"\n\t\t\tModificar cliente  ";
                        cout<<"\n\n\t1. Nit :              "<<aux->nit;
                        cout<<"\n\n\t2.Ident. prop. :      "<<aux->id;
                        cout<<"\n\t3. Nombre :           "<<aux->nom;
                        cout<<"\n\t4. Direccion :       "<<aux->dir;
                        cout<<"\n\t5. Salir.             ";
                        cout<<"\n\n\tDigite la opcion :  ";cin>>opc; 
                       
                        switch(opc){
                                    case 1 :
                                         do{
                                            cout<<"\n\n\tDigite el nit :   ";cin>>aux->nit;
                                            if(validarcodcli(aux->nit) == true){
                                               cout<<"\n\n\tEl nit se encuentra registrado....!";
                                            }
                                         }while(aux->nit <0 || aux->nit>1000 && validarcodcli(aux->nit)==true);//validando intervalos y existencia
                                    break;
                                    case 2:
                                    cout<<"\n\tDigite identificacion de propietario  :  ";cin>>aux->id;//cambia id
                                    
                                    break;
                                    
                                    case 3:
                                         fflush(stdin);
                                         cout<<"\n\n\tDigite el nombre  :   ";gets(aux->nom);//cambia nombre
                                    break;
                                    
                                    case 4:
                                         fflush(stdin);
                                         cout<<"\n\n\tDigite la direccion  :   ";gets(aux->dir);//cambia direccion 
                                    break;
                                    
                        }
                    actualizarcli();
                    }while(opc != 5);
                    return;
                 }
                 aux=aux->procli;
           } 
     } 
//consultando cliente
void consultacli(){
           long nit;
     cout<<"\n\t\t\tConsultar cliente";
     cout<<"\n\n\tDigite el nit : ";cin>>nit;
     if(validarcodcli(nit)==false){//si no esta, puedo no mostrara nada si no esta en lista 
        cout<<"\n\n\n\t\t\a\a\aEl cliente no esta registrado\n\t";
        getch();
        return;
     }
     cliente *aux;
     aux=pcli->procli;//asignando bloque de memoria
     while(aux != NULL){
          if(aux->nit==nit){//si esta el nit en lista, mostrara lo referente a el 
             system("cls");
             cout<<"\n\t\t\tCliente consultado  ";
             cout<<"\n\n\tNit :              "<<aux->nit;
             cout<<"\n\n\tIdent. propietario  :  "<<aux->id;
             cout<<"\n\tNombre :           "<<aux->nom;
             cout<<"\n\tDireccion :       "<<aux->dir<<"\n\t";
             getch();
             return;               
          }
          aux=aux->procli;//lista avanzando 
     }
       
       
  }   
 //eliminando cliente                     
   void eliminacli(){
   long nit;
     int res;
     cout<<"\n\t\t\tConsultar cliente para eliminar  ";
     cout<<"\n\n\tDigite el nit : ";cin>>nit;
     if(validarcodcli(nit)==false){//si no esta, pues no eliminara nada  
        cout<<"\n\n\n\t\t\a\a\aEl cliente no se halla registrado  \n\t";
        getch();
        return;
     }
     cliente *aux,*a;
     aux=pcli->procli;//asignando
     a=pcli;//bloques de memoria para intercambio
     while(aux != NULL){
          if(aux->nit==nit){//si esta en lista, mostrara todo lo referente 
             system("cls");
             cout<<"\n\t\t\tELIMINAR EMPRESA";
             cout<<"\n\n\tNit :              "<<aux->nit;
             cout<<"\n\n\tIdent. propietario  :  "<<aux->id;
             cout<<"\n\tNombre :           "<<aux->nom;
             cout<<"\n\tDireccion :       "<<aux->dir<<"\n\t";
             do{
                cout<<"\n\n\tDesea eliminar cliente (1. Si - 2. No) :  ";cin>>res;
                
             }while(res<1 || res>2);
             if(res == 1){//borrando
                a->procli=aux->procli;//cambiando espacios de memoria
                delete aux;    //dato borrado
              actualizarcli();//actualizando 
             }
         }
          a=aux;//cambiando
          aux=aux->procli;//avanzando lista y bloques de memoria 
    
   }      
}    
    //lista clientes 
void listacli(){
     cliente *aux;
     aux=pcli->procli;//asignando memoria 
     system("cls");
     cout<<"\n\n\t\tListado de clientes  \n\n";
     while(aux != NULL){//listando clientes 
           cout<<"\n\n\tNit :              "<<aux->nit;
           cout<<"\n\tIdent. propietario   "<<aux->id; 
           cout<<"\n\tNombre :           "<<aux->nom;
           cout<<"\n\tDireccion :       "<<aux->dir;   
           aux=aux->procli;//lista avanzando 
     }
     cout<<"\n\t";
     getch();
    }  
//actualizando clientes 
void actualizarcli(){
    cliente *aux,pro;
     aux=pcli->procli;              //se inicializa el auxiliar para recorrer la lista
     arcCli=fopen("cliente","w+");              //se borran todos los archivos para cargarlos con la actualizacion
     fclose(arcCli);
     arcCli=fopen("cliente","a+");              //se inicializa para anexar las estructuras a el archivo
     while(aux != NULL){
           pro.id=aux->id; 
           pro.nit=aux->nit;
           strcpy(pro.nom,aux->nom);
           strcpy(pro.dir,aux->dir);
           fwrite(&pro,sizeof(struct cliente),1,arcCli);
           aux=aux->procli;
     }
     fclose(arcCli);//cambios preservados 
  }
void loadcli(){
     if(arcCli==NULL){
         return;             
     }
     cliente cli;
     arcCli=fopen("cliente","r");//accediendo a fichero 
     fread(&cli,sizeof(struct cliente),1,arcCli);//garantizando flujo de lectura de fichero 
     while(!feof(arcCli)){//cargando datos para lista en nuevo arranque
           nodocli = new cliente;
           nodocli->nit=cli.nit;
           nodocli->id=cli.id;
           strcpy(nodocli->nom,cli.nom);
           strcpy(nodocli->dir,cli.dir);
           nodocli->procli=pcli->procli;
           pcli->procli=nodocli;
           fread(&cli,sizeof(struct cliente),1,arcCli);
     }
     fclose(arcCli);
}     
    //men de gestion            
 void menuges(){
      int opg;
  do{
  system("cls");  
   cout<<"\n\tMenu de gestion de pedido  ";
   cout<<"\n\t1.Registrar  ";
   cout<<"\n\t2.Consultar Lista de ventas de empleado  ";
   cout<<"\n\t3.Eliminar  ";
   cout<<"\n\t4.Salir  ";
  cin>>opg;  
  error(1,4,opg);
 switch(opg){

case 1:
   registrargest(); 
     break;

case 2:
   if(pges->proges==NULL){//validamos en caso que no se halla registrado nada antes
                printf("\n\tNo hay gestiones de pedido registradas  ");
               getch();
               break;
               }
   consulistargest();
   break;

case 3:
     if(pges->proges==NULL){//validamos en caso que no se halla registrado nada antes
     printf("\n\tNo hay gestiones de pedido registradas  ");
         getch();
           break;
           }
   eliminargest();
   break;
      }
}while(opg!=4);
   }     
      
 void registrargest(){
   long int idtra1;
   long nitg,nite;
   long codid;
   int e,dias,y;
   int op=1;
  system("cls");
   cout<<"\n\tingrese identificacion del trabajador que hace la venta ";cin>>idtra1;//validamos si el codigo del trabajador existe 
   if(validarcodtra(idtra1)==false){
   cout<<"\n\tEl codigo del empleado no se encuentra registrado  ";
  }else{
   //si existe...
  

   cout<<"\n\tIngrese nit del cliente  ";cin>>nitg;//validamos si el nit del cliente existe 
   if(validarcodcli(nitg)==false){
   cout<<"\n\tEl nit del cliente no existe  ";
   }else{//si existe...
   nodogestion= new gestion;//asignando memoria para lista de gestion
   nodogestion->idtra=idtra1;//asignando id. de prevendedor 
   nodogestion->nitemp=nitg;//asignando nit de cliente a vender producto 
  
  do{
   cout<<"\n\tIngrese nit de la empresa distribuidora del producto  ";cin>>nite;//digitemos nit de empresa que nos vende el producto
   cout<<"\n\tIngrese codigo del producto a vender  ";cin>>codid;//digitemos codigo de producto a vender

   if(validarpro(nite,codid)==false){
   cout<<"\n\tEl producto o la empresa no existen  ";
   }else{//si existe...
    
        consultarproges(nite,codid);//mostramos todos los atributos del producto que vendemos para que el comprador se interese o decida 
                                    //si comprar o no 


do{
cout<<"\n\tDesea hacer la venta  ?, (1=si) (2=no), ";cin>>e;//decidiendo venta
}while(e<1||e>2);
if(e==1){//si decidio
do{
cout<<"\n\tDigite cantidad del producto a comprar para vender a cliente ";cin>>nodogestion->cant;
}while(nodogestion->cant<1);//asignando cantidad de unidades vendidas

nodogestion->nitempd=nite;//asignando en lista nit de empresa distribuidora que nos vende el producto para poder comercializarlo
nodogestion->idpro=codid;//asignando en lista codigo de producto en bodega

fechacomp capturaevento=fregis(); //capturando fecha de realizacion de venta desde el sistema 
nodogestion->eventoventa.fecm.dia=capturaevento.fecm.dia;//capturando dia de venta
nodogestion->eventoventa.fecm.mes=capturaevento.fecm.mes;//capturando mes de venta
nodogestion->eventoventa.fecm.ano=capturaevento.fecm.ano;//capturando año de venta
strcpy(nodogestion->eventoventa.hora,capturaevento.hora);//capturando hora de venta
strcpy(nodogestion->entrega.hora2,nodogestion->eventoventa.hora);//guardando hora de venta para saber hora de entrega
if(capturaevento.fecm.mes==1||capturaevento.fecm.mes==3||capturaevento.fecm.mes==5||capturaevento.fecm.mes==7||capturaevento.fecm.mes==8||capturaevento.fecm.mes==10||capturaevento.fecm.mes==12){
y=1;//cerciorando auxiliar y para saber condicionarl respecto a numero de mes de venta 
}else{
      y=2;//cerciorando auxiliar y para saber condicionarl respecto a numero de mes de venta 
      }


    do{
    cout<<"\n\tDigite plazo en dias  (15 dias limite )";cin>>dias;
    }while(dias<1||dias>15);//digitando plazo de dias para entrega del producto
    nodogestion->plazo=dias;//asignando plazo
    //calculando fecha de entrega respecto a dias, meses y años
    if(nodogestion->entrega.mes2=capturaevento.fecm.mes){
    nodogestion->entrega.dia2=nodogestion->eventoventa.fecm.dia+dias;
    nodogestion->entrega.ano2=nodogestion->eventoventa.fecm.ano;
      }
    if(y==2){
    if(nodogestion->eventoventa.fecm.dia+dias>30){
    nodogestion->entrega.dia2=nodogestion->eventoventa.fecm.dia+dias-30;
    nodogestion->entrega.mes2=nodogestion->eventoventa.fecm.mes+1;
         }
         }else{
       if(nodogestion->eventoventa.fecm.dia+dias>31){
       nodogestion->entrega.dia2=nodogestion->eventoventa.fecm.dia+dias-31;
       nodogestion->entrega.mes2=nodogestion->eventoventa.fecm.mes+1;
      }
      if((nodogestion->eventoventa.fecm.mes==12)&&(nodogestion->eventoventa.fecm.dia+dias>31)){
       nodogestion->entrega.dia2=nodogestion->eventoventa.fecm.dia+dias-31;
       nodogestion->entrega.mes2=1;     
       nodogestion->entrega.ano2=nodogestion->eventoventa.fecm.ano+1;
        }
     }
     //mostrando fecha de venta y entrega 
cout<<"\n\tFecha de venta  ";
cout<<"\n\tDia  "<<nodogestion->eventoventa.fecm.dia;
cout<<"\n\tMes  "<<nodogestion->eventoventa.fecm.mes;
cout<<"\n\tAño  "<<nodogestion->eventoventa.fecm.ano;
cout<<"\n\tHora  "<<nodogestion->eventoventa.hora;
cout<<"\n\n";
cout<<"\n\tFecha de entrega  ";
cout<<"\n\tDia  "<<nodogestion->entrega.dia2;
cout<<"\n\tMes  "<<nodogestion->entrega.mes2;
cout<<"\n\tAño  "<<nodogestion->entrega.ano2;
cout<<"\n\tHora  "<<nodogestion->entrega.hora2;

}
}



cout<<"\n\tPara realizar mas ventas presione 1  ";cin>>op;//decidiendo nueva venta 


/*Llenando datos al fichero sobre realizacion de venta  */
ges1.idtra=nodogestion->idtra;
ges1.nitemp=nodogestion->nitemp;
ges1.idpro=nodogestion->idpro;
ges1.nitempd=nodogestion->nitempd;
ges1.cant=nodogestion->cant;
ges1.plazo=nodogestion->plazo;
ges1.eventoventa.fecm.dia=nodogestion->eventoventa.fecm.dia;
ges1.eventoventa.fecm.mes=nodogestion->eventoventa.fecm.mes;
ges1.eventoventa.fecm.ano=nodogestion->eventoventa.fecm.ano;
strcpy(ges1.eventoventa.hora,nodogestion->eventoventa.hora);
ges1.entrega.dia2=nodogestion->entrega.dia2;
ges1.entrega.mes2=nodogestion->entrega.mes2;
ges1.entrega.ano2=nodogestion->entrega.ano2;
strcpy(ges1.entrega.hora2,nodogestion->entrega.hora2);
arcGes=fopen("gestion","a+");
fwrite(&ges1,sizeof(struct gestion),1,arcGes);
fclose(arcGes);
/*****************************************************************/
nodogestion->proges=pges->proges;//avanzando lista para reservar espacios de memoria 
pges->proges=nodogestion;
     }while(op==1);

}
}
      getch();
}     
  //consultar gestion
  void consulistargest(){
     long int idtra;
    system("cls");
     gestion *aux;
    cout<<"\n\tDigite codigo del prevendedor  ";cin>>idtra;
    if(validarcodtra(idtra)==true){//si el codigo del prevendedor existe, muestra la lista 
    aux=pges->proges;//asignando espacio de memoria
     while(aux!=NULL){
          if(aux->idtra==idtra){//condicional adicional que nos permite ver con mas certeza si el trabajador existe y que venta hizo 
           cout<<"\n\tidentificacion del producto  "<<aux->idpro;
           cout<<"\n\tcantidad de unidades vendidas del producto  "<<aux->cant;
           cout<<"\n\tFecha de realizacion de venta   ";
           cout<<"\n\tDia  "<<aux->eventoventa.fecm.dia;  
           cout<<"\n\tMes  "<<aux->eventoventa.fecm.mes;  
           cout<<"\n\tAño  "<<aux->eventoventa.fecm.ano;
           cout<<"\n\tHora  "<<aux->eventoventa.hora;
           cout<<"\n";  
           cout<<"\n\tFecha de entrega de venta  ";
           cout<<"\n\tDia  "<<aux->entrega.dia2;  
           cout<<"\n\tMes  "<<aux->entrega.mes2;  
           cout<<"\n\tAño  "<<aux->entrega.ano2;
           cout<<"\n\tHora  "<<aux->entrega.hora2;
          getch();
           return;
           }
             aux=aux->proges;//lista avanzando 
           
             }
     
     }else{
           cout<<"\n\tEl vendedor no existe  ";
     }
     getch();
     }     
      //elimnar gestion 
       void eliminargest(){
       int eli,codid;
      system("cls");
      
  cout<<"\n\tDigite identificacion de vendedor a eliminar  ";cin>>codid;
     if(validarcodtra(codid)==false){//cerciorandonos si el vendedor existe o no
     cout<<"\n\tEl numero de identificacion del vendedor no existe";
     }else{//si existe...
        
       gestion *aux,*a;
       aux=pges->proges;//asignando bloques de memoria
       a=pges;
       while(aux!=NULL){
       if(aux->idtra==codid){//si se halla en lista, muestra lo relacionado con la venta 
           cout<<"\n\tidentificacion del producto  "<<aux->idpro;
           cout<<"\n\tcantidad de unidades vendidas del producto  "<<aux->cant;
           cout<<"\n\tFecha de realizacion de venta   ";
           cout<<"\n\tDia  "<<aux->eventoventa.fecm.dia;  
           cout<<"\n\tMes  "<<aux->eventoventa.fecm.mes;  
           cout<<"\n\tAño  "<<aux->eventoventa.fecm.ano;
           cout<<"\n\tHora  "<<aux->eventoventa.hora;
           cout<<"\n";  
           cout<<"\n\tFecha de entrega de venta  ";
           cout<<"\n\tDia  "<<aux->entrega.dia2;  
           cout<<"\n\tMes  "<<aux->entrega.mes2;  
           cout<<"\n\tAño  "<<aux->entrega.ano2;
           cout<<"\n\tHora  "<<aux->entrega.hora2;   
          cout<<"\n\n";
           do{
             cout<<"\n\tDesea eliminar la venta  (1=si) (2=no)";cin>>eli;               
            error(1,2,eli);
           }while(eli<1||eli>2);    
           if(eli==1){//borrando
          
             a->proges=aux->proges;//cambiando bloques de memoria         
             delete aux;//borrando dato
             actualizages();//actualizando 
              
           }                  
       return;              
       }
       a=aux;//cambiando
       aux=aux->proges;//y lista avanzando
       }
       }
    
       }   
       
       //actualiza gestion
       void actualizages(){
         gestion *aux,pro;
         aux=pges->proges;//asignando memoria
         arcGes=fopen("gestion","w+");//reescribiendo fichero
         fclose(arcGes);
         arcGes=fopen("gestion","a+");
         while(aux!=NULL){//cambiando lista miembro a miembro 
          pro.idtra=aux->idtra;                
          pro.nitemp=aux->nitemp;
          pro.nitempd=aux->nitempd;  
          pro.idpro=aux->idpro;    
          pro.cant=aux->cant;
          pro.plazo=aux->plazo;
          pro.eventoventa.fecm.dia=aux->eventoventa.fecm.dia;
          pro.eventoventa.fecm.mes=aux->eventoventa.fecm.mes;
          pro.eventoventa.fecm.ano=aux->eventoventa.fecm.ano;
          strcpy(pro.eventoventa.hora,aux->eventoventa.hora);
          pro.entrega.dia2=aux->entrega.dia2;
          pro.entrega.mes2=aux->entrega.mes2;
          pro.entrega.ano2=aux->entrega.ano2;
          strcpy(pro.entrega.hora2,aux->entrega.hora2);
         fwrite(&pro,sizeof(struct gestion),1,arcGes);
          aux=aux->proges;
        
         }
         fclose(arcGes);//cambios preservados 
         }
         //cargando gestion
         void loadges(){
         if(arcGes==NULL){
                return;          
         }
         gestion ges;
         arcGes=fopen("gestion","r");//accediendo a datos de fichero 
         fread(&ges,sizeof(struct gestion),1,arcGes);//flujo de datos
         while(!feof(arcGes)){//asignando datos a lista en nuevo arranque 
         nodogestion= new gestion;
         nodogestion->idtra=ges.idtra;                
         nodogestion->nitemp=ges.nitemp;
         nodogestion->nitempd=ges.nitempd;  
         nodogestion->idpro=ges.idpro;    
         nodogestion->cant=ges.cant;
         nodogestion->plazo=ges.plazo;
         nodogestion->eventoventa.fecm.dia=ges.eventoventa.fecm.dia;
         nodogestion->eventoventa.fecm.mes=ges.eventoventa.fecm.mes;
         nodogestion->eventoventa.fecm.ano=ges.eventoventa.fecm.ano;
         strcpy(nodogestion->eventoventa.hora,ges.eventoventa.hora);
         nodogestion->entrega.dia2=ges.entrega.dia2;
         nodogestion->entrega.mes2=ges.entrega.mes2;
         nodogestion->entrega.ano2=ges.entrega.ano2;
         strcpy(nodogestion->entrega.hora2,ges.entrega.hora2);
           nodogestion->proges=pges->proges;
           pges->proges=nodogestion;
           fread(&ges,sizeof(struct gestion),1,arcGes);
         
         }
          fclose(arcGes);//carga realizada 
         }     
      //consulta producto de gestion: permite ver lo relacionado con producto a vender en momento de gestion de pedido 
 void consultarproges(long codem, long codid){
    producto *aux;
    if(validarpro(codem,codid)==false){
    cout<<"\n\tLa empresa y/o el codigo del producto no se encuentran registrados  ";                             
    getch();
    return;
    }
     aux=ppro->propro;//asignando memoria 
     while(aux != NULL){
          if(aux->idem ==codem && aux->id==codid){//mostrando atributos, si esta en lista 
                  cout<<"\n\n\tCodigo de la empresa       :       "<<aux->idem;
                  cout<<"\n\tCodigo del producto        :       "<<aux->id; 
                  cout<<"\n\tNombre del producto        :       "<<aux->nom;
                  cout<<"\n\tCodigo invima              :       "<<aux->codinv;
                  cout<<"\n\tCodigo de comercializacion :       "<<aux->codcom;
                  cout<<"\n\tFecha de vencimiento       :       "<<aux->ven.dia<<" / "<<aux->ven.mes<<" / "<<aux->ven.ano;           
                  return;
          }    
          aux=aux->propro; //avanzando 
     }
      
      
      
      
      }      
     
     
     
     
     
     
             
           
           
/********************Fin de de cargado de informacion**********************/
/*******Utilidades***********/
//void mensage:se encarga de generar un mensage 
void mensage(char m['s']){
     cout<<"\n\n\t"<<m<<"....!";
     getch();
}                                 
/***Fin Utilidades***********/
/*******funciones de manejo de fecha***********/
fechacomp fregis(){//averiguando fecha y hora del sistema 
  fechacomp aux;
  time_t tiempo;
  char cad[80],*p,nom['v'];//estas variables y el puntero char ayudaran a saber cual es la fecha del sistema 
  int num=80,*c;
  p=&cad[0];//tomando espacio de memoria con operador unario
  c=&num;//tomando espacio de memoria con operador unario
  struct tm *tmPtr;//puntero con tipo de dato tm que permite acceder a fecha y hora  del sistema 
  tiempo = time(NULL);//tomando fecha y hora
  tmPtr = localtime(&tiempo);//capturando fecha y hora
  strftime( cad, 80, "%H:%M:%S, %d de %m de %Y", tmPtr );//funcion que permite transferir la fecha y hora del puntero tmPtr a variable char cad[80]
  cortar(nom,cad);  //llamando a funcion separadora de fecha y hora
 fechas(&aux.fecm.dia,&aux.fecm.mes,&aux.fecm.ano,cad);//funcion obteniee fecha de sistema
  strcpy(aux.hora,nom);//obteniendo hora del sistema para determinar vencimiento de producto y gestion de pedido 
 return aux;
}

int menuchartoint(char j){//funcion que permite tomar cada numero en varible char y convertirlo en entero uno por uno para saber fecha y transferirla
    switch(j){
        case '0':      
              return 0;
         break;     
        case '1':

             return 1;
        break;   
        
        case '2':
             return 2;
        break;
        
        case '3':
             return 3;
        break;
        
        case '4':
             return 4;
        break;
        
        case '5':
             return 5;
        break;
        
        case '6':
             return 6;
        break;
        
        case '7':
             return 7;
        break;
        
        case '8':
             return 8;
        break;
        
        case '9':
             return 9;
        break;   
              
        }       
     } 
     
void cortar(char *h,char *f){
     
    int i=0,w=0,w2=0,e=0;
    char aux[8],aux2[16];//variables auxliares para separar fecha y hora
    while(f[i] != '\0'){//en estos ciclos
               if(f[i]==','){//separaramos la hora teniendo en cuenta el signo de separacion del sistema que es una coma, aunque la vemos como ":"
                  while(f[w] != ','){

                        aux[w]=f[w];//separando datos de char uno a uno
                        w++;
                  }
                  strcpy(h,aux); //obteniendo hora 
                  e=i+1;//variable auxiliar iteradora que ayuda a tener fecha
                  while(f[e] != '\0'){//en este ciclo obtenemos la fecha
                             aux2[w2]=f[e];//pasando numeros de fecha uno a uno
                             w2++;//iterados auxiliar de fecha avanzando
                             e++;}//fin de ciclo
                             strcpy(f,aux2);//obteniendo fecha 
                  return;         
               }
               i++;//avanzando ciclo hasta llegar a null para tener fecha y hora 
    }
}
void fechas(int *d,int *m,int *a,char *fecha){//funcion para tener fecha final 
    int d1,d2,m1,m2,a1,a2,a3,a4;
    for(int v=0;v<17;v++){//al avanzar los 17 caracteres en los que se halla la fecha aun dispersa
          if(v==1){//llamamos de acuerdo a su ubicacion en la variable cad[80], llamamos a la funcion que convierte 
          d1=menuchartoint(fecha[v]);//char a int y multiplicamos cada variable de acuerdo al orden cronologico de los datos
          d1*=10;//aqui tenemos la decena del dia
          }
          if(v==2){
          d2=menuchartoint(fecha[v]);//unidad de dia
          
          }
          
          if(v==7){
          m1=menuchartoint(fecha[v]);
          m1*=10;//decena de mes
          }
          if(v==8){
            m2=menuchartoint(fecha[v]);   //unidad de mes    
                   }
                   
          if(v==13){
            a1=menuchartoint(fecha[v]);
            a1*=1000;//unidad de mil de año        
                    }
           if(v==14){
           a2=menuchartoint(fecha[v]);
            a2*=100; //centena de año       
           }
            if(v==15){
            a3=menuchartoint(fecha[v]);
            a3*=10;  //decena de año                
            }
            if(v==16){
            a4=menuchartoint(fecha[v]); //unidad de año
            
           }
        }//calculando despues de ciclo las fecha mediante la suma de unidades obtenidas en bucle para saber la fecha final
*d=d1+d2;
*m=m1+m2;
*a=a1+a2+a3+a4;//los datos de la suma se transfiere en punteros que pasan datos por parametro por referencia, por eso los parametros son punteros
}
