# read only --> you can not set thevalue. value can not be changed
# getter -- > get a value of property. Most of the time you will get the 
# value of privaet attribute

# setter --> set the value of property. Most of the time you will set the value of private property

class User:
    def __init__(self, name, age, money):
        self.name = name
        self._age = age
        self.__money = money    # private variable

    # getter without setting any attribute
    @property
    def age(self):
        return self._age
    

    @property
    def salary(self):
        return self.__money
    
    #setter
    @salary.setter
    def salary(self, value):
        if value < 0:
            return 'salary can not be negative'
        self.__money += value

samsu = User('Kopa', 21, 12000)

# print(samsu.__money) # private variable
print(samsu.age)
print(samsu.salary)

samsu.salary = 4500
print(samsu.salary)



