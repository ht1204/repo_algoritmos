package Adivinador;

import java.util.Random;
import java.util.Scanner;

public class Randomizer {

    private Random randomNumber;
    private int numeroAdivina = 0;
    int i = 0;

    private int randomCreator() {
        randomNumber = new Random();
        numeroAdivina = randomNumber.nextInt(100);
        return numeroAdivina;
    }

    public void adivinador() {
        String seguir = "si";
        int contadorIntentos = 0;
        int iteraciones = 0;
        int promedio = 0;
        System.out.println("Bienvenido a adivina el numero!!!");
        int apueste = 0;
        do {
            int adivina = this.randomCreator();
            Scanner sc = new Scanner(System.in);
            while (apueste != adivina) {
                System.out.println("¿Tu numero? ");
                do {
                    apueste = sc.nextInt();
                    if (apueste < 1 || apueste > 100) {
                        System.out.println("El número está entre 0 y 100");
                    }
                } while (apueste < 1 || apueste > 100);
                if (apueste > adivina) {
                    System.out.println("Mas bajo ");
                } else {
                    System.out.println("Mas alto ");
                }

                i++;
            }
            contadorIntentos += i;
            System.out.println("Adivinaste en  " + i + "intentos");
            System.out.println("");
            System.out.println("¿Quieres jugar de nuevo? (si para seguir) : ");
            Scanner scanString = new Scanner(System.in);
            seguir = scanString.nextLine();
            i = 0;
            iteraciones++;
        } while ("si".equals(seguir));

        promedio = contadorIntentos / iteraciones;
        System.out.println("Jugaste en promedio adivinaste en  " + promedio + "  intentos");
        System.out.println("Desempeño");
        if (promedio <= 2) {
            System.out.println("Excelente");
        } else if (promedio > 2 && promedio <= 4) {
            System.out.println("Bueno");
        } else if (promedio > 4 && promedio <= 6) {
            System.out.println("Regular");
        } else if (promedio > 6) {
            System.out.println("Malo :(");
        }
    }
}
