
def cantidadNumeros(order):
  value = 0
  if(order == "cantidad"):
    while(True):
      while(True):
        try:
          value=int(input('Ingrese cantidad de numeros : '))
        except ValueError:
          print('Por favor, ingrese cantidad ')
        else:
            break

      if(value <= 0):
          print('Debe haber al menos un numero ')
      else:
          break

  if(order == "input"):
    while(True):
      while(True):
        try:
          value=int(input('Ingrese numero : '))
        except ValueError:
          print('Por favor, ingrese numero ')
        else:
            break

      if(value < 1000 or value > 9999):
          print('El numero debe tener cuatro (4) cifras ')
      else:
          break    

  return value


def analizadorCifras(numero):
  numAux = numero

  i, digitosPar, digitosImpar = 0,0,0

  while(numAux > 0):
    cifra = numAux % 10

    if(i % 2 == 0):
      digitosPar += cifra
    else:
      digitosImpar += cifra
    
    numAux = numAux // 10
    i += 1

  if(digitosImpar == digitosPar):
    return True
  
  return False



def analizaNumeros(numeros):
  print('\n\tListado numeros')
  flag = False
  for i in range(len(numeros)):
    if(analizadorCifras(numeros[i])):
      print("\n\t", numeros[i])
      flag = True
  
  if(not flag):
    print("\n\tNingun numero cumple el criterio")

  


def ingresaNumeros():
  cantidad = cantidadNumeros("cantidad")
  numeros = []

  for i in range(0, cantidad):
    numero=cantidadNumeros("input")
    numeros.append(numero)
  print('\n\tNumeros ingresados en sistema, \n\tse procede a evaluar criterio de cifras\n\n')
  analizaNumeros(numeros)
 
 
### Function Main #####
def main():
  ingresaNumeros()

############# End of function ##################

###Execute Function main ######
if __name__ == '__main__':
  main()