public class OrderFacade {
    private InventorySystem inventory = new InventorySystem();
    private ShippingSystem shipping = new ShippingSystem();
    private PaymentSystem payment = new PaymentSystem();

    public void placeOrder(String product, String user, double amount, String address) {
        inventory.checkStock(product);
        payment.processPayment(user, amount);
        shipping.shipProduct(product, address);
    }
}
