from math import pi

class Shape:
    def __init__(self, name) -> None:
        self.name = name


class Reactangle(Shape):
    def __init__(self, name, length, width) -> None:
        super().__init__(name)
        self.length = length
        self.width = width

    def area(self):
        return self.length * self.width
    
class circle(Shape):
    def __init__(self, name, radius) -> None:
        super().__init__(name)
        self.radius = radius

    def area(self):
        return pi * self.radius*self.radius
    
    
