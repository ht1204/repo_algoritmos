clc;
clear all;

continuar=1;

while (continuar)

    %Ingresar funci�n
    str = input('Ingresa ecuaci�n en x: ','s');
    f = inline(str,'x');
    
    %Establecer intervalo
    a=input('Ingrese l�mite inferior de intervalo:  ');
    
    do
      b=input('Ingrese l�mite superior de intervalo:  ');
    until b>a
    
    
    %Tipo de orden: la cantidad de subintervalos debe ser m�ltiplo de tres
    do
      n=input('Ingrese cantidad de subintervalos:  ');
      
      if mod(n,3) ~= 0
        disp("La cantidad de subintervalos debe ser m�ltiplo de 3");
      end
      
      
    until mod(n,3)==0
    
    

    h=(b-a)/n;% tama�o de paso
  
  %realiza operaci�n
 
    sum=f(a);
    x(1)=a;
   for i=2:n
    x(i)=x(i-1)+h;
    end
   for j=2:3:n
    sum=sum+3*f(x(j));
   end
   for k=3:3:n
    sum=sum+3*f(x(k));
   end
   for l=4:3:n
    sum=sum+2*f(x(l));
   end
  
   sum=sum+f(b);
   int=sum*3*h/8;
   disp("Resultado Simpson 3/8");
   disp(int);
  
  
    
  continuar = menu('�Desea continuar?','Si','No');
  if continuar==2
    break;
  end
end

    


