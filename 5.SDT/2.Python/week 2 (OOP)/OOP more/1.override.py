class Person:
    def __init__(self, name, age, height, weight) -> None:
        self.name = name
        self.age = age
        self.height = height
        self.weight = weight
    
    def eat(self):
        print(f'{self.name} is eating')

    def exercise(self):
        raise NotImplementedError

class Cricketer(Person):
    def __init__(self, name, age, height, weight, team) -> None:
        self.team = team
        super().__init__(name, age, height, weight)

    # override
    def eat(self):
        print(f'{self.name} is eating vegetable, not meat, salad')

    def exercise(self):
        print('gym e poisha diya hai')

    def __add__(self, other):
        return self.age + other.age
    def __mul__(self, other):
        return self.age * other.age
    
    def __len__(self):
        return self.height
    
    def __gt__(self, other):
        return self.age > other.age

sakib = Cricketer('sakib', 38, 68, 91, 'BD')
mushi = Cricketer('mushi', 36, 50, 97, 'BD')
sakib.eat()
sakib.exercise()


print([12,98] + [1, 2, 3, 4, 5])
print(sakib + mushi)
print(sakib * mushi)
print('height of sakibal is:', len(sakib))
print(sakib > mushi)


