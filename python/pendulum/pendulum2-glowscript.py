from visual import *
#GlowScript 3.0 VPython

#Punto de apoyo del pendulo: pivote.
top=sphere(pos=vector(0,0,0),radius=0.1,color=color.yellow)

#Variables de sistema masa-pendulo.
m=1 #Masa (kg)
g=10 #Aceleracion gravitacional del medio (m/s^2)
l=4 #Longitud del pendulo (m)
dt=0.02 #intervalo de tiempo iterativo (s)

#Angulo Inicial
phi=2*pi/18
theta=-2*pi/18

#Conformacion de sistema pendular.
#Pendulo 1 (r)
masa_r=sphere(pos=l*vector(sin(phi), -cos(phi),0),radius=0.2, color=color.red)
hilo_r=cylinder(pos=top.pos, axis=(masa_r.pos-top.pos), radius=0.05, color=color.red)

#Pendulo 2 (a)
masa_a=sphere(pos=l*vector(sin(theta), -cos(theta),0),radius=0.2, color=color.blue)
hilo_a=cylinder(pos=top.pos, axis=(masa_a.pos-top.pos), radius=0.05, color=color.blue)


ball3=sphere(pos=vector(0,-4,0), radius=0.2, color=color.white)
ball3.p=vector(0,0,0)

#attach_trail(masa_r)

#Velocidad angular inicial
omega_r=0
omega_a=0

while 1:

    #Calcula la velocidad angular basado en el angulo inicial.
    alfa_r = -(g/l)*sin(phi)
    alfa_a = -(g/l)*sin(theta)
    
    #Actualiza la velocidad angular.
    omega_r=omega_r+alfa_r*dt
    omega_a=omega_a+alfa_a*dt

    
    #Actualiza angulo
    phi=phi+omega_r*dt
    theta=theta+omega_a*dt
    
    #Actualiza representacion de masa
    masa_r.pos=l*vector(sin(phi),-cos(phi),0)
    masa_a.pos=l*vector(sin(theta),-cos(theta),0)
    
    #Actualiza hilo 
    hilo_r.axis=masa_r.pos-top.pos
    hilo_a.axis=masa_a.pos-top.pos

    rate(100)




    
    
    
 
 


