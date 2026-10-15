public class Telefon implements Obserwator{

    @Override
    public void wyslijTemperature(Czujnik czujnik) {
        wyswietlTemperature(czujnik);
    }

    public void wyswietlTemperature(Czujnik czujnik) {
        System.out.println("Temperatura z telefonu: " + czujnik.temperatura);
    }
}
