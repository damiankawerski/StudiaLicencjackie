import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Czujnik czujnik = new Czujnik();
        Komputer komputer = new Komputer();
        Telefon telefon = new Telefon();
        Alarm alarm = new Alarm();
        czujnik.dodajObserwatora(komputer);
        czujnik.dodajObserwatora(telefon);
        czujnik.dodajObserwatora(alarm);

        Scanner scanner = new Scanner(System.in);
        System.out.println("Czy chcesz zmierzyć temperaturę? (tak/nie)");
        String odpowiedz = scanner.nextLine();
        while (odpowiedz.equalsIgnoreCase("tak")) {
            czujnik.zmierzTemperatuure();
            System.out.println("Czy chcesz zmierzyć temperaturę? (tak/nie)");
            odpowiedz = scanner.nextLine();
        }
    }
}