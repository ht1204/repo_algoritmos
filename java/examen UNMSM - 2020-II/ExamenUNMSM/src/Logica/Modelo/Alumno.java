
package Logica.Modelo;

import Logica.Interfase.Panel_frontal;


public class Alumno extends Universitario implements Panel_frontal{

    private int cantidadAsignaturas;
    
    public Alumno(String id, String nombre, int edad, int cantidadAsignaturas) {
        super.setId(id);
        super.setNombre(nombre);
        super.setEdad(edad);
        this.cantidadAsignaturas=cantidadAsignaturas;
    }

    public int getCantidadAsignaturas() {
        return cantidadAsignaturas;
    }

    public void setCantidadAsignaturas(int cantidadAsignaturas) {
        this.cantidadAsignaturas = cantidadAsignaturas;
    }
      
    
    
    
    @Override
    public String presentacion() {
        return "Hola, mi nombre es : "+super.getNombre()+" con el ID : "+super.getId()+" y tengo "+
                super.getEdad()+" años.";
    }

    @Override
    public String realizarSolicitud() {
        return "Solicito atención respecto a exigencias realizadas en reunión de comité.";
    }
    
    @Override
    public boolean estado(String status) {
        if("SI".equals(status)){
            return true;
        }else{
            return false;
        }
    }

    @Override
    public int cantidadProyectos() {
        return 2;
    }


    
}
