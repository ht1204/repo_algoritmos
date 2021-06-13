package Controlador;

import Controlador.Validate.Validator;
import Modelo.Estudiante;

public class ControllerInitGUI {

    private Estudiante student;
    private DataStudentGather dataStu;
    private float promedio;
    private int ultimoDigitoCodigo;

    public ControllerInitGUI() {
        student = new Estudiante();
        dataStu = new DataStudentGather();
    }

    public boolean validateInputs(String name, String lastName, int code) {

        if (Validator.validateNames(name) || Validator.validateNames(lastName)
                || Validator.validateNumbers(code)) {
            return true;
        } else {
            return false;
        }

    }

    public boolean validateCodeNumber(int code) {
        if (code < 1 || code > 1000000) {
            return true;
        } else {
            return false;
        }
    }

    public void setData(String name, String lastName, int code) {
        student.setNombre(name);
        student.setApellido(lastName);
        student.setCodigo(code);
        dataStu.setCode(student.getCodigo());
        this.promedio = dataStu.getPromedioDigitosCodigo();
        this.ultimoDigitoCodigo = dataStu.getLastDigitCode();
    }

    public float getPromedio() {
        return promedio;
    }

    public int getUltimoDigitoCodigo() {
        return ultimoDigitoCodigo;
    }

    public Estudiante getStudent() {
        return student;
    }

}
