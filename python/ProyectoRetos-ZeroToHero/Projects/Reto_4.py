
##Modelo
### Start: Clase Person
class Person:

  #self: palabra reservada, indica mismo contexto de entidad.

  #Constructor por defecto
  #Recomendable
  #Es opcional codificarlo debido a que se genera por defecto
  #al crear la clase. Sin embargo, es bueno conocer su estructura.
  def __init__(self):
    pass #Continúa ejecución en python, buena práctica.
  

  #Constructor con paramétros
  #En software, no es una buena práctica de seguridad, pero 
  #es útil cuando se empieza en Prog. Orientada a Objetos
  #Puede ser usado también para crear objetos fácilmente.
  """
  def __init__(self, name, age, weight):
    self.__name=name
    self.__age=age
    self.__weight=weight
  """
  
  #Setters and getters
  def setName(self, name):
    self.__name=name
  
  def getName(self):
    return self.__name

  def setAge(self, age):
    self.__age = age
  
  def getAge(self):
    return self.__age

  def setWeight(self, weight):
    self.__weight=weight
  
  def getWeight(self):
    return self.__weight
  ###################

  ##Saludar a otra persona
  def greetPerson(self,person):
    print('Hola '+person.getName())

############ End of class ##############
###fin Modelo


#### Start: Clase PersonContainer #####
### Este es un contenedor de objeto clase Persona
### Brinda encapsulación y seguridad.
### Esto se le conoce como inyección de dependencias
class PersonContainer:
  
  ##Sobrecarga de constructores:
  ##Constructor por defecto y paramétrizado.
  def __init__(self):
    pass

  def __init__(self,lstPersonAttr):
    self.__person=Person()
    self.__person.setName(lstPersonAttr[0])
    self.__person.setAge(lstPersonAttr[1])
    self.__person.setWeight(lstPersonAttr[2])

    """ 
    #Si se utiliza constructor parametrizado, aplicar lo siguiente.
    self.__person=Person(
                        lstPersonAttr[0],
                        lstPersonAttr[1],
                        lstPersonAttr[2]
                        )
    """                 
      

  ## setter & getter objeto Persona ####
  def setPerson(self, person):
    self.__person=person
  
  def getPerson(self):
    return self.__person
  ############################

############ End of class ##############

## Start: Clase Validator####
### Se especializa en manejo de ingreso de datos
class Validator:
  def __init__(self):
    pass  

####  Function stringValidator ######
  def stringValidator(self,strAux):
    return True if(strAux == '') else False
############# End of function ################## 

####  Function intNumericValidator ######
  def intNumericValidator(self, value, optionInput):
    strMsg=''
    strAttr=''
  
    if(optionInput):
      strMsg='Ingrese edad (años) : '
      strAttr='edad'
    else:
      strMsg='Ingrese peso (Kg) : '
      strAttr='peso'


    while(True):
      while(True):
        try:
          value=int(input(strMsg))
        except ValueError:
          print('Por favor, ingrese '+strAttr)
        else:
          break

      if(value <1):
        print(strAttr+'no debe ser cero o menor')
      else:
        break 
  
    return value

############# End of function ################## 

####  Function selectionOptionValidator ######
  def selectionOptionValidator(self, value, lstOptions):
  
    while(True):
      while(True):
        try:
          value=int(input('Ingrese selección : \t'))
        except ValueError:
          print('Por favor, ingrese selección permitida ')
        else:
          break

      if(value <1 or value > len(lstOptions)):
        print('Selección no debe pasar de rango')
      else:
        break 
  
    return value


############# End of function ################## 


############ End of class ##############

## Start: Clase Init ####
class Init(object):
  """
  Se propone una lista de contenedores de persona para crear
  n-objetos de personas dinámicamente cada vez que el método 
  createPerson() sea invocado.
  
  """

  def __init__(self):
    self.__lstPersonContainer=[]
    self.__inputValidate=Validator()
    pass

 ############# Start of function ################## 
  def createPerson(self):
    value=0
    age=0
    weight=0
    strName=''
    personName=''
   


    while(self.__inputValidate.stringValidator(strName)):
      strName=input('Ingrese nombre: ')
    
    personName=strName

    age=self.__inputValidate.intNumericValidator(value,True)
    weight=self.__inputValidate.intNumericValidator(value,False)

    lstPersonAttr=[personName,age,weight]

    self.__lstPersonContainer.append(PersonContainer(lstPersonAttr))

  ############# End of function ################## 

  ############# Start of function ################## 
  ###Objetivo: selección dinámica de saludo de personas.
  def saludoEntrePersonas(self):
    value=0
    selectedPerson=0
    selectedReceivedPerson=0
    print()
    print()
    print('Seleccione quien envía el saludo')
    for i in range(len(self.__lstPersonContainer)):
      print(
            str(i+1)
            +' - '+
            self.__lstPersonContainer[i].getPerson().getName()
      )

    

    selectedPerson=self.__inputValidate.selectionOptionValidator(
                    value,
                    self.__lstPersonContainer
                  )


    ##Evita que una persona se salude así misma
    ##La lista de personas restantes a quien saludar.
    ##Al crear instancia de lista, se crean dos versiones independientes
    ##copia_lista=list(original_lista)
    ##Lo que pasa en una lista, no afecta a la otra.
    lstRestOfPerson=list(self.__lstPersonContainer)
    del lstRestOfPerson[selectedPerson-1]
    print()
    print('Seleccione quien recibe el saludo')
    for i in range(len(lstRestOfPerson)):
      print(
        str(i+1)+' - '+lstRestOfPerson[i].getPerson().getName()
      )

    selectedReceivedPerson=self.__inputValidate.selectionOptionValidator(
      value,
      lstRestOfPerson
    )
    print()
    print()
    print('Saludo enviado por '+
            self.__lstPersonContainer[selectedPerson-1]
            .getPerson().getName()
          )

    
    ##Ejecuta saludo entre persona
    self.__lstPersonContainer[selectedPerson-1].getPerson().greetPerson(
        lstRestOfPerson[selectedReceivedPerson-1].getPerson()
    )

  ############# End of function ################## 
  

  ## Visualizar lista de personas creadas
  def getPersonContainers(self):
    for per in self.__lstPersonContainer:
      print('Nombre: '+per.getPerson().getName()+
      '\nEdad (años) :'+str(per.getPerson().getAge())+
      '\nPeso (Kg) :'+str(per.getPerson().getWeight())
      )
      print('___________')
  ############# End of function ################## 
        
############ End of class ##############
  

## Instancia de objeto clase Init, arranca programa #####
initObj=Init()
initObj.createPerson()
print()
initObj.createPerson()
#print()
#Puede llamarse el método createPerson() n-veces.
#initObj.createPerson()
print()
initObj.saludoEntrePersonas()

#print()
#Ver lista de personas agregadas.
#initObj.getPersonContainers()


######################################################
##Niveles de privacidad:
##Atributos:
## Público: self.name = name 
## Privado: self.__name = name  #Doble guión bajo
## Protected: self._name = name #Un guión bajo

##Métodos:
## Público: def foo(self): 
## Privado: def __foo(self):  #Doble guión bajo
## Protected: def _foo(self): #Un guión bajo