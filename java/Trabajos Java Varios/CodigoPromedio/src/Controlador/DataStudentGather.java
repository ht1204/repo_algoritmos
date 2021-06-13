package Controlador;

public class DataStudentGather {

    private int codeDigits[];
    private float promedioDigitosCodigo;

    public DataStudentGather() {
    }

    public void setCodeDigits(int[] codeDigits) {
        this.codeDigits = codeDigits;
    }

    public int[] getCodeDigits() {
        return codeDigits;
    }
    
    public float getPromedioDigitosCodigo() {
        return promedioDigitosCodigo;
    }

    private void setPromedioDigitosCodigo(float promedioDigitosCodigo) {
        this.promedioDigitosCodigo = promedioDigitosCodigo;
    }

    public void setCode(int code) {
        int digitCounter = 0;
        int number = code;
        int tempNumber = number;
        digitCounter = this.digitAmount(number);
        codeDigits = new int[digitCounter];
        while (tempNumber > 0) {
            codeDigits[digitCounter - 1] = tempNumber % 10;
            tempNumber /= 10;
            digitCounter--;
        }

        this.calculateAverage(codeDigits);
        this.setCodeDigits(codeDigits);
    }

    private int digitAmount(int number) {
        int count = 0;
        while (number != 0) {
            number /= 10;
            ++count;
        }
        return count;
    }

    private void calculateAverage(int codeDigits[]) {
        int sumaDigitos = 0;
        for (int i = 0; i < codeDigits.length; i++) {
            sumaDigitos += codeDigits[i];
        }

        float averageDigits = (float) sumaDigitos / codeDigits.length;
        this.setPromedioDigitosCodigo(averageDigits);
    }
    
    public int getLastDigitCode(){
        return this.getCodeDigits()[this.codeDigits.length-1];
    }
}
