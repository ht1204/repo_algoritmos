package Controlador;

import Controlador.Validate.Validator;
import Modelo.CodigoModel;

public class ControladorInitStartGUI {

    private CodigoModel codigoBean;
    private CodigoController codigoAnalyzer;
    private int mayorDigitoCodigo;

    public ControladorInitStartGUI() {
        codigoBean = new CodigoModel();
        codigoAnalyzer = new CodigoController();
        this.mayorDigitoCodigo = 0;
    }

    public boolean validateInputs(int code) {
        if (Validator.validateNumbers(code)) {
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

    public void inputDataCode(int codeNumber) {
        codigoBean.setCodigo(codeNumber);
        codigoAnalyzer.codeFragmenter(codigoBean);
        codigoBean.setCodigoDigitos(new int[codigoAnalyzer.getSumaDigitoscodigo()]);
        this.mayorDigitoCodigo = codigoAnalyzer.getMayorDigitoCodigo();
    }

    public int[] getDigitosIngresados() {
        return codigoBean.getCodigoDigitos();
    }

    public int getMayorDigitoCodigo() {
        return mayorDigitoCodigo;
    }
    
    public CodigoModel getCodigoBean(){
        return codigoBean;
    }
}
