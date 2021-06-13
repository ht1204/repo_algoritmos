package Controlador;

import Controlador.Validate.Validator;
import Modelo.Estudiante;
import java.util.Scanner;

public class StudentController {

    private Estudiante student;
    private DataStudentGather dataStu;

    public StudentController() {
        student = new Estudiante();
        dataStu = new DataStudentGather();
    }

    public void inputData() {
        boolean inputFlag = true;
        String name = "";
        String lastName = "";
        int codigo = 0;

        Scanner sc = new Scanner(System.in);

        do {
            System.out.println("Ingrese nombre de estudiante : ");
            name = sc.nextLine();
        } while (Validator.validateNames(name));

        do {
            System.out.println("Ingrese apellido de estudiante : ");
            lastName = sc.nextLine();
        } while (Validator.validateNames(lastName));

        do {
            inputFlag = false;
            try {

                System.out.println("Ingrese código de estudiante : ");
                codigo = sc.nextInt();
                if (codigo < 1 || codigo > 1000000) {
                    inputFlag = true;
                    throw new Exception("Ingreso Inválido");
                }
            } catch (Exception ex) {
                inputFlag = true;
                System.out.println("Ingreso Inválido");
                sc = new Scanner(System.in);
            }

        } while (inputFlag == true);

        student.setNombre(name);
        student.setApellido(lastName);
        student.setCodigo(codigo);
        System.out.println("\n______________________");
        this.showReport(student);
    }

    private void showReport(Estudiante student) {
        dataStu.setCode(student.getCodigo());
        float promedio = dataStu.getPromedioDigitosCodigo();
        int ultimoDigitoCodigo = dataStu.getLastDigitCode();
        System.out.println("\n\tPromedio Dígitos: "+promedio);
        System.out.println("\n\tÚltimo Dígito: "+ultimoDigitoCodigo);
        if (promedio < 3.55 && ultimoDigitoCodigo > 5) {
            System.out.println("\n\tPromedio Dígitos: "+promedio);
            System.out.println("\n\tApellidos Estudiante: "+student.getApellido());
        }else{
            System.out.println("\n\tNombre Estudiante: "+student.getNombre()+" "+student.getApellido());
        }
    }

}
