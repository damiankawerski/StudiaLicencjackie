public abstract class Decoration implements BubbleTea{
    protected BubbleTea bubbleTea;

    public Decoration(BubbleTea bubbleTea){
        this.bubbleTea = bubbleTea;
    }
}
