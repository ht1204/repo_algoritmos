##studentDictionary={
##                    '1': [2.8,2.5,3,4,1,3.5],
##                    '2': [2.7,5,3.5,4.9,4]
##                }

# def readIntInput(prompt): Valida ingreso de cantidad de almunos.
# prompt: Representa dato de ingreso.
# Validaciones: Si es un caracter no numérico y si es numérico, debe ser mayor a cero (0).
def readIntInput(prompt):
    flagException=True
    number=0
    try:
        number=int(input(prompt))
        if(number<0):
            print('Error: el valor debe ser mayor a cero')
            flagException=False
    except:
        print('Error: entrada incorrecta')
        flagException=False
        
    return flagException,number

### def readIntCantCalificaciones(prompt, min, max): Valida ingreso de cantidad de almunos.
### prompt: Representa dato de ingreso.
### Validaciones: Si es un caracter no numérico, y si es numérico, hallarse entre min a max, puede ser de coma flotante.
def readIntCantCalificaciones(prompt, min, max):
    flagException=True
    number=0.0
    try:
        number=float(input(prompt))
        if(number<min or number>max):
            print('Error: el valor no está dentro del rango permitido (0..20)')
            flagException=False
    except:
        print('Error: entrada incorrecta')
        flagException=False
        
    return flagException,number


studentDictionary={}
cantAlumnos=0
cantCalificaciones=0
calificationsList=[]
calificacion=0.0

flagInput=False
flagInputCant=False
flagInputCalification=False

while(not flagInput):
    flagInput,cantAlumnos=readIntInput('Ingrese cantidad de alumnos: ')

keyDict='Alum_'


for contador in range(1,cantAlumnos+1):
    
    keyDict=keyDict+str(contador)
    print('Código de alumno: ',keyDict)
    
    
    while(not flagInputCant):
        flagInputCant,cantCalificaciones=readIntInput('Ingrese cantidad de calificaciones: ')
    flagInputCant=False

    for i in range(0,cantCalificaciones):
        while(not flagInputCalification):
            flagInputCalification,calificacion=readIntCantCalificaciones('Ingrese calificación: ',0,20)
            
        flagInputCalification=False    
        calificationsList.append(calificacion)
        
        

    studentDictionary[keyDict]=calificationsList
    keyDict='Alum_'
    calificationsList=[]


for key in studentDictionary:
    for items in studentDictionary[key]:
        for i in range(len(studentDictionary[key])-1):
            for j in range(0,len(studentDictionary[key])-i-1):
                if studentDictionary[key][j] < studentDictionary[key][j+1] :
                    studentDictionary[key][j], studentDictionary[key][j+1] = studentDictionary[key][j+1], studentDictionary[key][j]
                

print()
print('_____________________')
print('Lista Calificaciones Sobresalientes Por Alumno')
print()
for key, value in studentDictionary.items() :
    print (key,' : ',value[:3])
    
        


