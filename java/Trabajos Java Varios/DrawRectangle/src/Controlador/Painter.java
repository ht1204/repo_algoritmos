package Controlador;

import Modelo.Rectangle;
import java.lang.System;
import static java.lang.System.out;

public class Painter {

    private static char marker = 'X';
    private static char emptySpace = ' ';

    public Painter() {
    }

    public void FigurePrinter(Rectangle rect) {
        this.printH_Axis(rect.getWidth(), marker);
        for (int i = 0; i < rect.getHeight()-2; i++) {
            this.printV_Axis(rect.getWidth(), marker);
        }
        this.printH_Axis(rect.getWidth(), marker);
    }

    private void printH_Axis(int ancho, char marker) {
        for (int i = 0; i < ancho-1; i++) {
            out.print(marker);
        }
        out.println(marker);         
    }

    private void printV_Axis(int ancho, char marker ) {
        out.print(marker);
        for (int i = 0; i < ancho-2; i++) {
            out.print(emptySpace);
        }
        out.println(marker);
    }
}
