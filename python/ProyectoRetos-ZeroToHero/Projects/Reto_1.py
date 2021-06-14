####  Function ingredientesVegetarianos ######
def ingredientesVegetarianos():
  return ['Pimiento','Tofu']
############# End of function ################## 

####  Function ingredientesNoVegetarianos ######
def ingredientesNoVegetarianos():
  return ['Pepperoni','Jamón','Salmón']
############# End of function ##################  

#### Function defaultIngredientes ####
def defaultIngredientes():
  return ['Mozzarella','Tomate']

############# End of function ##################  

### Function subMenuSelection ###
def subMenuSelection(lstIngredientes):
  value=0
  option=0

  for i in range(0,len(lstIngredientes)):
    print(f"{i+1}-{lstIngredientes[i]}")
  
  print()
  #Validación rango ingreso de dato
  while(True):
    #Validación ingreso de dato
    while(True):
      try:
        value=int(input())
      except ValueError:
        print('Por favor, ingrese opción adecuada ')
      else:
        break
    if(value < 1 or value > len(lstIngredientes)):
      print('Debe seleccionar uno de los ingredientes')
    else:
      break 

  option = value

  #Retorna ingrediente en posición en memoria: opciónSeleccionada - 1
  return lstIngredientes[option-1] 
  
############# End of function ##################  

### Function selectedPizza ####
def selectedPizza(option):
  return 'Vegetariana' if(option == 1) else 'No Vegetariana'

  """
  #Lo anterior es operador ternario, es lo mismo que lo siguiente:
  if(option == 1):
    return 'Vegetariana'
  else:
    return 'No Vegetariana'
 """ 
############# End of function ##################  

### Function report ####
def report(option, ingPizza):
  commaSeparator=", "
  print('Tipo de pizza seleccionada : '+selectedPizza(option))
  print('Ingredientes : '+str(commaSeparator.join(ingPizza)))

############# End of function ##################  

### Functión menu ###
def menu():
  ingVeg=ingredientesVegetarianos()
  ingNotVeg=ingredientesNoVegetarianos()
  ingPizza = defaultIngredientes()
  value=0
  option=0
  selectedIngredient=''

  menuSelection='Seleccione\n\t 1-Ingredientes vegetarianos \n\t 2-Ingredientes no vegetarianos\n\t'

  #Validación rango ingreso de dato
  while(True):
    #Validación ingreso de dato
    while(True):
      try:
        print(menuSelection)
        print()
        value=int(input())
      except ValueError:
        print('Por favor, ingrese opción adecuada ')
      else:
        break

    if(value < 1 or value >2):
      print('La opción debe ser uno (1) o dos (2)')
    else:
      break  
        
  option = value 
  print()
  print('Seleccione uno de los siguientes ingredientes :') 

  if(option == 1):
    selectedIngredient=subMenuSelection(ingVeg)
  else:
    selectedIngredient=subMenuSelection(ingNotVeg)

  print()
  ingPizza.append(selectedIngredient)
  report(option, ingPizza)

############# End of function ##################  

###Execute Function Menu ######
if __name__ == '__main__':
  menu()
