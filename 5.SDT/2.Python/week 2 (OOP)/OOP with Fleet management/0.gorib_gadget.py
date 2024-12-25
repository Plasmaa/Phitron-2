class Laptop:
    def __init__(self, brand, model, price, color , memory):
        self.brand = brand
        self.model = model
        self.price = price
        self.color = color
        self.memory = memory

    def run(self):
        print(f"{self.brand} {self.model} is running")

    def coding(self):
        print(f"{self.brand} {self.model} is coding")

class Phone:
    def __init__(self, brand, price , color, dual_sim) -> None:
        self.brand = brand
        self.price = price
        self.color = color
        self.dual_sim = dual_sim

    def call(self):
        print(f"{self.brand} {self.price} is calling")

    def sms(self):
        print(f"{self.brand} {self.price} is sending sms")


class Camera:
    def __init__(self, brand, price, color, pixel) -> None:
        self.brand = brand
        self.price = price
        self.color = color
        self.pixel = pixel

    def run(self):  
        print(f"{self.brand} {self.price} is running")

    def click(self):
        print(f"{self.brand} {self.price} is clicking")

    def change_lens(self):
        print(f"{self.brand} {self.price} is changing lens")

    def record(self):    
        print(f"{self.brand} {self.price} is recording")