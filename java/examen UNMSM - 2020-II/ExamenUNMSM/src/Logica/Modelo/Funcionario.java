package Logica.Modelo;

import Logica.Interfase.Panel_frontal;

public class Funcionario extends Universitario implements Panel_frontal {

    private String cargo;

    public Funcionario(String id, String nombre, int edad, String cargo) {
        super.setId(id);
        super.setNombre(nombre);
        super.setEdad(edad);
        
        if("".equals(cargo) || null == cargo){
            this.cargo="Funcionario";
        }else{
            this.cargo=cargo;
        }
        
    }

    public String getCargo() {
        return cargo;
    }

    public void setCargo(String cargo) {
        this.cargo = cargo;
    }

    @Override
    public String presentacion() {
        return "Hola, mi nombre es : " + super.getNombre() + " con el ID :" + super.getId() + " y tengo "
                + super.getEdad() + " años y tengo el cargo de " + this.getCargo()+".";
    }

    @Override
    public String realizarSolicitud() {
        return "Solicito un mejor computador para trabajar y un internet más rápido.";
    }

    @Override
    public boolean estado(String status) {
        if ("SI".equals(status)) {
            return true;
        } else {
            return false;
        }
    }

    @Override
    public int cantidadProyectos() {
        return 5;
    }

}
