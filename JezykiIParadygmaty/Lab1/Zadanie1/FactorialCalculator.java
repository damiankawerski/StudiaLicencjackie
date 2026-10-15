import java.util.Scanner;

public class FactorialCalculator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Podaj liczbę: ");
        int number = scanner.nextInt();
        
        if (number < 0) {
            System.out.println("Silnia nie jest zdefiniowana dla liczb ujemnych.");
        } else {
            long factorial = calculateFactorial(number);
            System.out.println("Silnia liczby " + number + " to: " + factorial);
        }
        
        scanner.close();
    }
    
    public static long calculateFactorial(int n) {
        long result = 1;
        for (int i = 2; i <= n; i++) {
            result *= i;
        }
        return result;
    }
}

