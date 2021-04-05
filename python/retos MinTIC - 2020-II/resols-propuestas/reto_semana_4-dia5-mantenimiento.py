import math

#Función para personalizada para redondear
def round(n, decimales=0):
    multiplier = 10 ** decimales
    return math.ceil(n * multiplier) / multiplier

#Fin función

#Inicio función
def entregasATiempo(matrixDistribucionAsignado, matrixDistribucionRegistrado):

    #Diccionarios cuyos keys son los ID de los camiones y valores por defecto, cero.
    cantidadTotalDespachoRegistrado={1:0,2:0,3:0,4:0,5:0}
    cantidadTotalDespachoRegistradoATiempo = {1:0,2:0,3:0,4:0,5:0}
    
    #Validación entre cantidad de datos registrados y asignados
    if(len(matrixDistribucionAsignado) and len(matrixDistribucionRegistrado)):
        
        filasRegistradoAsignado = len(matrixDistribucionAsignado)
        
        for i in range(0,filasRegistradoAsignado):

            #Se validan registros positivos para realizar cálculos
            if(matrixDistribucionAsignado[i][2] > 0 and matrixDistribucionAsignado[i][3] > 0 and matrixDistribucionRegistrado[i][2] > 0 and matrixDistribucionRegistrado[i][3] > 0):
                
                cantidadTotalDespachoRegistrado[matrixDistribucionRegistrado[i][1]] = cantidadTotalDespachoRegistrado.get(matrixDistribucionRegistrado[i][1],0)+ matrixDistribucionRegistrado[i][2]

                #Una entrega registra retraso cuando el tiempo registrado es mayor al tiempo asignado
                #El tiempo registrado debe ser menor/igual al tiempo asignado
                if(matrixDistribucionRegistrado[i][3] <= matrixDistribucionAsignado[i][3]):
                    cantidadTotalDespachoRegistradoATiempo[matrixDistribucionRegistrado[i][1]] = cantidadTotalDespachoRegistradoATiempo.get(matrixDistribucionRegistrado[i][1],0)+ matrixDistribucionRegistrado[i][2]


                

                


        #Se obtienen los valores de cada key de diccionarios  y se pasa a listas con el fin
        #de realizar la evaluación de eficiencia por cada posición de memoria.                
        
        cantTotalDespachoRegistrado = []
        
        cantTotalDespachoRegistradoATiempo = []


            
        for value in cantidadTotalDespachoRegistrado.values():
            cantTotalDespachoRegistrado.append(round(value,1))

            
        for value in cantidadTotalDespachoRegistradoATiempo.values():
            cantTotalDespachoRegistradoATiempo.append(round(value,1))
            
        #Se evalúan e imprimen datos.
        print("Entregas a tiempo")
        for i in range(0, len(cantTotalDespachoRegistrado)):
            entregas_tiempo=(cantTotalDespachoRegistradoATiempo[i]/cantTotalDespachoRegistrado[i])*100
            print("Para Id camión # ",i+1," = ", round(entregas_tiempo,1),"%")                
        
        
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

            #Se validan registros positivos para realizar cálculos
            if(matrixDistribucionAsignado[i][2] > 0 and matrixDistribucionAsignado[i][3] > 0 and matrixDistribucionRegistrado[i][2] > 0 and matrixDistribucionRegistrado[i][3] > 0):
                cantidadTotalDespachoAsignado[matrixDistribucionAsignado[i][1]] =cantidadTotalDespachoAsignado.get(matrixDistribucionAsignado[i][1],0)+ matrixDistribucionAsignado[i][2]

        #De manera análoga a lo anterior, se realiza con los datos registrados
        filasRegistradoRegistrado = len(matrixDistribucionRegistrado)
        for i in range(0,filasRegistradoRegistrado):

            #Se validan registros positivos para realizar cálculos
            if(matrixDistribucionRegistrado[i][2] > 0 and matrixDistribucionRegistrado[i][3] > 0 and matrixDistribucionAsignado[i][2] > 0 and matrixDistribucionAsignado[i][3] > 0):
                cantidadTotalDespachoRegistrado[matrixDistribucionRegistrado[i][1]]= cantidadTotalDespachoRegistrado.get(matrixDistribucionRegistrado[i][1],0)+ matrixDistribucionRegistrado[i][2]

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
            print("Para Id camión # ",i+1," = ", round(nCumplimiento,1),"%")
        
    else:
        print("No hay datos apropiados")    
        

