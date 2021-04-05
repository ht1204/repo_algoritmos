import math

#Función para personalizada para redondear
def round(n, decimales=0):
    multiplier = 10 ** decimales
    return math.ceil(n * multiplier) / multiplier

#Fin Función round


#Inicio función
def eficienciaTiemposDespacho(matrixDistribucionAsignado, matrixDistribucionRegistrado):

    #Diccionarios cuyos keys son los ID de los camiones y valores por defecto, cero.
    tiempoTotalDespachoAsignado={1:0,2:0,3:0,4:0,5:0}
    tiempoTotalDespachoRegistrado={1:0,2:0,3:0,4:0,5:0}
    
   
    #Validación entre cantidad de datos registrados y asignados
    if(len(matrixDistribucionAsignado) and len(matrixDistribucionRegistrado)):
        filasRegistradoAsignado = len(matrixDistribucionAsignado)

        #Sumar cada key-value del diccionario respecto al id del camión correspondiente en datos asignados.
        for i in range(0,filasRegistradoAsignado):
  
            if(matrixDistribucionAsignado[i][1] == 1):
                tiempoTotalDespachoAsignado[1]=tiempoTotalDespachoAsignado.get(1,0)+ matrixDistribucionAsignado[i][3]
                
                
            elif(matrixDistribucionAsignado[i][1] == 2):
                tiempoTotalDespachoAsignado[2]=tiempoTotalDespachoAsignado.get(2,0)+ matrixDistribucionAsignado[i][3]
                
                
            elif(matrixDistribucionAsignado[i][1] == 3):
                tiempoTotalDespachoAsignado[3]=tiempoTotalDespachoAsignado.get(3,0)+ matrixDistribucionAsignado[i][3]
                
                
            elif(matrixDistribucionAsignado[i][1] == 4):
                tiempoTotalDespachoAsignado[4]=tiempoTotalDespachoAsignado.get(4,0)+ matrixDistribucionAsignado[i][3]
                
                
            elif(matrixDistribucionAsignado[i][1] == 5):
                tiempoTotalDespachoAsignado[5]=tiempoTotalDespachoAsignado.get(5,0)+ matrixDistribucionAsignado[i][3]

        #De manera análoga a lo anterior, se realiza con los datos registrados        
        filasRegistradoRegistrado = len(matrixDistribucionRegistrado)
        for i in range(0,filasRegistradoRegistrado):
  
            if(matrixDistribucionRegistrado[i][1] == 1):
                tiempoTotalDespachoRegistrado[1]= tiempoTotalDespachoRegistrado.get(1,0)+ matrixDistribucionRegistrado[i][3]
                
                
            elif(matrixDistribucionAsignado[i][1] == 2):
                tiempoTotalDespachoRegistrado[2]= tiempoTotalDespachoRegistrado.get(2,0)+ matrixDistribucionRegistrado[i][3]
                
                
            elif(matrixDistribucionAsignado[i][1] == 3):
                tiempoTotalDespachoRegistrado[3]= tiempoTotalDespachoRegistrado.get(3,0)+ matrixDistribucionRegistrado[i][3]
                
                
            elif(matrixDistribucionAsignado[i][1] == 4):
                tiempoTotalDespachoRegistrado[4]= tiempoTotalDespachoRegistrado.get(4,0)+ matrixDistribucionRegistrado[i][3]
                
                
            elif(matrixDistribucionAsignado[i][1] == 5):
                tiempoTotalDespachoRegistrado[5]= tiempoTotalDespachoRegistrado.get(5,0)+ matrixDistribucionRegistrado[i][3]


        #Se obtienen los valores de cada key de diccionarios  y se pasa a listas con el fin
        #de realizar la evaluación de eficiencia por cada posición de memoria.
        
        tiemposTotalDespachoAsignado = []
        tiemposTotalDespachoRegistrado = []
        
        for value in tiempoTotalDespachoAsignado.values():
            tiemposTotalDespachoAsignado.append(round(value,1))
            
        for value in tiempoTotalDespachoRegistrado.values():
            tiemposTotalDespachoRegistrado.append(round(value,1))

        #Se evalúan e imprimen datos.
        print("Eficiencia en tiempos de despacho")
        for i in range(0, len(tiemposTotalDespachoRegistrado)):
            eficiencia=((tiemposTotalDespachoAsignado[i]-tiemposTotalDespachoRegistrado[i])/tiemposTotalDespachoAsignado[i])*100
            print("Para Id # ",i+1," = ", round(eficiencia,1),"%")
        
    else:
        print("No hay datos apropiados")

