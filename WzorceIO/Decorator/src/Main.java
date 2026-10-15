public class Main {
    public static void main(String[] args) {
        BubbleTea order = new BlackTea();

        order = new Tapioca(order);
        order = new Milk(order);
        order = new Syrup(order);

        System.out.println(order.getDesc());
        System.out.println(order.getPrice());
    }
}