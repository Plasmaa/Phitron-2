class Shopping:
    cart = []
    origin = 'china'
    def __init__(self, name, location) -> None:
        self.name = name  # instance attribute
        self.location = location

    def purchase(self, item, price, amount):
        remaining = amount - price
        print(f'buying: {item} for price: {price} and remaining: {remaining}')
        if remaining > 0:
            self.cart.append(item)
        else:
            print('please provide more')

    def check_out(self, amount):
        print(f'{self.name} is buying: {self.cart} for price: {amount}')
        self.cart.clear()

    @staticmethod
    def multiply(a, b):
        result = a*b
        print(result)

    @classmethod
    def hudai_dekhi(cls, item):
        print(f'{cls.origin} made {item}')
        print('hudai dekhi kintu kinmu just ac er hawa khaite aschi', item)


basundara = Shopping('basu en dhara', 'not popular location')
basundara.purchase('lungi', 500, 1000)
basundara.check_out(1000)

Shopping.hudai_dekhi('Lungi')
print(basundara.cart)

Shopping.multiply(4,6)

