package Vista.Test;

import java.util.Scanner;

public class RectangleTypes {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter width: ");
        int w = input.nextInt();
        System.out.print("Enter height: ");
        int h = input.nextInt();
        System.out.println("A filled rectangle:");
        printFilledRectangle("x", w, h);
        System.out.println("An empty rectangle:");
        printEmptyRectangle("x", w, h);
    }

    private static void printFilledRectangle(String character, int width, int height) {
        for (int i = 1; i <= height; i++) {
            for (int j = 1; j <= width; j++) {
                System.out.print(character);
            }
            System.out.println();
        }
    }

    private static void printEmptyRectangle(String character, int width, int height) {
        for (int j = 1; j <= width; j++) {
            System.out.print(character);
        }
        System.out.println();
        for (int i = 1; i <= height - 2; i++) {
            System.out.print(character);
            for (int j = 1; j <= width - 2; j++) {
                System.out.print(" ");
            }
            System.out.println(character);
        }
        for (int j = 1; j <= width; j++) {
            System.out.print(character);
        }
    }
}
