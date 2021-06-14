import math #Library for math functions 


####  Function pointOne ######
def pointOne(n):
  coordPointOne = []

  for i in range(1, n+1):
    nData=validateInputNumericData(2)
    coordPointOne.append(nData)

  return coordPointOne
############# End of function ################## 

####  Function pointTwo ######
def pointTwo(n):
  coordPointTwo = []

  for i in range(1, n+1):
    nData=validateInputNumericData(2)
    coordPointTwo.append(nData)

  return coordPointTwo
############# End of function ################## 


####  Function validateInputNumericData(): ######
def validateInputNumericData(inputOption):
  value=0.0
  num=0.0

  if(inputOption == 1):
    while(True):
      while(True):
        try:
          value=int(input('Ingrese Dimensión Vectorial : '))
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
        value=float(input("Ingrese coord. : "))
      except ValueError:
        print('Por favor, ingrese coordenada ')
      else:
        break

  num = value  

  return num
############# End of function ################## 

####  Function assignDimension ######
def assignDimension():
  
  n=0
  n=validateInputNumericData(1) 
  return n
############# End of function ################## 

####  Function euclideanDistance ######
def euclideanDistance(pointOneEuc, pointTwoEuc):
  distPoints=0.0
  sumDiffCoords=0.0

  for p1, p2 in zip(pointOneEuc, pointTwoEuc):
    sumDiffCoords += (p1-p2)**2

  distPoints = math.sqrt(sumDiffCoords)
  return distPoints
############# End of function ################## 



### Function Main #####
def main():

  #Cadena para aplicar formato aproximación dos cifras decimales
  formatDecimalPlaces="{:.2f}"

  nDimension=assignDimension()
  print()
  print('Coordenadas punto 1')
  pointOneEuc=pointOne(nDimension)
  print()
  print('Coordenadas punto 2')
  pointTwoEuc=pointTwo(nDimension)
  print()
  eucDist=euclideanDistance(pointOneEuc, pointTwoEuc)
  print('Distancia Euclideana: '+formatDecimalPlaces.format(eucDist))




############# End of function ##################

###Execute Function main ######
if __name__ == '__main__':
  main()