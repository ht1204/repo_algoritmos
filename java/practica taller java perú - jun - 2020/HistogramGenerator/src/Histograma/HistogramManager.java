package Histograma;

public class HistogramManager {

    private int contadorPuntajes[];

    public HistogramManager() {
    }

    
    public void GenerarHistograma(int puntajes[]) {
        contadorPuntajes = new int[101];
        for (int i = 0; i < puntajes.length; i++) {
            int nota = puntajes[i];
            contadorPuntajes[nota]++;
        }
    }

    public void MostrarHistograma() {
        for (int i = 0; i < contadorPuntajes.length; i++) { // print star histogram
            if (contadorPuntajes[i] > 0) {
                System.out.print(i + ": ");
                for (int j = 0; j < contadorPuntajes[i]; j++) {
                    System.out.print("*");
                }
                System.out.println();
            }
        }
    }
}
