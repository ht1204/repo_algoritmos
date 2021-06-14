####  Function finalVector ######
def finalVector(initialVector):
  finalLstVector = []
  
  for elem in initialVector:
    finalLstVector.append(elem*3)

  return finalLstVector
############# End of function ################## 

####  Function createInitialVector ######
def createInitialVector(n):
  initialLstVector = []

  for i in range(1, n+1):
    nData=validateInputNumericData(2, i)
    initialLstVector.append(nData)

  return initialLstVector
############# End of function ################## 

####  Function validateInputNumericData(): ######
def validateInputNumericData(inputOption, index):
  value=0.0
  num=0.0

  if(inputOption == 1):
    while(True):
      while(True):
        try:
          value=int(input('Ingrese Dimensión : '))
        except ValueError:
          print('Por favor, ingrese dimensión ')
        else:
          break

      if(value <= 0):
        print('La dimensión debe ser positiva ')
      else:
        break
  else:
    while(True):
      try:
        value=float(input(f"Ingrese registro {index} : "))
      except ValueError:
        print('Por favor, ingrese registro numérico ')
      else:
        break


  num = value  

  return num

############# End of function ################## 

####  Function assignDimension ######
def assignDimension():
  
  n=0
  n=validateInputNumericData(1,0) 
  return n
############# End of function ################## 

### Function Main #####
def main():

  #Cadena para aplicar formato aproximación dos cifras decimales
  formatDecimalPlaces="{:.2f}"

  nDimension=assignDimension()
  print()
  initialVector=createInitialVector(nDimension)
  print()
  fVector=finalVector(initialVector)
  print()
  print('Vector Inicial - Vector Final')

  #Se iteran dos listas en un mismo ciclo for-in
  for i,j in zip(initialVector, fVector):
    print(i, ' | ',formatDecimalPlaces.format(j))

############# End of function ##################

###Execute Function main ######
if __name__ == '__main__':
  main()