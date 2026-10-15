public class Milk extends Decoration{
    public Milk(BubbleTea tea){
        super(tea);
    }

    public String getDesc() {
        return bubbleTea.getDesc() + " Milk";
    }
    public double getPrice() {
        return bubbleTea.getPrice() + 4.0;
    }

}