#Fin función

#Inicio función
def tasaDeEntrega(matrixDistribucionRegistrado):
    #Diccionarios cuyos keys son los ID de los camiones y valores por defecto, cero.
    
    cantTotalDespachoRegistrado={1:0,2:0,3:0,4:0,5:0}
    tiempoTotalDespachoRegistrado={1:0,2:0,3:0,4:0,5:0}
    
    if(len(matrixDistribucionRegistrado) > 0):
        filasRegistrado = len(matrixDistribucionRegistrado)

        #Sumar cada key-value del diccionario respecto al id del camión correspondiente en datos asignados.
        for i in range(0,filasRegistrado):
  
            if(matrixDistribucionRegistrado[i][1] == 1):
                
                cantTotalDespachoRegistrado[1] = cantTotalDespachoRegistrado.get(1,0) + matrixDistribucionRegistrado[i][2]
                
            elif(matrixDistribucionRegistrado[i][1] == 2):
                
                cantTotalDespachoRegistrado[2] = cantTotalDespachoRegistrado.get(2,0) + matrixDistribucionRegistrado[i][2]
                
            elif(matrixDistribucionRegistrado[i][1] == 3):
                
                cantTotalDespachoRegistrado[3] = cantTotalDespachoRegistrado.get(3,0) + matrixDistribucionRegistrado[i][2]
                
            elif(matrixDistribucionRegistrado[i][1] == 4):
                
                cantTotalDespachoRegistrado[4] = cantTotalDespachoRegistrado.get(4,0) + matrixDistribucionRegistrado[i][2]
                
            elif(matrixDistribucionRegistrado[i][1] == 5):
                
                cantTotalDespachoRegistrado[5] = cantTotalDespachoRegistrado.get(5,0) + matrixDistribucionRegistrado[i][2]

        #De manera análoga a lo anterior, se realiza con los datos registrados        
        filasRegistrado= len(matrixDistribucionRegistrado)
        #Sumar cada key-value del diccionario respecto al id del camión correspondiente en datos asignados.
        for i in range(0,filasRegistrado):
  
            if(matrixDistribucionRegistrado[i][1] == 1):
                
                tiempoTotalDespachoRegistrado[1]=tiempoTotalDespachoRegistrado.get(1,0) + matrixDistribucionRegistrado[i][3]
                
            elif(matrixDistribucionRegistrado[i][1] == 2):
                
                tiempoTotalDespachoRegistrado[2]=tiempoTotalDespachoRegistrado.get(2,0) + matrixDistribucionRegistrado[i][3]
                
            elif(matrixDistribucionRegistrado[i][1] == 3):
                
                tiempoTotalDespachoRegistrado[3]=tiempoTotalDespachoRegistrado.get(3,0) + matrixDistribucionRegistrado[i][3]
                
            elif(matrixDistribucionRegistrado[i][1] == 4):
                
                tiempoTotalDespachoRegistrado[4]=tiempoTotalDespachoRegistrado.get(4,0) + matrixDistribucionRegistrado[i][3]
                
            elif(matrixDistribucionRegistrado[i][1] == 5):
                
                tiempoTotalDespachoRegistrado[5]=tiempoTotalDespachoRegistrado.get(5,0) + matrixDistribucionRegistrado[i][3]

        #Se obtienen los valores de cada key de diccionarios  y se pasa a listas con el fin
        #de realizar la evaluación de eficiencia por cada posición de memoria.
                

        cantidadTotalDespachoRegistrado = []

        tiemposTotalDespachoRegistrado = []
        
            
        for value in cantTotalDespachoRegistrado.values():
            cantidadTotalDespachoRegistrado.append(round(value,1))            
            
            
        for value in tiempoTotalDespachoRegistrado.values():
            tiemposTotalDespachoRegistrado.append(round(value,1))            

        #Se evalúan e imprimen datos.
        print("Tasa de entrega")
        for i in range(0, len(cantidadTotalDespachoRegistrado)):
            tasaEntrega = cantidadTotalDespachoRegistrado[i] /  tiemposTotalDespachoRegistrado[i] *100
            print("Para Id # ",i+1," = ", round(tasaEntrega,1),"%")               
    else:
        print("No hay datos apropiados")
        
