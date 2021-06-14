#include <stdio.h>
#define N 19
int main( void )
{
   int i, n;
   char digitos[N];
   printf( "Escribe un numero de %d digitos como maximo: ", N );
   fflush( stdout );
   scanf ("%s",digitos);
   /*cuento los digitos*/
   for (n=0;digitos[n]!='\0';n++);
  /*los imprimo*/
   for (i=0;i<n;i++)
    printf ("%3c",digitos[i]);
   return 0;
}