#Fin función





#Inicio Función
def tasaDeEntrega(matrixDistribucionRegistrado,matrixDistribucionAsignado):
#Diccionarios cuyos keys son los ID de los camiones y valores por defecto, cero.
    
    cantTotalDespachoRegistrado={1:0,2:0,3:0,4:0,5:0}
    tiempoTotalDespachoRegistrado={1:0,2:0,3:0,4:0,5:0}
    
    if(len(matrixDistribucionAsignado) and len(matrixDistribucionRegistrado)):
        filasRegistrado = len(matrixDistribucionRegistrado)

        #Sumar cada key-value del diccionario respecto al id del camión correspondiente en datos asignados.
        for i in range(0,filasRegistrado):

            #Se validan registros positivos para realizar cálculos
            if(matrixDistribucionRegistrado[i][2] > 0 and matrixDistribucionRegistrado[i][3] > 0 and matrixDistribucionAsignado[i][2] > 0 and matrixDistribucionAsignado[i][3] > 0):
                cantTotalDespachoRegistrado[matrixDistribucionRegistrado[i][1]] = cantTotalDespachoRegistrado.get(matrixDistribucionRegistrado[i][1],0) + matrixDistribucionRegistrado[i][2]              
                tiempoTotalDespachoRegistrado[matrixDistribucionRegistrado[i][1]]= tiempoTotalDespachoRegistrado.get(matrixDistribucionRegistrado[i][1],0) + matrixDistribucionRegistrado[i][3]


        #Se obtienen los valores de cada key de diccionarios  y se pasa a listas con el fin
        #de realizar la evaluación de eficiencia por cada posición de memoria.
                
        cantidadTotalDespachoRegistrado = []
        tiemposTotalDespachoRegistrado = []
        
            
        for value in cantTotalDespachoRegistrado.values():
            cantidadTotalDespachoRegistrado.append(value)            
            
            
        for value in tiempoTotalDespachoRegistrado.values():
            tiemposTotalDespachoRegistrado.append(value)            

        #Se evalúan e imprimen datos.
        print("Tasa de entrega")
        for i in range(0, len(cantidadTotalDespachoRegistrado)):
            tasaEntrega = cantidadTotalDespachoRegistrado[i] /  tiemposTotalDespachoRegistrado[i]
            print("Para Id camión # ",i+1," = ", round(tasaEntrega,1))               
    else:
        print("No hay datos apropiados")    

#Fin función


#Inicio Función
def errorInputData(matrix, index,strFlag):
    
    if(matrix[index][2]<=0):
        print("Error en litros",strFlag," Punto # ",index+1," Camión ",matrix[index][1])
            
    elif(matrix[index][3]<=0):
        print("Error en tiempo de despacho ",strFlag," Punto # ",index+1," Camión ",matrix[index][1])    


#Fin función