#Fin función    

    
#Inicio función
def nivelCumplimientoDespachos(matrixDistribucionAsignado, matrixDistribucionRegistrado):

    #Diccionarios cuyos keys son los ID de los camiones y valores por defecto, cero.
    cantidadTotalDespachoAsignado={1:0,2:0,3:0,4:0,5:0}
    cantidadTotalDespachoRegistrado={1:0,2:0,3:0,4:0,5:0}
    
   
    #Validación entre cantidad de datos registrados y asignados
    if(len(matrixDistribucionAsignado) and len(matrixDistribucionRegistrado)):
        filasRegistradoAsignado = len(matrixDistribucionAsignado)

        #Sumar cada key-value del diccionario respecto al id del camión correspondiente en datos asignados.
        for i in range(0,filasRegistradoAsignado):
  
            if(matrixDistribucionAsignado[i][1] == 1):
                cantidadTotalDespachoAsignado[1]=cantidadTotalDespachoAsignado.get(1,0)+ matrixDistribucionAsignado[i][2]
                
                
            elif(matrixDistribucionAsignado[i][1] == 2):
                cantidadTotalDespachoAsignado[2]=cantidadTotalDespachoAsignado.get(2,0)+ matrixDistribucionAsignado[i][2]
                
                
            elif(matrixDistribucionAsignado[i][1] == 3):
                cantidadTotalDespachoAsignado[3]=cantidadTotalDespachoAsignado.get(3,0)+ matrixDistribucionAsignado[i][2]
                
                
            elif(matrixDistribucionAsignado[i][1] == 4):
                cantidadTotalDespachoAsignado[4]=cantidadTotalDespachoAsignado.get(4,0)+ matrixDistribucionAsignado[i][2]
                
                
            elif(matrixDistribucionAsignado[i][1] == 5):
                cantidadTotalDespachoAsignado[5]=cantidadTotalDespachoAsignado.get(5,0)+ matrixDistribucionAsignado[i][2]

        #De manera análoga a lo anterior, se realiza con los datos registrados        
        filasRegistradoRegistrado = len(matrixDistribucionRegistrado)
        for i in range(0,filasRegistradoRegistrado):
  
            if(matrixDistribucionRegistrado[i][1] == 1):
                cantidadTotalDespachoRegistrado[1]= cantidadTotalDespachoRegistrado.get(1,0)+ matrixDistribucionRegistrado[i][2]
                
                
            elif(matrixDistribucionAsignado[i][1] == 2):
                cantidadTotalDespachoRegistrado[2]= cantidadTotalDespachoRegistrado.get(2,0)+ matrixDistribucionRegistrado[i][2]
                
                
            elif(matrixDistribucionAsignado[i][1] == 3):
                cantidadTotalDespachoRegistrado[3]= cantidadTotalDespachoRegistrado.get(3,0)+ matrixDistribucionRegistrado[i][2]
                
                
            elif(matrixDistribucionAsignado[i][1] == 4):
                cantidadTotalDespachoRegistrado[4]= cantidadTotalDespachoRegistrado.get(4,0)+ matrixDistribucionRegistrado[i][2]
                
                
            elif(matrixDistribucionAsignado[i][1] == 5):
                cantidadTotalDespachoRegistrado[5]= cantidadTotalDespachoRegistrado.get(5,0)+ matrixDistribucionRegistrado[i][2]


        #Se obtienen los valores de cada key de diccionarios  y se pasa a listas con el fin
        #de realizar la evaluación de eficiencia por cada posición de memoria.
                
        cantTotalDespachoAsignado = []
        cantTotalDespachoRegistrado = []
        
        for value in cantidadTotalDespachoAsignado.values():
            cantTotalDespachoAsignado.append(round(value,1))
            
        for value in cantidadTotalDespachoRegistrado.values():
            cantTotalDespachoRegistrado.append(round(value,1))

        #Se evalúan e imprimen datos.
        print("Nivel de cumplimiento")
        for i in range(0, len(cantTotalDespachoRegistrado)):
            nCumplimiento=(cantTotalDespachoRegistrado[i]/cantTotalDespachoAsignado[i])*100
            print("Para Id # ",i+1," = ", round(nCumplimiento,1),"%")
        
    else:
        print("No hay datos apropiados")    
        

