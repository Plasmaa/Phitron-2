from ride import Ride, RideRequest, RideMatching, RideSharing
from user import Rider, Driver
from vehicle import Car, Bike

niye_jao = RideSharing("Niye Jao")
rahim = Rider("Rahim Uddin", "rahim@gmail.com", 1234,"Kuril", 1200)
niye_jao.add_rider(rahim)
print(niye_jao)

kolimuddin = Driver("Kolim Uddin", "kolim@gmail.com", 1256, "Uttara")
niye_jao.add_driver(kolimuddin)
print(niye_jao)
rahim.request_ride(niye_jao, "Uttara", "car")
print(niye_jao)
rahim.show_current_ride()
kolimuddin.reach_destination(rahim.current_ride)
print(niye_jao)