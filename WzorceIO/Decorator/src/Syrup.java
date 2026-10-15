public class Syrup extends Decoration{
    public Syrup(BubbleTea tea){
        super(tea);
    }

    public String getDesc() {
        return bubbleTea.getDesc() + " Syrup";
    }
    public double getPrice() {
        return bubbleTea.getPrice() + 1.0;
    }
}
