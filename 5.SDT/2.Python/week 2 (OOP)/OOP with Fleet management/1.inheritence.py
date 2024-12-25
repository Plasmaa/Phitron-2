# base class, parent class, common attribute + functionality class
# derived class, child class, uncommon attribute + functionality class

class Gadget:
    def __init__(self, brand, model, price, color , memory):
        self.brand = brand  
        self.model = model
        self.price = price  
        self.color = color
        self.memory = memory
    
    def run(self):
        print(f"{self.brand} {self.model} is running")



class Laptop(Gadget):
    def __init__(self , memory):
        super().__init__(self, memory)

    def run(self):
        print(f"{self.brand} {self.model} is running")

    def coding(self):
        print(f"{self.brand} {self.model} is coding")

class Phone(Gadget):
    def __init__(self, brand, price , color, dual_sim) -> None:
        super().__init__(self, brand, price, color, dual_sim)
        self.dual_sim = dual_sim

    def call(self):
        print(f"{self.brand} {self.price} is calling")

    def sms(self):
        print(f"{self.brand} {self.price} is sending sms")
    
    def __repr__(self) -> str:
        return f"Phone: {self.brand}, price: {self.price}, color: {self.color}, dual_sim: {self.dual_sim}"


class Camera(Gadget):
    def __init__(self, brand, price, color, pixel) -> None:
        super().__init__(self, brand, price, color, pixel)
        self.pixel = pixel

    def run(self):  
        print(f"{self.brand} {self.price} is running")

    def click(self):
        print(f"{self.brand} {self.price} is clicking")

    def change_lens(self):
        print(f"{self.brand} {self.price} is changing lens")

    def record(self):    
        print(f"{self.brand} {self.price} is recording")


# inheritance
my_phone = Phone("Nokia", 10000, "black", True)
print(my_phone.brand)
