
package Logica.Modelo;


public abstract class Universitario {
    
    private String id;
    private String nombre;
    private int edad;

    
    public abstract String presentacion();
    public abstract String realizarSolicitud();

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public int getEdad() {
        return edad;
    }

    public void setEdad(int edad) {
        this.edad = edad;
    }
   
 
    
}
