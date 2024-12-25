from datetime import datetime
from vehicle import Car, Bike

class RideSharing:
    def __init__(self, company_name) -> None:
        self.company_name = company_name
        self.riders = []
        self.drivers = []
        self.rides = []

    def add_rider(self, rider):
        self.riders.append(rider)

    def add_driver(self, driver):
        self.drivers.append(driver)

    def __str__(self):
        return f"Company Name {self.company_name} with riders: {len(self.riders)} and drivers: {len(self.drivers)}"


class Ride:
    def __init__(self, start_location, end_location, vehicle) -> None:
        self.start_location = start_location
        self.end_location = end_location
        self.vehicle = vehicle
        self.driver = None
        self.rider = None
        self.start_time = None
        self.end_time = None
        self.estimated_fare = self.calculate_fare()

    def set_driver(self, driver):
        self.driver = driver

    def start_ride(self):
        self.start_time = datetime.now()

    def end_ride(self):
        self.end_time = datetime.now()
        self.rider.wallet -= self.estimated_fare
        self.driver.wallet += self.estimated_fare

    def calculate_fare(self,distance,vehicle):
        fare_per_km = {
            'car': 30,
            'bike': 20,
            'cng': 25
        }
        distance = 10  # This should be calculated based on locations
        return distance * fare_per_km.get(self.vehicle.vehicle_type, 0)

    def __repr__(self):
        return f"Ride details. Start: {self.start_location}, End: {self.end_location}, Fare: {self.estimated_fare}"


class RideRequest:
    def __init__(self, rider, end_location) -> None:
        self.rider = rider
        self.end_location = end_location


class RideMatching:
    def __init__(self, available_drivers) -> None:
        self.available_drivers = available_drivers

    def find_driver(self, ride_request, vehicle_type):
        if self.available_drivers:
            print("Looking for drivers.....")
            driver = self.available_drivers.pop(0)
            if vehicle_type == 'car':
                vehicle = Car('car', "ABC456", 30)
            elif vehicle_type == 'bike':
                vehicle = Bike("bike", "1234BH", 50)
            else:
                return None

            ride = Ride(ride_request.rider.current_location,
                        ride_request.end_location, vehicle)
            ride.set_driver(driver)
            driver.accept_ride(ride)
            return ride
        return None
