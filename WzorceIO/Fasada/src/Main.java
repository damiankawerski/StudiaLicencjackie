class Main {
    public static void main(String[] args) {
        OrderFacade facade = new OrderFacade();

        facade.placeOrder("Pizza", "Damian", 45, "ul. Imperator Seneszyn 44");
    }
}