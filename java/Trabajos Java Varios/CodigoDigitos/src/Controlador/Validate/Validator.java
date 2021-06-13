package Controlador.Validate;

public class Validator {

    public static String regexOnlyLetters = "^[a-zA-Z]*$";
    public static String regexOnlyNumbers = "[0-9]+"; //Considerate "\\d+";
    public static String emptySpace = "";

    public static boolean validateNames(String inputName) {
        return (inputName == null)
                || (inputName.equals(Validator.emptySpace))
                || (!inputName.matches(Validator.regexOnlyLetters));
    }

    public static boolean validateNumbers(int number) {
        String inputNumber = Integer.toString(number);
        return (inputNumber == null)
                || (inputNumber.equals(Validator.emptySpace))
                || (!inputNumber.matches(Validator.regexOnlyNumbers));
    }
}
