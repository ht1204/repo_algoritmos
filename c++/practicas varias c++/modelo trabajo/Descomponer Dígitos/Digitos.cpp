#include <stdio.h>
#define N 19
 
int main( void )
{
   int c, i, n;
   int digitos[N];
   unsigned long long int num;
 
   printf( "Escribe un numero de %d digitos como maximo: ", N );
   fflush( stdout );
   num = 0;
   for( n = 0; n < N && (c = getchar()) != '\n'; n++ )
   {
      digitos[n] = c - '0';
      num *= 10;
      num += digitos[n];
   }
   printf( "Digitos: " );
   for( i = 0; i < n; ++i )
      printf( " %3d,", digitos[i] );
   return 0;
}
