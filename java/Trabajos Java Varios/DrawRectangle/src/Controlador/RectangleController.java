package Controlador;

import Modelo.Rectangle;
import java.util.Scanner;

public class RectangleController {

    private Rectangle rectangulo;
    private Painter painter;

    public RectangleController() {
        rectangulo = new Rectangle();
        painter=new Painter();
    }

    public void inputDataPainter() {
        int ancho = 0, alto=0;
        boolean inputFlag = true;
        Scanner scanData = new Scanner(System.in);

        do {
            inputFlag = false;
            try {

                System.out.println("Ingrese ancho de rectángulo: ");
                ancho = scanData.nextInt();
                if (ancho < 1) {
                    inputFlag = true;
                    throw new Exception("Ingreso Inválido");
                }
            } catch (Exception ex) {
                inputFlag = true;
                System.out.println("Ingreso Inválido");
                scanData = new Scanner(System.in);
            }

        } while (inputFlag == true);

        do {
            inputFlag = false;
            try {

                System.out.println("Ingrese alto de rectángulo: ");
                alto = scanData.nextInt();
                if (alto < 1) {
                    inputFlag = true;
                    throw new Exception("Ingreso Inválido");
                }
            } catch (Exception ex) {
                inputFlag = true;
                System.out.println("Ingreso Inválido");
                scanData = new Scanner(System.in);
            }

        } while (inputFlag == true);
        
        rectangulo.setWidth(ancho);
        rectangulo.setHeight(alto);
        painter.FigurePrinter(rectangulo);
    }
    
    
}
