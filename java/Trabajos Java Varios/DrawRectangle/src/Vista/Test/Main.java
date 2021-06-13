
package Vista.Test;

public class Main {

    public static void main(String[] args) {
        printRect(5,10,'x');
    }

    private static void printRect(int width,int height,char marker) {
        printHorizontal(width,marker);
        for(int j=0;j<height-2;j++) {
            printVertical(width,marker);
        }
        printHorizontal(width,marker);
    }

    private static void printVertical(int width, char marker) {
        System.out.print(marker);
        for (int j = 0; j < width-2; j++) {
            System.out.print(' ');
        }
        System.out.println(marker);
    }

    private static void printHorizontal(int width,char marker) {
        for (int j = 0; j < width-1; j++) {
            System.out.print(marker);
        }
        System.out.println(marker);
    }

}