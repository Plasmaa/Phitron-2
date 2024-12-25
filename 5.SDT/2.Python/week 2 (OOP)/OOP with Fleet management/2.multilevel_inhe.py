class Vehicle:
    def __init__(self, name, price, make, model, year):
        self.make = make
        self.model = model
        self.year = year
        self.name = name
        self.price = price

    def move(self):
        print(f"{self.name} is moving")

    def __repr__(self):
        return f"Vehicle: {self.name}, Make: {self.make}, Model: {self.model}, Year: {self.year}, Price: {self.price}"


class Bus(Vehicle):
    def __init__(self, name, price, make, model, year, seat):
        super().__init__(name, price, make, model, year)
        self.seat = seat    


    def move(self):        
        print(f"{self.name} is moving")

    def __repr__(self):
        return super().__repr__() + f", Seat: {self.seat}"


class Truck(Vehicle):
    def __init__(self, name, price, make, model, year, capacity):
        super().__init__(name, price, make, model, year)
        self.capacity = capacity


    def move(self):        
        print(f"{self.name} is moving")




class Pickup(Truck):
    def __init__(self, name, price, make, model, year, capacity):
        # adding capacity to the super init
        super().__init__(name, price, make, model, year, capacity)


    def move(self):
        print(f"{self.name} is moving")


class ACbus(Bus):    
    def __init__(self, name, price, make, model, year, seat, temperature):
        super().__init__(name, price, make, model, year, seat)
        self.temperature = temperature


    def move(self):
        print(f"{self.name} is moving")

    def __repr__(self) -> str:
        return super().__repr__() + f", Temperature: {self.temperature}"

    
green_line = ACbus('green', 5000000, 22, 16, 2020, 50, 22)
print(green_line)

tata = Bus('Tata', 3000000, 'Tata', 'Tata', 2020, 30)
print(tata)

toyota = Pickup('Toyota', 5000000, 'Toyota', 'Toyota', 2020, 5000)
print(toyota)

