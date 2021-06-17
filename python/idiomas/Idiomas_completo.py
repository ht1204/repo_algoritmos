#Hecho por Sará Luna UwU y compañeros de clase
import matplotlib.pyplot as plt
import numpy as np

def Diccionario():
   
   diccionario={
     "A":0,"B":0,"C":0,"D":0,"E":0,"F":0,"G":0,"H":0,
     "I":0,"J:":0,"K":0,"L":0,"M":0,"N":0,"O":0,"P":0,
     "Q":0,"R":0,"S":0,"T":0,"U":0,"V":0,"W":0,"X":0,"Y":0,
     "Z":0,"Ã‘":0,"Ã„":0,"Ã–":0,"Ãœ":0,"áºž":0,"Ã€":0,"Ã‚":0,
     "Ã‡":0,"Ã‰":0,"Ãˆ":0,"ÃŠ":0,"Ã‹":0,"ÃŽ":0,"Ã":0,"Ã”":0,
     "Å’":0,"Ã™":0,"Ã›":0,"Ã†":0,"Å¸":0,"Ã’":0,"ÃŒ":0
     }
   lectura = open("prueba.txt","r")
   linea = lectura.readline()
   n=0
   while linea:
      for x in linea:
         if x.upper() in diccionario:
            diccionario[x.upper()]+=1
            n+=1
      linea = lectura.readline()
   lectura.close()
   
   for x in diccionario:
      diccionario[x] = round(diccionario[x]/n*100,4)

   return diccionario