#Fin función



#Inicio función
def controlAsignado():
    
    matrixDistribucionAsignado = []

#Asignado por LactoCaribe    
    matrixDistribucionAsignado.insert(0,[1,5,1329,48])
    matrixDistribucionAsignado.insert(1,[2,4,1386,35])
    matrixDistribucionAsignado.insert(2,[3,1,1462,54])
    matrixDistribucionAsignado.insert(3,[4,3,1222,35])
    matrixDistribucionAsignado.insert(4,[5,2,1445,44])
    matrixDistribucionAsignado.insert(5,[6,3,1389,52])
    matrixDistribucionAsignado.insert(6,[7,1,1500,35])
    matrixDistribucionAsignado.insert(7,[8,1,1419,50])
    matrixDistribucionAsignado.insert(8,[9,5,1355,44])
    matrixDistribucionAsignado.insert(9,[10,4,1491,46])
    matrixDistribucionAsignado.insert(10,[11,1,1427,38])
    matrixDistribucionAsignado.insert(11,[12,4,1421,31])    
    matrixDistribucionAsignado.insert(12,[13,3,1259,55])
    matrixDistribucionAsignado.insert(13,[14,5,1489,35])
    matrixDistribucionAsignado.insert(14,[15,5,1417,37])
    matrixDistribucionAsignado.insert(15,[16,1,1220,33])
    matrixDistribucionAsignado.insert(16,[17,1,1291,35])
    matrixDistribucionAsignado.insert(17,[18,2,1341,48])
    matrixDistribucionAsignado.insert(18,[19,4,1386,54])
    matrixDistribucionAsignado.insert(19,[20,3,1467,34])
    matrixDistribucionAsignado.insert(20,[21,1,1429,42])
    matrixDistribucionAsignado.insert(21,[22,5,1232,32])
    matrixDistribucionAsignado.insert(22,[23,3,1343,54])
    matrixDistribucionAsignado.insert(23,[24,1,1426,33])   
    matrixDistribucionAsignado.insert(24,[25,4,1332,36])
    matrixDistribucionAsignado.insert(25,[26,4,1494,40])
    matrixDistribucionAsignado.insert(26,[27,3,1280,39])
    matrixDistribucionAsignado.insert(27,[28,1,1374,36])
    matrixDistribucionAsignado.insert(28,[29,2,1376,48])
    matrixDistribucionAsignado.insert(29,[30,4,1349,50])

    

    """
    #Comprobación ingreso de datos de caso de estudio
    litrosEntregar = 0
    tiempoDespacho = 0
    
    for i in range(0,30):
        for j in range(0,4):

            if(j == 2):
                litrosEntregar =  litrosEntregar + matrixDistribucionAsignado[i][j]

            if(j == 3):
                tiempoDespacho =  tiempoDespacho + matrixDistribucionAsignado[i][j]
    
    print("Litros a entregar : ", litrosEntregar)
    print("Tiempo de despacho : ", tiempoDespacho)
    """
    return matrixDistribucionAsignado

#Fin función


