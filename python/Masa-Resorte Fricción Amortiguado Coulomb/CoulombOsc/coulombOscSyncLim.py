#Carga de librerias, rutinas, animaciones y recursos para graficos de Visual Python, VPython
from visual import *
from visual.graph import *


#Objetos para animacion.
L=vector(1,0,0) #Vector para resorte en reposo
s=vector(1., 0,0)  #Vector que representa extension del resorte
block=sphere(radius=0.25, color=color.cyan, pos=L+s) #Se crea una esfera que representa el bloque.
spring=cylinder(pos=vector(0,0,0), axis=L+s, radius=0.1)  #Se crea un cilindro que representa al resorte
scene.autoscale=0 #Quita el agregado de movimiento (autoscaling) a la animacion
posgraph=gcurve(color=color.green) #El gcurve configura la ventana para generacion de graficos

"""
Inicializacion de variables:
k=100 N/m; g=9.8 m/s^2; m=1 kg;  
Coeficientes de friccion cinetico y estatico:
mu_s=mu_k=0.5

Diferencial de tiempo de animacion: dt=0.0001 s
Posicion del bloque: d=0 m (inicialmente)
Tiempo de la animacion: t=0 s (Inicialmente)
"""
k=100.; g=9.8; mu_s=0.5; mu_k=0.5; m=1.0; dt=0.0001; d=0.; t=0.
F_mu_s=mu_s*m*g #Fuerza de friccion
F_spring=-k*(block.pos-L) #Fuerza de restitucion del resorte
almost_zero_p=mag(F_spring)*dt #Impulso casi nulo= |F_resorte|*dt, mag(A), funcion que toma magnitud del vector.
block.p=vector(0,0,0) #Momentum o impulso inicial del bloque.

# El analisis fisico desarrollado en el bucle se ejecuta hasta que el momentum del bloque sea casi nulo
# y que la fuerza de friccion estatica supere a la fuerza de restitucion del resorte.

while t<3.1396: #Condicion hasta tiempo final de recorrido
    rate(1000) #Variacion tiempo animacion en milisegundos

    if not(mag(block.p) < almost_zero_p):  #Si el bloque se mueve.
        F_mu_k=-m*g*mu_k*norm(block.p)     #Calcula la fuerza de friccion cinetica
    else:                                  #Si el bloque se detiene,
        F_mu_k=vector(0,0,0)               # la fuerza de friccion cinetica llega a anularse.

    F_spring=-k*(block.pos-L)              #Se aplica la segunda ley de Newton
    Fnet=F_spring+F_mu_k                   #Se actualiza "block.pos"  una vez
    block.p=block.p+Fnet*dt                #se actualiza la posicion del bloque en la animacion
    block.pos=block.pos+block.p/m*dt       #Al actualizarse "spring.axis", se actualiza
    spring.axis=block.pos-spring.pos       #la longitud del resorte en la animacion.

    d=d+mag(block.p/m)*dt                   #Se actualiza la distancia recorrida por el bloque: d->d+|p/m|*dt,p=m*v
    posgraph.plot(pos=(t,block.pos.x-L.x))  #Se grafica el desplazamiento del bloque en el grafico.
    t=t+dt

#Al terminar con el desarrollo en el bucle, se obtiene el resultado del desplazamiento final recorrido.
print('Total distance traveled : '+str(d)+' m')


