class Family:
    def __init__(self, address) -> None:
        self.address = address
    
class School(Family):
    def __init__(self, id, level, address) -> None:
        super().__init__(address)
        self.id = id
        self.level = level

class Sports:
    def __init__(self, game) -> None:
        self.game = game

class Student(School, Sports):
    def __init__(self, name, id, level, address, game) -> None:
        School.__init__(self, id, level, address)
        Sports.__init__(self, game)
        self.name = name


student = Student("Sakib", 1, "A", "Dhaka", "Cricket")
print(student.name, student.id, student.level, student.address, student.game)

