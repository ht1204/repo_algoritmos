package Controlador;

import Modelo.CodigoModel;
import java.util.Scanner;

public class CodigoGestor {

    private CodigoModel codigo;
    private CodigoController codigoAnalyzer;
    private int digitosIngresados[];
    private int mayorDigitoCodigo;

    public CodigoGestor() {
        codigo = new CodigoModel();
        codigoAnalyzer = new CodigoController();
        this.mayorDigitoCodigo = 0;
    }

    public void InputData() {
        boolean inputFlag = true;
        int cod = 0;
        Scanner sc = new Scanner(System.in);
        do {
            inputFlag = false;
            try {

                System.out.println("Ingrese código de estudiante : ");
                cod = sc.nextInt();
                if (cod < 1 || cod > 1000000) {
                    inputFlag = true;
                    throw new Exception("Ingreso Inválido");
                }
            } catch (Exception ex) {
                inputFlag = true;
                System.out.println("Ingreso Inválido");
                sc = new Scanner(System.in);
            }

        } while (inputFlag == true);
        codigo.setCodigo(cod);
        codigoAnalyzer.codeFragmenter(codigo);
        this.digitosIngresados = new int[codigoAnalyzer.getSumaDigitoscodigo()];
        System.out.println("Suma Dígitos Código Ingresado : " + this.digitosIngresados.length);
        this.mayorDigitoCodigo = codigoAnalyzer.getMayorDigitoCodigo();
        this.inputDataDigits(this.digitosIngresados);
    }

    private void inputDataDigits(int digitosIngresados[]) {
        boolean inputFlag = true;
        Scanner sc = new Scanner(System.in);
        int inputUserDigit = 0;
        for (int i = 0; i < digitosIngresados.length; i++) {
            if (i % 2 == 0) {
                digitosIngresados[i] = this.mayorDigitoCodigo;
            } else {
                do {
                    inputFlag = false;
                    try {

                        do {
                            System.out.println("\n\tPosición; " + (i + 1) + "\tIngrese dígito : ");
                            inputUserDigit = sc.nextInt();
                        } while (inputUserDigit < -10 || inputUserDigit > 10);

                    } catch (Exception ex) {
                        inputFlag = true;
                        System.out.println("Ingreso Inválido");
                        sc = new Scanner(System.in);
                    }

                } while (inputFlag == true);

                digitosIngresados[i] = inputUserDigit;
            }
        }
        this.showResults(digitosIngresados);
    }

    public void showResults(int digitosIngresados[]) {

        System.out.println("Datos ingresados-Casillas Mayor Número");

        for (int i = 0; i < digitosIngresados.length; i++) {
            if (i % 2 == 0) {
                System.out.println("\n\tPosición; " + (i + 1) + "\tMayor número Código : " + digitosIngresados[i]);
            } else {
                System.out.println("\n\tPosición; " + (i + 1) + "\tNúmero ingresado : " + digitosIngresados[i]);
            }

        }
    }

}
