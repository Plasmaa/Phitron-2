from abc import ABC

class Vehicle(ABC):
    speed = {
    'car': 50, 
    'bike': 60, 
    'cng': 15
    }
    def __init__(self, vehicle_type,license_plate, rate) -> None:
        self.licanse_plate = license_plate
        self.vehicle_type = vehicle_type
        self.rate = rate

class Car(Vehicle):
    def __init__(self, vehicle_type,license_plate, rate) -> None:
        super().__init__(vehicle_type,license_plate, rate)

class Bike(Vehicle):
    def __init__(self, vehicle_type,license_plate, rate) -> None:
        super().__init__(vehicle_type,license_plate, rate)