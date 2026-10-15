public class Tapioca extends Decoration{
    public Tapioca(BubbleTea tea){
        super(tea);
    }

    public String getDesc() {
        return bubbleTea.getDesc() + " Tapioca";
    }
    public double getPrice() {
        return bubbleTea.getPrice() + 3.0;
    }
}
