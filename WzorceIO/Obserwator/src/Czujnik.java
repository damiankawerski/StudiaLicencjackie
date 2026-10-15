import java.util.ArrayList;

public class Czujnik {
    public double temperatura;
    public ArrayList<Obserwator> obserwatorzy;

    public Czujnik() {
        this.obserwatorzy = new ArrayList<>();
    }

    public void dodajObserwatora(Obserwator o) {
        this.obserwatorzy.add(o);
    }

    public void usunObserwatora(Obserwator o) {
        this.obserwatorzy.remove(o);
    }

    public void zmierzTemperatuure() {
        // Simulate temperature measurement
        this.temperatura = Math.random() * 100;

        // Notify observers
        for (Obserwator o : this.obserwatorzy) {
            o.wyslijTemperature(this);
        }
    }
}