def Graficadora(porcentajes):
    porcentajes=list(porcentajes.values())
    alfabeto = ["A","B","C","D","E","F","G","H","I","J:","K","L","M","N","O","P","Q","R","S","T","U",
                "V","W","X","Y","Z","Ã‘","Ã„","Ã–","Ãœ","áºž","Ã€","Ã‚","Ã‡","Ã‰","Ãˆ","ÃŠ","Ã‹","ÃŽ",
                "Ã","Ã”","Å’","Ã™","Ã›","Ã†","Å¸","Ã’","ÃŒ"]
    espanol=[12.53,1.42,4.68,5.86,13.68,0.69,1.01,0.70,6.25,
             0.44,0.02,4.97,3.15,6.71,8.68,2.51,0.88,6.87,
             7.98,4.63,3.93,0.9,0.01,0.22,0.9,0.52,0.31,
             0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
    
    aleman= [5.58,1.96,3.16,4.98,16.93,1.49,3.02,4.98,
             8.02,0.24,1.32,3.60,2.55,10.53,2.24,0.67,
             0.02,6.89,6.42,5.79,3.83,0.84,1.78,0.05,
             0.05,1.21,0,0.54,0.30,0.65,0.37,0,0,0,
             0,0,0,0,0,0,0,0,0,0,0,0,0,0]
    
    ingles=[8.34,1.54,2.73,4.14,12.60,2.03,1.92,6.11,
            6.71,0.23,0.87,4.24,2.53,6.8,7.70,1.66,0.09,
            5.68,6.11,9.37,2.85,1.06,2.34,0.20,2.04,0.06,
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
    
    frances=[8.13,0.93,3.15,3.55,15.10,0.96,0.97,1.08,
             6.94,0.71,0.16,5.68,3.25,6.42,5.27,3.03,
             0.89,6.43,7.91,7.11,6.05,1.83,0.04,0.42,
             0.19,0.21,0,0,0,0,0.54,0.03,0.01,2.13,
             0.35,0.24,0.01,0.03,0.01,0.07,0.01,
             0.02,0.05,0.02,0.01,0.01,0,0]
    
    italiano=[10.85,1.05,4.3,3.39,11.49,1.01,1.65,
              1.43,10.18,0,0,5.70,2.87,7.02,9.97,
              2.96,0.45,6.19,5.48,6.97,3.16,1.75,
              0,0,0,0.85,0,0,0,0,0,0.15,0,0,0.06,
              0.42,0,0,0,0,0,0,0.12,0,0,0,0.11,0.09]
    
    x = np.arange(len(alfabeto))
    width=.15
    
    fig, ax = plt.subplots(figsize=(25,5))
    rects1 = ax.bar(x+(width*-2), porcentajes, width, label='Texto',color="yellow")
    rects2 = ax.bar(x+(width*-1), espanol, width, label='Español')
    rects3 = ax.bar(x+(width*0), aleman, width, label='Aleman')
    rects4 = ax.bar(x+(width*1), frances, width, label='Frances')
    rects5 = ax.bar(x+(width*2), ingles, width, label='Ingles')
    rects6 = ax.bar(x+(width*3), italiano, width, label='Italiano')

    ax.set_ylabel('Porcentajes')
    ax.set_xlabel('Alfabeto')
    ax.set_title('Frecuencia de apariciÃ³n de letras')
    ax.set_xticks(x)
    ax.set_xticklabels(alfabeto)
    ax.grid(True, axis="y")
    fig.savefig("idiomas.png")
    ax.legend()

    ax.bar_label(rects1, padding=3)
    ax.bar_label(rects2, padding=3)
    ax.bar_label(rects3, padding=3)
    ax.bar_label(rects4, padding=3)
    ax.bar_label(rects5, padding=3)
    ax.bar_label(rects6, padding=3)


    plt.show()

def IDIOMA(DICCIONARIO):
    print(DICCIONARIO)
    ESPANOL={"A":"12.53","B":"1.42","C":"4.68","D":"5.86",
             "E":"13.68","F":"0.69","G":"1.01","H":"0.70",
             "I":"6.25","J:":"0.44","K":"0.02","L":"4.97",
             "M":"3.15","N":"6.71","O":"8.68","P":"2.51",
             "Q":"0.88","R":"6.87","S":"7.98","T":"4.63",
             "U":"3.93","V":"0.9","W":"0.01","X":"0.22",
             "Y":"0.9","Z":"0.52","Ã‘":"0.31","Ã„":"0",
             "Ã–":"0","Ãœ":"0","áºž":"0","Ã€":"0","Ã‚":"0",
             "Ã‡":"0","Ã‰":"0","Ãˆ":"0","ÃŠ":"0","Ã‹":"0",
             "ÃŽ":"0","Ã":"0","Ã”":"0","Å’":"0","Ã™":"0",
             "Ã›":"0","Ã†":"0","Å¸":"0","Ã’":"0","ÃŒ":"0"
             }
    
    ALEMAN= {"A":"5.58","B":"1.96","C":"3.16","D":"4.98",
             "E":"16.93","F":"1.49","G":"3.02","H":"4.98",
             "I":"8.02","J:":"0.24","K":"1.32","L":"3.60",
             "M":"2.55","N":"10.53","O":"2.24","P":"0.67",
             "Q":"0.02","R":"6.89","S":"6.42","T":"5.79",
             "U":"3.83","V":"0.84","W":"1.78","X":"0.05",
             "Y":"0.05","Z":"1.21","Ã‘":"0","Ã„":"0.54",
             "Ã–":"0.30","Ãœ":"0.65","áºž":"0.37","Ã€":"0",
             "Ã‚":"0","Ã‡":"0","Ã‰":"0","Ãˆ":"0","ÃŠ":"0",
             "Ã‹":"0","ÃŽ":"0","Ã":"0","Ã”":"0","Å’":"0",
             "Ã™":"0","Ã›":"0","Ã†":"0","Å¸":"0","Ã’":"0","ÃŒ":"0"
             }
    INGLES={"A":"8.34","B":"1.54","C":"2.73","D":"4.14","E":"12.60","F":"2.03","G":"1.92","H":"6.11","I":"6.71","J:":"0.23","K":"0.87","L":"4.24","M":"2.53","N":"6.8","O":"7.70","P":"1.66","Q":"0.09","R":"5.68","S":"6.11","T":"9.37","U":"2.85","V":"1.06","W":"2.34","X":"0.20","Y":"2.04","Z":"0.06","Ã‘":"0","Ã„":"0","Ã–":"0","Ãœ":"0","áºž":"0","Ã€":"0","Ã‚":"0","Ã‡":"0","Ã‰":"0","Ãˆ":"0","ÃŠ":"0","Ã‹":"0","ÃŽ":"0","Ã":"0","Ã”":"0","Å’":"0","Ã™":"0","Ã›":"0","Ãœ":"0","Ã†":"0","Å¸":"0","Ã’":"0","ÃŒ":"0"}
    FRANCES={"A":"8.13","B":"0.93","C":"3.15","D":"3.55","E":"15.10","F":"0.96","G":"0.97","H":"1.08","I":"6.94","J:":"0.71","K":"0.16","L":"5.68","M":"3.25","N":"6.42","O":"5.27","P":"3.03","Q":"0.89","R":"6.43","S":"7.91","T":"7.11","U":"6.05","V":"1.83","W":"0.04","X":"0.42","Y":"0.19","Z":"0.21","Ã‘":"0","Ã„":"0","Ã–":"0","áºž":"0","Ã€":"0.54","Ã‚":"0.03","Ã‡":"0.01","Ã‰":"2.13","Ãˆ":"0.35","ÃŠ":"0.24","Ã‹":"0.01","ÃŽ":"0.03","Ã":"0.01","Ã”":"0.07","Å’":"0.01","Ã™":"0.02","Ã›":"0.05","Ãœ":"0.02","Ã†":"0.01","Å¸":"0.01","Ã’":"0","ÃŒ":"0"}
    ITALIANO={"A":"10.85","B":"1.05","C":"4.3","D":"3.39","E":"11.49","F":"1.01","G":"1.65","H":"1.43","I":"10.18","J:":"0","K":"0","L":"5.70","M":"2.87","N":"7.02","O":"9.97","P":"2.96","Q":"0.45","R":"6.19","S":"5.48","T":"6.97","U":"3.16","V":"1.75","W":"0","X":"0","Y":"0","Z":"0.85","Ã‘":"0","Ã„":"0","Ã–":"0","Ãœ":"0","áºž":"0","Ã€":"0.15","Ã‚":"0","Ã‡":"0","Ã‰":"0.06","Ãˆ":"0.42","ÃŠ":"0","Ã‹":"0","ÃŽ":"0","Ã":"0","Ã”":"0","Å’":"0","Ã™":"0.12","Ã›":"0","Ã†":"0","Å¸":"0","Ã’":"0.11","ÃŒ":"0.09"}
    #DIFERE > LISTA DE LOS VALORES DE LA DIFERENCIA EXISTENTE ENTRE EL TEXTO Y LOS IDIOMAS
    DIFERE=[]
    SMDIFE=0
    for letra in DICCIONARIO:
        #PTEX > PORCENTAJE DEL TEXTO
        PTEX= float(DICCIONARIO[letra])
        
        #PESPA > PORCENTAJE EN ESPAÑOL
        PESPA= float(ESPANOL.get(letra))
        #SMDIFE > SUMA DE DIFERENCIAS EN ESPAÑOL
        if PTEX >= PESPA:
            DIF= PTEX - PESPA
            SMDIFE=SMDIFE + DIF
        else:
            DIF= PESPA - PTEX
            SMDIFE= float(SMDIFE) + float(DIF)
    DIFERE.append(SMDIFE)
    SMDIFA=0
    for letra in DICCIONARIO:
        #PTEX > PORCENTAJE DEL TEXTO
        PTEX= float(DICCIONARIO[letra])
        
        #PESPA > PORCENTAJE EN ALEMAN
        PALE= float(ALEMAN.get(letra))
        #SMDIFA > SUMA DE DIFERENCIAS EN ALEMAN
        if PTEX >= PALE:
            DIF= PTEX - PALE
            SMDIFA=SMDIFA + DIF
        else:
            DIF= PALE - PTEX
            SMDIFA= SMDIFA + DIF
    DIFERE.append(SMDIFA)
    SMDIFI=0
    for letra in DICCIONARIO:
        #PTEX > PORCENTAJE DEL TEXTO
        PTEX= float(DICCIONARIO[letra])
        
        #PING > PORCENTAJE EN INGLES
        PING= float(INGLES.get(letra))
        #SMDIFI > SUMA DE DIFERENCIAS EN INGLES
        if PTEX >= PING:
            DIF= PTEX - PING
            SMDIFI=SMDIFI + DIF
        else:
            DIF= PING - PTEX
            SMDIFI= SMDIFI + DIF
    DIFERE.append(SMDIFI)
    SMDIFF=0
    for letra in DICCIONARIO:
        #PTEX > PORCENTAJE DEL TEXTO
        PTEX= float(DICCIONARIO[letra])
        
        #PFRAN > PORCENTAJE EN FRANCES
        PFRAN= float(FRANCES.get(letra))
        #SMDIFF > SUMA DE DIFERENCIAS EN FRANCES
        if PTEX >= PFRAN:
            DIF= PTEX - PFRAN
            SMDIFF=SMDIFF + DIF
        else:
            DIF= PFRAN - PTEX
            SMDIFF= SMDIFF + DIF
    DIFERE.append(SMDIFF)
    SMDIFIT=0
    for letra in DICCIONARIO:
        #PTEX > PORCENTAJE DEL TEXTO
        PTEX= float(DICCIONARIO[letra])
        
        #PITAL > PORCENTAJE EN ITALIANO
        PITAL= float(ITALIANO.get(letra))
        #SMDIFIT > SUMA DE DIFERENCIAS EN ITALIANO
        if PTEX >= PITAL:
            DIF= PTEX - PITAL
            SMDIFIT=SMDIFIT + DIF
        else:
            DIF= PITAL - PTEX
            SMDIFIT= SMDIFIT + DIF
    DIFERE.append(SMDIFIT)
    #VMIN > VALOR MINIMO DE LA LISTA
    VMIN= min(DIFERE)
    #POS= POSICION DEL VALOR MINIMO
    print("------ DIFERENCIAS CON CADA IDIOMA --------")
    print("\ESPAÑOL =",SMDIFE)
    print("ALEMAN =",SMDIFA)
    print("INGLES =",SMDIFI)
    print("FRANCES =",SMDIFF)
    print("ITALIANO =",SMDIFIT)
    POS=DIFERE.index(VMIN)
    if POS== 0:
        a="EL IDIOMA DEL TEXTO ES ESPAÑOL"
    elif POS == 1:
        a="EL IDIOMA DEL TEXTO ES ALEMAN"
    elif POS ==2:
        a="EL IDIOMA DEL TEXTO ES INGLES"
    elif POS == 3:
        a="EL IDIOMA DEL TEXTO ES FRANCES"
    elif POS == 4:
        a="EL IDIOMA DEL TEXTO ES ITALIANO"
    return a

d=Diccionario()
print(d)
print(IDIOMA(d))
Graficadora(d)
