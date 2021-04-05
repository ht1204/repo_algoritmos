#Leer un número de 4 dígitos, mostrar el dígito mayor e informar si es par o impar.
#Leer dos números de 3 dígitos cada uno, formar un tercer número con el mayor del primero y el menor del segundo.
#Leer un número de 3 dígitos y formar el mayor número posible con sus cifras.
#Salir

#Inicio Función
def descomponerCifras(num):
    auxNumber=num
    residuo=0
    cifras=[]
    strOddEven=''
    i=0
    
#Descomponer el número ingresado y obtener las cifras descompuestas.
#Descompone de la última a la primera cifra.    
    while(auxNumber>0):
        residuo = auxNumber % 10
        auxNumber = auxNumber // 10
        cifras.insert(i,residuo)
        i=i+1

    
    return cifras
#Fin función


#Inicio Función
def obtieneMayor(num):
    cifras=descomponerCifras(num)

#Obtener la primera cifra descompuesta 
    maxDigit=cifras[0]

#Recorrer el arreglo de cifras y se compara hasta tener la mayor.    
    for item in range(1,len(cifras)):
        if(cifras[item] > maxDigit):
            maxDigit = cifras[item]

    return maxDigit

#Fin función
   
    

#Inicio función
def obtieneMenor(num):
    cifras=descomponerCifras(num)
#Obtener la primera cifra descompuesta 
    minDigit=cifras[0]

#Recorrer el arreglo de cifras y se compara hasta tener la mayor.    
    for item in range(1,len(cifras)):
        if(cifras[item] < minDigit):
            minDigit = cifras[item]

    return minDigit
#Fin función



#Función menú
def menu(option,num1,num2):
   # Compara opciones seleccionadas
   if(option == 1):
       return op1(num1)
   elif(option == 2):
       return op2(num1, num2)
   elif(option == 3):
       return op3(num1)
   else:
       return op4()
#Fin función menú

   

#Inicio de función    
def op1(num1):
    maxDigit=obtieneMayor(num1)
            
#evalúa si la cifra o digito mayor es par o impar.
    if(maxDigit % 2 == 0):
        strOddEven='par'
    else:
        strOddEven='impar'

    return(maxDigit, strOddEven) #Salida con ese formato (numero, 'par'/'impar')
#Fin de función


#Inicio de función               
def op2(num1, num2):
    
    maxDigitNumber1=obtieneMayor(num1)
    minDigitNumber2=obtieneMenor(num2)
    resultNumber=maxDigitNumber1 * 10 + minDigitNumber2
    
    return resultNumber # Salida un numero conformado por el digito mayor de num1 y el menor de num2
#Fin de función


#Inicio de función     
def op3(num1):
    cifras=descomponerCifras(num1)

    #Recorrer arreglo y ordenar por método de burbuja
    for i in range(len(cifras)-1):
        for j in range(0,len(cifras)-i-1):
            if(cifras[j] < cifras[j+1]):
                #Asignación múltiple, intercambia valores de mayor a menor por recorrido
                cifras[j], cifras[j+1] = cifras[j+1], cifras[j] 
              
    
    result=0
    decimalMultiplier = 100 #Base 100 para crear nuevo número de tres cifras

    #Recorre el arreglo de cifras y se crea el número nuevo ordenado de mayor a menor.
    for i in range(0,len(cifras)):
        result = result + cifras[i] * decimalMultiplier
        decimalMultiplier = decimalMultiplier // 10
    
  
    return result # Salida numero de 3 digitos ordenados de mayor a menor 
#Fin de función    


#Inicio de función  
def op4():
    return "Salir" # Salida "Salir"
#Fin de función        

#Función principal, usuario digita opciones y obtiene resultados.
def main():
    op=0
    strExit=''
    numero1=0
    numero2=0

    while(strExit != "Salir"):
        print('Menú principal')
        print('1-Analizar número de 4 dígitos - digito mayor-par-impar')
        print('2-Ingresar números de 3 dígitos cada uno')
        print('3-Ingresar número de 3 dígitos y formar el mayor número posible con sus cifras')
        print('4-Salir')
        print('')
        op=int(input('Ingrese Opción de menú : '))
        print('')
        
        if(op == 1):
            while(numero1<1000 or numero1 > 9999):
                numero1=0
                numero2=0
                
                numero1=int(input('Ingrese numero de cuatro digitos : '))
                numero2=0
        elif(op == 2):
            numero1=0
            numero2=0
            
            while(numero1<100 or numero1 > 999):
                numero1=int(input('Ingrese numero 1 de tres digitos : '))
            while(numero2<100 or numero2 > 999):
                numero2=int(input('Ingrese numero 2 de tres digitos : '))
        elif(op == 3):
            numero1=0
            numero2=0
            
            while(numero1<100 or numero1 > 999):
                numero1=int(input('Ingrese numero 1 de tres digitos : '))
                numero2=0
        else:
            #Opción salir
            strExit=menu(op,numero1,numero2)
            

        #Resultado opciones 1-3    
        result = menu(op,numero1,numero2)
        print(result)
        print('')
        print('')
        
#Fin función principal

#Ejecución función principal
if __name__ == "__main__":
    main()