#Inicio función
def controlRegistrado():
  
    

    """
    Si se desea ingresar datos por usuario, realizar la siguiente sintaxis:
    filas = 30
    idCamion = 0
    litrosEntregar = 0
    tiempoDespacho = 0
    aux = []

    for i in range(0,filas):

        print("Punto de Distribución : ",i+1)

        while(idCamion < 1 or idCamion > 5):
            idCamion = int(input('Ingrese Id Camión : '))

        while(litrosEntregar < 1000):
            litrosEntregar = int(input('Litros a entregar : '))

        while(tiempoDespacho < 5):
            tiempoDespacho = int(input('Tiempo de despacho (mins) : '))

        matrixDistribucionRegistrado.insert(i, [i+1, idCamion, litrosEntregar, tiempoDespacho])
        idCamion = 0
        litrosEntregar = 0
        tiempoDespacho = 0
    """
#Registrado por cada Camión
    matrixDistribucionRegistrado = []
    matrixDistribucionRegistrado.insert(0,[1,5,1168,52])
    matrixDistribucionRegistrado.insert(1,[2,4,1224,51])
    matrixDistribucionRegistrado.insert(2,[3,1,1379,33])
    matrixDistribucionRegistrado.insert(3,[4,3,1281,52])
    matrixDistribucionRegistrado.insert(4,[5,2,1200,38])
    matrixDistribucionRegistrado.insert(5,[6,3,1320,34])
    matrixDistribucionRegistrado.insert(6,[7,1,1225,52])
    matrixDistribucionRegistrado.insert(7,[8,1,1149,51])
    matrixDistribucionRegistrado.insert(8,[9,5,1424,34])
    matrixDistribucionRegistrado.insert(9,[10,4,1437,36])
    matrixDistribucionRegistrado.insert(10,[11,1,1205,42])
    matrixDistribucionRegistrado.insert(11,[12,4,1297,37])    
    matrixDistribucionRegistrado.insert(12,[13,3,1357,49])
    matrixDistribucionRegistrado.insert(13,[14,5,1227,36])
    matrixDistribucionRegistrado.insert(14,[15,5,1263,46])
    matrixDistribucionRegistrado.insert(15,[16,1,1123,33])
    matrixDistribucionRegistrado.insert(16,[17,1,1137,30])
    matrixDistribucionRegistrado.insert(17,[18,2,1374,37])
    matrixDistribucionRegistrado.insert(18,[19,4,1229,33])
    matrixDistribucionRegistrado.insert(19,[20,3,1437,31])
    matrixDistribucionRegistrado.insert(20,[21,1,1290,48])
    matrixDistribucionRegistrado.insert(21,[22,5,1259,48])
    matrixDistribucionRegistrado.insert(22,[23,3,1435,30])
    matrixDistribucionRegistrado.insert(23,[24,1,1104,40])   
    matrixDistribucionRegistrado.insert(24,[25,4,1387,43])
    matrixDistribucionRegistrado.insert(25,[26,4,1377,55])
    matrixDistribucionRegistrado.insert(26,[27,3,1294,54])
    matrixDistribucionRegistrado.insert(27,[28,1,1338,51])
    matrixDistribucionRegistrado.insert(28,[29,2,1387,47])
    matrixDistribucionRegistrado.insert(29,[30,4,1208,34])

    return matrixDistribucionRegistrado

    """
    #Comprobación ingreso de datos de caso de estudio
    litrosEntregar = 0
    tiempoDespacho = 0
    
    for i in range(0,30):
        for j in range(0,4):

            if(j == 2):
                litrosEntregar =  litrosEntregar + matrixDistribucionRegistrado[i][j]

            if(j == 3):
                tiempoDespacho =  tiempoDespacho + matrixDistribucionRegistrado[i][j]

    print("Litros a entregar : ", litrosEntregar)
    print("Tiempo de despacho : ", tiempoDespacho)
    """
    
#Fin función


#Inicio función
def blankSpace():
    print("")
#Fin función


#Inicio función
def control():
    matrixDistribucionAsignado = controlAsignado()
    matrixDistribucionRegistrado = controlRegistrado()
    eficienciaTiemposDespacho(matrixDistribucionAsignado, matrixDistribucionRegistrado)
    blankSpace()
    tasaDeEntrega(matrixDistribucionRegistrado)
    blankSpace()
    nivelCumplimientoDespachos(matrixDistribucionAsignado, matrixDistribucionRegistrado)
    
#Fin función    
            


control()
