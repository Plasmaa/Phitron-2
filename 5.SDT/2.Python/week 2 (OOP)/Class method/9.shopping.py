class Shopping:
    def __init__(self, name):
        self.name = name
        self.cart = []

    def add_to_cart(self, item, price, quantity):
        product = {'item': item, 'price': price, 'quantity': quantity}
        self.cart.append(product)

    def remove_item(self, item):
        self.cart = [product for product in self.cart if product['item'] != item]

    def checkout(self, amount):
        total = 0
        for item in self.cart:
            total += item['price'] * item['quantity']
        print(f'Total price: {total}')
        if amount < total:
            print(f'Please provide {total - amount} more')
        else:
            extra = amount - total
            print(f'Here is your items and extra money: {extra}')
            self.cart.clear()


swapan = Shopping('Alan Swapon')
swapan.add_to_cart('alu', 50, 6)
swapan.add_to_cart('dim', 12, 24)
swapan.add_to_cart('rice', 50, 5)
swapan.checkout(600)
print(swapan.cart)

shop = Shopping('Kodom Ali')
shop.add_to_cart('Shirt', 500, 2)
shop.add_to_cart('Shoes', 1000, 1)
print(shop.cart)

shop.checkout(1600)
shop.checkout(600)

