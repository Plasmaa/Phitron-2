# poly --> many
# morph --> form

class Animal:
    def __init__(self, name):
        self.name = name

    def make_sound(self):
        print('animal making some sound')

    
class Cat(Animal):

    def __init__(self, name) -> None:
        super().__init__(name)
    def make_sound(self):
        print('meow meow')
don = Cat('Real Don')
don.make_sound()


class Dog(Animal):

    def __init__(self, name) -> None:
        super().__init__(name)
    def make_sound(self):
        print('woof woof')

shephard = Dog('shephard')
shephard.make_sound()

class Goat(Animal):
    def __init__(self, name) -> None:
        super().__init__(name)
    def make_sound(self):
        print('maa maa')

mess = Goat('chagol')
mess.make_sound()

less = Goat('gora gori')

animals = [don, shephard, mess, less]
for animal in animals:
    animal.make_sound()