#Inicio Función
def eficienciaTiemposDespacho(matrixDistribucionAsignado, matrixDistribucionRegistrado):

    #Diccionarios cuyos keys son los ID de los camiones y valores por defecto, cero.
    tiempoTotalDespachoAsignado={1:0,2:0,3:0,4:0,5:0}
    tiempoTotalDespachoRegistrado={1:0,2:0,3:0,4:0,5:0}
    
   
    #Validación entre cantidad de datos registrados y asignados
    if(len(matrixDistribucionAsignado) and len(matrixDistribucionRegistrado)):
        
        filasRegistradoAsignado = len(matrixDistribucionAsignado)

        #Sumar cada key-value del diccionario respecto al id del camión correspondiente en datos asignados.
        for i in range(0,filasRegistradoAsignado):
            
            if(matrixDistribucionAsignado[i][2] <= 0 or matrixDistribucionAsignado[i][3] <= 0):
                errorInputData(matrixDistribucionAsignado, i,"asignados")
                
            else:

                #Se validan registros positivos para realizar cálculos
                if(matrixDistribucionAsignado[i][2] > 0 and matrixDistribucionAsignado[i][3] > 0 and matrixDistribucionRegistrado[i][2] > 0 and matrixDistribucionRegistrado[i][3] > 0):
                    tiempoTotalDespachoAsignado[matrixDistribucionAsignado[i][1]] = tiempoTotalDespachoAsignado.get(matrixDistribucionAsignado[i][1],0)+ matrixDistribucionAsignado[i][3]

        #De manera análoga a lo anterior, se realiza con los datos registrados        
        filasRegistrado = len(matrixDistribucionRegistrado)
        for i in range(0,filasRegistrado):
            
            if(matrixDistribucionRegistrado[i][2] <= 0 or matrixDistribucionRegistrado[i][3] <= 0):
                errorInputData(matrixDistribucionRegistrado, i,"registrados")
            
            else:

                #Se validan registros positivos para realizar cálculos
                if(matrixDistribucionRegistrado[i][2] > 0 and matrixDistribucionRegistrado[i][3] > 0 and matrixDistribucionAsignado[i][2] > 0 and matrixDistribucionAsignado[i][3] > 0):
                    tiempoTotalDespachoRegistrado[matrixDistribucionRegistrado[i][1]]= tiempoTotalDespachoRegistrado.get(matrixDistribucionRegistrado[i][1],0)+ matrixDistribucionRegistrado[i][3]

        #Se obtienen los valores de cada key de diccionarios  y se pasa a listas con el fin
        #de realizar la evaluación de eficiencia por cada posición de memoria.
                
        tiemposTotalDespachoAsignado = []
        tiemposTotalDespachoRegistrado = []
        
        for value in tiempoTotalDespachoAsignado.values():
            tiemposTotalDespachoAsignado.append(value)
            
        for value in tiempoTotalDespachoRegistrado.values():
            tiemposTotalDespachoRegistrado.append(value)

        blankSpace()
        #Se evalúan e imprimen datos.
        print("Eficiencia en tiempo de Despacho")
        for i in range(0, len(tiemposTotalDespachoRegistrado)):
            eficiencia=((tiemposTotalDespachoAsignado[i]-tiemposTotalDespachoRegistrado[i])/tiemposTotalDespachoAsignado[i])*100
            print("Para Id camión # ",i+1," = ", round(eficiencia,1),"%")
        
    else:
        print("No hay datos apropiados")    

#Fin función


#Inicio función
def blankSpace():
    print("")

#Fin función


#Inicio función
def control(matrizAsig, matrizRegis):
    eficienciaTiemposDespacho(matrizAsig,matrizRegis)
    blankSpace()
    tasaDeEntrega(matrizRegis,matrizAsig)
    blankSpace()
    nivelCumplimientoDespachos(matrizAsig,matrizRegis)
    blankSpace()
    entregasATiempo(matrizAsig,matrizRegis)

#Fin Función



#No modifiques esta parte!
#La función control recibe dos parametros de entrada control(matrizasig, matrizregis)
if __name__ == "__main__":
    control([[1,5,1329,0], [2,4,0,35], [3,1,1462,54], [4,3,1222,35], [5,2,-111,44],[6,3,1389,52], [7,1,1500,35], [8,1,1419,50], [9,5,1355,44],[10,4,1491,46],[11,1,1427,38],[12,4,1421,31], [13,3,1259,55], [14,5,1489,35], [15,5,1417,37], [16,1,1220,33], [17,1,1291,35], [18,2,1341,48], [19,4,1386,54], [20,3,1467,34],                   [21,1,1429,42],[22,5,1232,32], [23,3,1343,54], [24,1,1426,33], [25,4,1332,36], [26,4,1494,40], [27,3,1280,39], [28,1,1374,36], [29,2,1376,48], [30,4,1349,50]],
            [[1,5,1168,52], [2,4,1224,51], [3,1,1379,33], [4,3,1281,52], [5,2,1200,38], [6,3,1320,34], [7,1,1225,52], [8,1,1149,51], [9,5,1424,34], [10,4,0,36], [11,1,1205,0], [12,4,1297,-37],[13,3,1357,49], [14,5,1227,36],[15,5,1263,46], [16,1,1123,33], [17,1,1137,30], [18,2,1374,37], [19,4,1229,33], [20,3,1437,31], [21,1,1290,48], [22,5,1259,48], [23,3,1435,30],[24,1,1104,40], [25,4,1387,43], [26,4,1377,55], [27,3,1294,54], [28,1,1338,51],[29,2,1387,47], [30,4,1208,34]])
