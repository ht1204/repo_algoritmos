def inputNumber(order):
  value = 0
  if(order == "inputX"):
    while(True):
      while(True):
        try:
          value=float(input('Ingrese X  : '))
        except ValueError:
          print('Por favor, ingrese numero x ')
        else:
            break

      if(value <= 0 or value > 1):
          print('Debe x mayor a cero y menor e igual a uno ')
      else:
          break

  if(order == "inputN"):
    while(True):
      while(True):
        try:
          value=int(input('Ingrese n-terminos : '))
        except ValueError:
          print('Por favor, ingrese numero ')
        else:
            break

      if(value < 1 or value > 1000):
          print('Ingrese entre uno hasta mil terminos ')
      else:
          break    

  return value


def potencia(x, iteracion):
  if(iteracion <= 1):
    return 1
  
  for i in range(1, iteracion + 1):
    x *= x
  
  return x

def factorial(iteracion):
  if(iteracion <= 1):
    return 1

  else:
    fact = 1
    for i in range(1, iteracion + 1):
      fact *= i
  
    return fact    


def series():
  x=inputNumber("inputX")
  n=inputNumber("inputN")

  sumaSerie=0

  for i in range(0, n):
    sumaSerie += potencia(x, i) / factorial(i)

  print("\nResultado suma de serie : ",sumaSerie)




### Function Main #####
def main():
  series()

############# End of function ##################

###Execute Function main ######
if __name__ == '__main__':
  main()