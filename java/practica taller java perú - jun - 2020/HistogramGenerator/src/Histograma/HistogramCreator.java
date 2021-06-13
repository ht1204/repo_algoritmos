package Histograma;

import java.util.Scanner;

public class HistogramCreator {

    HistogramManager manager;

    public void createHistogram() {
        manager = new HistogramManager();
        System.out.println("Ingrese cantidad de alumnos:");
        int noOfStudents = 0;

        Scanner sc = new Scanner(System.in);
        do {
            noOfStudents = sc.nextInt();
            if (noOfStudents <= 0) {
                System.out.println("La cantidad de alumnos debe ser positiva.");
            }
        } while (noOfStudents <= 0);

        int elementosHistograma[] = new int[noOfStudents];

        System.out.println("Ingrese puntajes:");

        int puntaje = 0;
        for (int i = 0; i < noOfStudents; i++) {
            do {
                puntaje = sc.nextInt();
                if (puntaje < 1 || puntaje > 100) {
                    System.out.println("El puntaje ingresado debe ser de cero (0) a 100");
                }

            } while (puntaje < 1 || puntaje > 100);
            elementosHistograma[i] = puntaje;

        }
        manager.GenerarHistograma(elementosHistograma);
        System.out.println("______________________________");
        System.out.println("____Histograma Puntajes______");
        System.out.println("");
        manager.MostrarHistograma();
    }
}
