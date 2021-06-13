
package Logica;

import Logica.Modelo.Alumno;
import Logica.Modelo.Funcionario;

public class Tester {

    public Tester() {
        
    }
    
    public void testImplementations(){
        Funcionario funcionario = new Funcionario("UNMSM-F021", "Pedro Perez", 35, "Coordinador");
        System.out.println("\n\t___________________");
        System.out.println("\n\t"+funcionario.presentacion());
        System.out.println("\n\tSolicitud: "+funcionario.realizarSolicitud());
        System.out.println("\n\tEstado Funcionario : "+(funcionario.estado("SI") ? "Si" : "No"));
        System.out.println("\n\tCantidad de proyectos : "+funcionario.cantidadProyectos());
        System.out.println("\n\t_______________________________________");
        Alumno alumno= new Alumno("UNMSM-A0135", "Jose Pintado", 20,5);
        System.out.println("\n\t"+alumno.presentacion());
        System.out.println("\n\tSolicitud: "+alumno.realizarSolicitud());
        System.out.println("\n\tEstado Alumno : "+(alumno.estado("NO") ? "Si" : "No"));
        System.out.println("\n\tCantidad Asignaturas : "+alumno.getCantidadAsignaturas()); 
        System.out.println("\n\tCantidad de proyectos : "+alumno.cantidadProyectos());        
    }
}
