import java.util.Observer;

public class Komputer implements Obserwator {
    @Override
    public void wyslijTemperature(Czujnik czujnik) {
        wyswietlTemperature(czujnik);
    }

    public void wyswietlTemperature(Czujnik czujnik) {
        System.out.println("Temperatura z komputera: " + czujnik.temperatura);
    }
}
