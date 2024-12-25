"""
1. calculator class to add, deduct, multiply, divide
2. Pen class. create three object with different instance attribute
3. Exam attend_to_exam get_marks

"""

class Calculator:
    brand = 'Casio MS990'

    def add(self, num1, num2):
        return num1 + num2
    
    def deduct(self, num1, num2):
        return num1 - num2
    
    def multiply(self, num1, num2):    
        return num1 * num2    
    def divide(self, num1, num2):    
        return num1 / num2
    

class Pen:
    def __init__(self, color, brand, price):
        self.color = color
        self.brand = brand
        self.price = price
    def write(self, text):
        print(f"Writing {text} on pen")

class Exam:
    def __init__(self, student_name, exam_name, total_marks):
        self.student_name = student_name
        self.exam_name = exam_name
        self.total_marks = total_marks
        self.attended = False
        self.marks_obtained = 0

    def attend_to_exam(self, marks):
        if not self.attended:
            self.attended = True
            self.marks_obtained = marks
            return marks
        else:
            return "Already attended"

    def get_percentage(self):
        if self.attended:
            return (self.marks_obtained / self.total_marks) * 100
        else:
            return "Not attended yet"



