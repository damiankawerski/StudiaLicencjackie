public class Alarm implements Obserwator {

    @Override
    public void wyslijTemperature(Czujnik czujnik) {
        if(czujnik.temperatura > 60) {
            alarm();
        }
    }

    public void alarm() {
        System.out.println("Alarm! Temperatura przekroczyła 60 stopni!");
    }
}
