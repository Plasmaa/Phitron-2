from abc import ABC, abstractmethod

class Animal(ABC):
    @abstractmethod #enforce the child class to implement this method
    def __init__(self, name):
        self.name = name
    
    def eat(self):
        print(f'{self.name} is eating')

    @abstractmethod
    def move(self):
        print(f'{self.name} is moving')

class Monkey(Animal):
    def __init__(self, name):
        super().__init__(name)

    def eat(self):
        print('Eating banana')

    def move(self):
        print('Climbing tree')

    

layka = Monkey('lucky')
layka.eat()    

