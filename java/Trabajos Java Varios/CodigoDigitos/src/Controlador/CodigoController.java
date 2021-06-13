package Controlador;

import Modelo.CodigoModel;

public class CodigoController {

    private final CodigoModel codigoBean;
    private int sumaDigitoscodigo = 0;
    private int mayorDigitoCodigo = 0;

    public CodigoController() {
        codigoBean = new CodigoModel();
    }

    public void codeFragmenter(final CodigoModel cod) {
        int digitCounter = 0;
        int number = cod.getCodigo();
        int tempNumber = number;
        digitCounter = this.digitAmount(number);
        cod.setCodigoDigitos(new int[digitCounter]);
        while (tempNumber > 0) {
            cod.setDigitos(digitCounter - 1, tempNumber % 10);
            tempNumber /= 10;
            digitCounter--;
        }
        this.sumaResultadosDigitoCodigo(cod.getCodigoDigitos());
        this.mayorDigitoCodigo = this.mayorDigitoCodigo(cod.getCodigoDigitos());

    }

    private int digitAmount(int number) {
        int count = 0;
        while (number != 0) {
            number /= 10;
            ++count;
        }
        return count;
    }

    private int sumaResultadosDigitoCodigo(int codigoDigitos[]) {
        this.sumaDigitoscodigo = 0;
        for (int i = 0; i < codigoDigitos.length; i++) {
            this.sumaDigitoscodigo += codigoDigitos[i];
        }

        return sumaDigitoscodigo;
    }

    public int getSumaDigitoscodigo() {
        return sumaDigitoscodigo;
    }

    private int mayorDigitoCodigo(int codigoDigitos[]) {
        int mayorDigito = codigoDigitos[0];
        for (int i = 1; i < codigoDigitos.length; i++) {
            if (mayorDigito < codigoDigitos[i]) {
                mayorDigito = codigoDigitos[i];
            }
        }

        return mayorDigito;
    }

    public int getMayorDigitoCodigo() {
        return mayorDigitoCodigo;
    }

}
